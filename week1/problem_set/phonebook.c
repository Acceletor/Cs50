#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? ");
    int age = get_int("what's your age? ");
    string phonenumber = get_string("What's your phone number? ");

    printf("Your name is %s. Age is %i. Your phone number is %s.\n ",name, age, phonenumber);
}