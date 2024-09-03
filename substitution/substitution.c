#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool check_repeatition(string x);
void loc_calc(string x, string key);
string c_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string l_alpha = "abcdefghijklmnopqrstuvwxyz";
int main(int argc, string argv[])

{
    if (argc !=2) {
        printf("Usage: ./substitution key \n");
        return 1;
        }
    // check if the command-line input is valid
    for (int i = 0; i < strlen(argv[1]); i++) {
     if (!isalpha(argv[1][i])){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (ispunct(argv[1][i])){
        printf("Usage: ./substitution key\n");
        return 1;
    }}
    int length = strlen(argv[1]);

     if (length != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
        }
        else if (check_repeatition(argv[1])){
            printf("No charachters repeatition is allowed\n");
            return 1;
        }
        string key ;
        key = argv[1];
        //get text section
        string text = get_string("plaintext: ");
        int txt_length= strlen(text);
       loc_calc(text,key);
       string output = text;
        printf("ciphertext: %s\n",output);

        return 0 ;
    }

void loc_calc(string x ,string key) {
    for (int p = 0; p <strlen(x); p++){ {
        if (isalpha(x[p])) {
            if (isupper(x[p])) {
                for (int q = 0; q<strlen(c_alpha); q++) {
                    if (x[p] == c_alpha[q]){
                        x[p] = toupper(key[q]);
                        break;
                    }
                }
            }

            else if (islower(x[p])){
                for (int q = 0; q<strlen(l_alpha); q++) {
                    if (x[p] == l_alpha[q]){
                        x[p] = tolower(key[q]);
                        break;
                    }
            }
        }
    }}}}


bool check_repeatition(string x) {
    int z[256] = { 0 };
    int i;
    for (i = 0; x[i]; i++) {
        if (z[(unsigned char)x[i]] > 0) {
            return true;
        }
        z[(unsigned char)x[i]]++;

    }
    return false;
}