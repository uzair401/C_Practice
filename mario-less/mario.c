#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // variable declaration
    int x;
    // do-while loop to show output and then check for condition
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);
    // loop to check the condition
    for (int i = 0; i < x; i++)
    {
        //inner loopcd  generating space
        for (int j = 0; j < x - i - 1; j++)
        {
            printf(" ");
        }
        //another inner loop to display '#'
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        //jump to new line
        printf("\n");
    }
}
