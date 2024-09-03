#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int num = 8;
    for(int i=0; i<num;i++)
    {
        for (int j = 0; j<i;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}