#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    string name;
    struct node *next;
} node;

const int Capacity = 26;

int main(void)
{
    node *n = malloc(sizeof(node));

    n->name = "z";
    n->next = NULL;
    node *list = n;

    for (int i = 1; i < Capacity; i++)
    {
        node *newNode = malloc(sizeof(node));
        char letter = 'z' - i;

        char *name = malloc(3 * sizeof(char));
        sprintf(name, "%c\n", letter);

        newNode->name = name;
        newNode->next = list;
        list = newNode;
    }

    while (list != NULL)
    {
        printf("%s ", list->name);
        list = list->next;
    }

    // Free the allocated memory
    while (n != NULL)
    {
        node *temp = n;
        n = n->next;
        free(temp->name);
        free(temp);
    }

    return 0;
}
