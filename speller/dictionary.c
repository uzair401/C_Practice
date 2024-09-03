// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <cs50.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
#define N 26

// Hash table
node *table[N];

// Number of words loaded from dictionary
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowercase[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        lowercase[i] = tolower(word[i]);
    }
    lowercase[strlen(word)] = '\0';

    // Get hash index for the word
    int index = hash(lowercase);

    // Traverse the linked list at the hash index
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(lowercase, cursor->word) == 0)
        {
            return true; // Word found in dictionary
        }
        cursor = cursor->next;
    }

    return false; // Word not found in dictionary
}

// Hashes word to a number between 0 and N-1, inclusive
unsigned int hash(const char *word)
{
    // Use the first character of the word to determine the index
    int first_char = tolower(word[0]);
    return first_char - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Clear hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Buffer for storing words read from file
    char word[LENGTH + 1];

    // Read words from file and insert into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy word to new node
        strcpy(new_node->word, word);

        // Get hash index for the word
        int index = hash(word);

        // Insert the new node at the beginning of the linked list
        new_node->next = table[index];
        table[index] = new_node;

        // Increment word count
        word_count++;
    }

    // Close dictionary file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each index in the hashtable
    for (int i = 0; i < N; i++)
    {
        // Free the linked list at each index
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
