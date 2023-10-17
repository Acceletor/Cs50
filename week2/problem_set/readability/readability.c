#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void count_words(string text);

int main(void)
{
    string text = get_string("Text:");
    count_words(text);
}

void count_words(string text)
{
    int length = strlen(text);
    int letter = 0, word = 0, sentence = 0;
    for (int i = 0; i < length; i++)
    {

        char upper_char = toupper(text[i]);
        if (upper_char <= 'Z' && upper_char >= 'A')
        {
            letter++;
        }
        else if (text[i] == ' ')
        {
            word++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }

    }
    word++;
    // printf("%i letters\n", letter);
    // printf("%i words\n", word);
    // printf("%i sentences\n", sentence);
    double L = (float)letter / word * 100;
    // printf("%f\n", L);
    double S = (float)sentence / word * 100;
    // printf("%f\n", S);
    double index = (0.0588 * L) - (0.296 * S) - 15.8;
    int result = (int)round(index);

    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }

}