#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//prototypes
void rotate(string x , int length, int key);
int main(int argc, string argv[])
{
    // check if the command-line input is valid
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i])) {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
        int key = atoi(argv[1]) % 26;


    // get plaintext
    string text = get_string("plaintext: ");
    int length= strlen(text);
    int text_len = strlen(text);
    rotate(text,length,key);
    printf("ciphertext: %s\n", text);
    return 0;
}

void rotate(string x , int length, int key) {
      // convert plaintext to ciphertext
    for (int i = 0; i < length; i++) {
        if (isalpha(x[i])) {
            if (isupper(x[i])) {
                x[i] = (x[i] - 'A' + key) % 26 + 'A';
            } else {
                x[i] = (x[i] - 'a' + key) % 26 + 'a';
            }
        }
    }
}
