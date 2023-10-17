#include <stdbool.h>
#include <stdint.h> // to use uint8_t
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 // from note

int main(int argc, char *argv[])
{
    // check correct usuage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open the forensic image file specific
    char *file = argv[1];
    FILE *raw_file = fopen(file, "r");
    if (raw_file == NULL)
    {
        printf("Counld open %s file.\n", file);
        return 1;
    }

    // initialize values
    bool found_jpeg = false;    // to flag that the jpeg found
    int jpeg_count = 0;         // count how many jpeg is found
    uint8_t buffer[BLOCK_SIZE]; // buffer to store a block of data from image
    char jpeg_name[8];          // array to store a filename of current jpeg "000.jpg"
    FILE *outprt = NULL;        // pointer that point to the current img file

    // read the image file block by block
    while (fread(buffer, BLOCK_SIZE, 1, raw_file) == 1)
    {
        // check the the block mark as a new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the prevoius jpeg, if one was open
            if (found_jpeg)
            {
                fclose(outprt);
            }
            else
            {
                found_jpeg = true;
            }
            // open new jpeg file
            sprintf(jpeg_name, "%03d.jpg", jpeg_count); // Generate file name base on jpeg_count variable
            outprt = fopen(jpeg_name, "w");             // open new Jpeg file with new generated name
            if (outprt == NULL)
            {
                fclose(raw_file);
                printf("JPEG file can not be create %s\n", jpeg_name);
                return 3;
            }
            // increase counter for each jpeg that we found
            jpeg_count++;
        }
        // write current block to the current file Jpeg, if one is open
        if (found_jpeg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outprt);
        }
    }
    // Close the forensic file and last file, if one was open
    fclose(raw_file);
    if (found_jpeg)
    {
        fclose(outprt);
    }
    return 0;
}