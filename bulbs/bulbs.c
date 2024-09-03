#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
//Functions prototypes
void print_bulb(char bit);
void text_to_binary(string x);
void reverse_array(char* input, char* output, int size);

//array prototypes
char binary_char[1000];
char reversed_binary_char[1000];
int main(void)
{   // get input from users
    string x = get_string("Message:");

    // to calculate the length of the input
    int length = strlen(x);

    //text to ASCII Values and then Binary
    text_to_binary(x);

    // reversing the text array after each byte
    reverse_array(binary_char, reversed_binary_char, length * BITS_IN_BYTE);

    //printing the light bulbs
    int counter = 0;
    for (int i = 0; i < length * BITS_IN_BYTE;  i++)
    {
        print_bulb(reversed_binary_char[i]);
        counter++;
        if (counter == BITS_IN_BYTE)
        {
            printf("\n");
            counter = 0;
        }
    }
    printf("\n");

}

// Converting the text value to Binary
void text_to_binary(string x)
{
    int binary_index = 0;
    for (int i = 0, length = strlen(x); i < length; i++)
    {
        int ascii = (int)x[i];
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (ascii % 2 == 0)
            {
                binary_char[binary_index] = '0';
            }
            else
            {
                binary_char[binary_index] = '1';
            }
            ascii /= 2;
            binary_index++;
        }
    }
}

void print_bulb(char bit)
{
    if (bit == '0')
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == '1')
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

// special function to break the charachters in the binary_array
//bytes and then store them in revrse order to get the expected output
void reverse_array(char* input, char* output, int size) {
    for (int i = 0; i < size; i += 8) {
        int start = i;
        int end = i + 8 - 1;
        for (int j = end; j >= start; j--) {
            output[i + (end - j)] = input[j];
        }
    }
}