// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int up_count, low_count, sym_count, num_count = 0;
    int n = strlen(password);
    for (int i = 0; i < n; i++)
    {
        if (password[i] >= '!' && password[i] <= '/')
        {
            sym_count = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            num_count = 1;
        }
        else if (islower(password[i]))
        {
            low_count = 1;
        }
        else if (isupper(password[i]))
        {
            up_count = 1;
        }

    }

    if (sym_count == 1 && num_count == 1 && low_count == 1 && up_count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }


}
