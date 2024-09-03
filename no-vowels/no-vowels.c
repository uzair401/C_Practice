// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string ss);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: No Vowel Words\n");
        return 1;
    }
    string data = argv[1];
    printf("%s\n", replace(argv[1]));
}

string replace(string ss)
{   string s = ss;
    for(int i = 0 , n = strlen(s); i < n; i++)
    {
        switch (s[i])
        {
            case 'a':
            s[i] = '6';
            break;

            case 'e':
            s[i] = '3';
            break;

            case 'i':
            s[i] = '1';
            break;
            case 'o':
            s[i] = '0';
            break;
        }

    }
     return s;
}
