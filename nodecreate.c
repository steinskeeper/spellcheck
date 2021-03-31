#include "def.h"

trie *NodeCreate()
{
    int i;
    trie *n1 = malloc(sizeof(trie));
    
    for (i = 0; i < ALPHA_SIZE; i++)
        n1->start[i] = NULL;
    n1->isend = false;
    return n1;
}
