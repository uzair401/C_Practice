#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num = 0 ;
    do
    {
        num = get_int("Height: ");
    }
    while (num<1 || num>8);

    for(int i = 0; i<num; i++)
    {
        for (int j=0; j < num - i - 1;j++)
        {
            printf(" ");
        }
        for(int k =0; k<i+1;k++)
        {
            printf("#");
        }
        printf("  ");
            for(int q = 0; q<i+1;q++)
            {
                printf("#");
            }
        printf("\n");
    }
}