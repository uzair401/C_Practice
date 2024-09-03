#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declaring variable
    int height = 0;
    //checking conditions with a forever loop
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //executing a for loop
    for (int i = 0; i < height; i++)
    {
        // Printing spaces for the first pyramid
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Printing # symbols for the first pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Printing spaces between the pyramids
        printf("  ");

        // Printing # symbols for the second pyramid
        for (int q = 0; q < i + 1; q++)
        {
            printf("#");
        }

        // Moving control to a new line
        printf("\n");
    }
}