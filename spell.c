#include "def.h"
int main()
{
    int limit;
    char mainword[50];
    
    root = NodeCreate();//go to NodeCreate() and create a trie
    
    FILE *wordlist; //create a FILE for wordlist
    wordlist = fopen("words.txt", "r"); //open the dictionary file
    for (limit = 0; limit < 100000; limit++)
    {
        fscanf(wordlist, "%s", mainword);
        insertWord(mainword); //calls the insertWord func and pass value inside it
    }
    fclose(wordlist);
    
    char enterword[50];
    
    printf("Welcome to Spell Check and Autocomplete Program\n");
    printf("Menu");
    printf("-----------------------------------------------\n");
    printf("1. Find spelling mistakes in a file\n");
    printf("2. Enter word in terminal to find mistake\n");
    printf("3. Add word to database\n");
    printf("4. Help\n");
    printf("5. Info\n");
    printf("-----------------------------------------------\n");
    printf("Enter your Choice : \n");
    int menuchoice;
    scanf("%d", &menuchoice);

    switch (menuchoice)
    {
    case 1:
        printf("Enter the text file you want check : ");
        scanf("%s", enterword);
        checkfile(enterword);
        break;
    
    case 2:
        printf("Enter word you want to check : \n");
        scanf("%s", enterword);

        bool i = wordexists(enterword); // send word to check if it exists in the trie
        if (i == true)
        {
            printf("%s - Spelling Correct\n", enterword);
        }
        else
        {
            printf("Spelling Mistake identified"); // if word != inside trie then pass it to autocorrect.
            autocorrect(enterword);
        }

        break;
    case 3: 
    //this case used add words to dictionary
    // by calling the addtowordlist() function
        printf("Enter the word to be added to the database : ");
        scanf("%s", enterword);
        addtofile(enterword);
        break;

    case 4:
        printf("-------------Help---------------\n");
        printf("The program provides the following features that are mentioned below\n");
        printf("\n\n");
        printf("Find spelling mistakes in a file\n");
        printf("Enter word in terminal to find mistake\n");
        printf("Add word to database\n");

        printf("The program provides the following features that are mentioned below\n");
        printf("\n\n");
        printf("Requires a dictionary file with words");
        printf("\n\n");
        printf("Create a text file in the root dir to enable file scan");

        break;

    case 5:
        printf("This Spell Check Program and Autocorrect \nWas developed by Dhanush Y P of 3rd Semester from CSE Engineering Departmant\n");
        printf("Written using C language, implemented with Tries Data structure and compiled on GNU/Linux using the gcc compiler\n");
        
        break;
    }

    return 0;
}
