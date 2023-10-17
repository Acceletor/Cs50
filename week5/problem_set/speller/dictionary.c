// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];
int count = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *n = table[index];
    while(n != NULL)
    {
        if(strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        else
        {
            n = n->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    // TODO: Improve this hash function
    if (strlen(word) > 5){
        return toupper(word[0]) - 'A';
    }
    else
    {
        return toupper(word[0]) - 'A' + 25;
    }

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *fp = fopen(dictionary,"r");
    if (fp == NULL) {
        printf("no such file.");
        return false;
    }

    char fp_word[LENGTH + 1]; // Temporary storage for word
    while(fscanf(fp, "%s",fp_word) != EOF)
    {
        int index = hash(fp_word);
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(fp); // Close the file before return
            return false;
        }
        strcpy(new_node->word, fp_word);
        new_node->next = table[index];
        table[index] = new_node;
        count ++;
    }
    fclose(fp);
    //printf("count = %i", count);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0, size = N; i < size; i++)
    {
        node *n = table[i];
        while(n != NULL)
        {
            node *ptr = n->next;
            free(n);
            n = ptr;
        }
    }

    return true;
}
