#include "def.h"
void autocorrect(char acword[])
{
    int length = strlen(acword);
    int i;

    printf("\ndid you mean this instead of %s: \n", acword);

    for (i = 0; i < length; i++)
    {
        
        char c = acword[i];
        char ch;
        for (ch = 'a'; ch <= 'z'; ch++)
        {
            if (ch != c)
            {
                acword[i] = ch;

                if (wordexists(acword) == true)
                {
                    printf("\t%s\n", acword);
                }
                
                }
        }
        acword[i] = c;
    }
}