// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

void replace(char text[]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string text = argv[1];
        replace(text);
    }
    else
    {
        printf("Error");
        return 1;
    }

}

void replace(string text)
{
    int n = strlen(text);

    for (int i = 0 ; i < n ; i++)
    {
        switch (text[i])
        {
            case 'a':
                printf("6");
                break;
            case 'e':
                printf("3");
                break;
            case 'i':
                printf("1");
                break;
            case 'o':
                printf("0");
                break;
            default:
                printf("%c",text[i]);
         }
    }
    printf("\n");
    return;
}
