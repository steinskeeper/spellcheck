#include "def.h"
void sort()
{
    char c;
    int count;
    FILE *wordlist;
    wordlist = fopen("words.txt", "r");
    for (c = getc(wordlist); c != EOF; c = getc(wordlist))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    int limit;
    
    char str[100000][20], t[100000];
    int i, j;
    for(limit = 0; limit < count+1; limit++)
    {
        fscanf(wordlist, "%s", str[limit]);
    }

    for(i=1; i<count+1; i++)
    {
        for(j=1; j<count+1; j++)
        {
            if(strcmp(str[j-1], str[j])>0)
            {
                strcpy(t, str[j-1]);
                strcpy(str[j-1], str[j]);
                strcpy(str[j], t);
            }
        }
    }
    fclose(wordlist);
    wordlist = fopen("words.txt","w");

    for(i=0; i<count+1; i++)
        fprintf(wordlist,"%s\n", str[i]);
    fclose(wordlist);
    
    printf("Word added");
    exit(1);
}
void addtofile(char word[])
{
    FILE *wordlist;
    wordlist = fopen("words.txt","a");
    fputs("\n", wordlist);
    fputs(word,wordlist);
    fclose(wordlist);
    sort();
}
