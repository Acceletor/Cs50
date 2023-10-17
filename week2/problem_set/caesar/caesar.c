#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>//atoi()
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc > 2 || argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int shift_num = atoi(argv[1]);
    printf("%i\n", shift_num);

    string text = get_string("plaintext: ");
    string cipher = text;
    int length_text = strlen(text);

    for (int i = 0; i < length_text; i++)
    {
        if (islower(text[i]))
        {
            int curr = text[i] - 97;
            curr = (curr + shift_num) % 26 + 97;
            cipher[i] = curr;
        }
        else if (isupper(text[i]))
        {
            int curr = text[i] - 65;
            curr = (curr + shift_num) % 26 + 65;
            cipher[i] = curr;
        }
    }
    printf("ciphertext: %s\n", cipher);

}