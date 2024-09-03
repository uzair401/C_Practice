#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x, y;
    do
    {
        x = get_int("Start Size: ");
    }
    while (x < 9);

    do
    {
        y = get_int("End Size: ");
    }
    while (y < x);

    int p = x ;
    int years = 0;

    for (int i = 0 ; p < y; i++)
    {
        p = p + (p / 3) - (p / 4);
        years++;
    }

    printf("Years: %i\n", years);
}
