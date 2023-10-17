#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float start_size;
    do
    {
        // TODO: Prompt for start size
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    float end_size;
    do
    {
        end_size = get_int("End size: ");

    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    while (start_size < end_size)
    {
        start_size += (int)start_size / 3 - (int)start_size / 4;

        year ++;
    }

    printf("Years: %i", year);

}