#include "def.h"
void checkfile(char filename[50])
{

    char spell[23];
    FILE *userfile;
    userfile = fopen(filename, "r");
    if (userfile != NULL)
    {
        fscanf(userfile, "%s", spell);
        spell[22] = fgetc(userfile);
        while (spell[22] != EOF) //read the userfile word by word
        {
            bool i = wordexists(spell);
            if (i == true)
            {
                printf("%s FOUND \n", spell);
            }
            else
            {

                autocorrect(spell);
            }
            fscanf(userfile, "%s", spell);
            spell[22] = fgetc(userfile);
        }
        fclose(userfile);
    }
    else
        printf("The userfile you are looking for is not to be found.");
}