#include "def.h"
void insertWord(char insertword[])
{
    trie *temp = root;
    int i;
    for (i = 0; insertword[i] != '\0'; i++)
    {
        int indexer = insertword[i] - 'a'; // To find the ASCII code of the current letter with respect to A

        if (temp->start[indexer] == NULL) //Check if the node is null
            temp->start[indexer] = NodeCreate(); //then create a new node
        temp = temp->start[indexer]; //else add a new child to node
    }
    temp->isend = true;
}