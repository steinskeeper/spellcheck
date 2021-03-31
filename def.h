#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHA_SIZE 26

typedef struct data
{
    bool isend;
    struct data *start[ALPHA_SIZE];

} trie;

trie *root;

trie *NodeCreate();
void insertWord(char insertword[]);
bool wordexists(char wordaccept[]);
void autocorrect(char acword[]);
void checkfile(char filename[50]);
void addtofile(char wordtoadd[50]);
