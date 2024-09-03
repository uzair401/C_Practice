#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<math.h>


//Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

//main
int main(void)
{
    // variables declaration
    string x = get_string("Text: ");
    int letters = count_letters(x);
    int words = count_words(x);
    int sentences = count_sentences(x);
    float L = (float)letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    //Coleman-Liau formula
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    if(grade > 16) {
        printf("Grade 16+\n");
    }
    else if (grade < 1){
        printf("Before Grade 1\n");
    }
    else {
    printf("Grade %i\n", grade);
    }
}

// Functions Declaration Section
int count_letters(string text){
    int letters = 0;
    for(int i = 0, length = strlen(text); i < length; i++)
    {
        if (islower(text[i])){
            letters++;
        }
        else if (isupper(text[i])){
            letters++;
        }
    }

     return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i=0, length = strlen(text); i < length; i++)
    {
        if(text[i] ==' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences= 0;
    for (int i=0, length = strlen(text); i < length; i++)
    {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?')
    {
        sentences++;
    }
}
    return sentences;
}