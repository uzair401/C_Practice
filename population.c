#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = 0;
    int end = 0;
    int years = 0;
    do
    {
        number = get_int("Start Size: ");
    }
        while(number<9);
    do
    {
        end = get_int("End Size: ");
    }
        while(end<number);
        for (int i = 0; number < end; i++)
        {
            number = number+(number/3)-(number/4);
            years++;
        }
            printf("Years: %i\n", years);
}
