#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // variables section

        long product1 = 0;
        long product2 = 0;
        long total = 0;
        long card = get_long("Number: ");
        long temp = card;

    //Length Calculation

        long length  = length=(card==0)?1:log10(card)+1;
    long templength = length;
    templength = (length>16) ? 0 : length;


   //Luhn's Algorithm

        if (13 <= length && 16>= length){
        for(int i = 0; i<templength; i++)
        {
            // validating 2nd last digit values
            long num = (((card / 10)%10)*2);
            if(num>9) {
                long p = ((num / 10)%10);
                long q = (num % 10);
                num = p+q ;
            }
            product1 += num;

            product2 += (card % 10);
            // last and 2nd last digit deletion
            card = card /100 ;
            // limiting loop
            templength = templength - 1 ;
        }
        }
        total = product1+product2;

    //validation section
    long n = temp;
    while(n>100){
        n /= 10;
    }

    if((total % 10) == 0 && length >= 13 && length <=16 ) {
        if ((n/10) == 3 && ((n%10)==4 || (n%10) == 7)) {
            printf("AMEX\n");
        }
         else if ((n/10) == 4 && ((n%10)==0 || (n%10)==1 || (n%10)==2)) {
            printf("VISA\n");
        }
        else if ((n/10) == 5 && (((n%10)==1 || (n%10)==2 || (n%10)==3 || (n%10)==4 || (n%10)==5))) {
            printf("MASTERCARD\n");
        }
        else {
            printf("INVALID\n");
        }}
        else {
            printf("INVALID\n");
    }}




