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
        for (int p=0; p < num - i - 1;p++)
        {
            printf(" ");
        }
        for(int j =0; j<i+1;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}