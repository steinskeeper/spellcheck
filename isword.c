#include "def.h"
bool wordexists(char wordaccept[])
{
    trie *temp = root;
    int i;

    for (i = 0; wordaccept[i] != '\0'; i++) // Run loop till word end is reached
    {
        int id = wordaccept[i] - 'a'; 

        if (temp->start[id] == NULL)
            return false;
        temp = temp->start[id];
    }
    return true;
}