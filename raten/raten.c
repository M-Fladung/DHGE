#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{

    const char *words[] = {"Hund", "Katze", "Wald", "Kopfhörer", "Computer", "Tastatur", "Monitor"};
    int num_words = sizeof(words) / sizeof(words[0]); 


    srand(time(NULL));


    int random_index = rand() % num_words;
    const char *myword = words[random_index];
    int length = strlen(myword);
    

    printf("Das zufällige Wort ist: %s\n", myword);
    printf("Zeichen sind: %d\n", length);

    char guessedword[length + 1];
    for(int i = 0; i < length;i++)
    {
        guessedword[i] = '*';
    }
    guessedword[length] = '\0';

    for(int versuch = 1;;versuch++)
    {
        char ch;
        bool guessed = false;
        printf("Dein Wort\n %s\n", guessedword);
        scanf(" %c", &ch);
        for(int i = 0; i < length; i++){
            if(myword[i] == ch){
                guessedword[i] = ch;
                guessed = true;
            }else{
                guessed = false;
            }
        }
        if(strcmp(guessedword, myword) == 0){
            printf("Dein Wort\n %s\n", guessedword);
            printf("Gewonnen in %d Versuchen\n", versuch);
            break;
        }

    }

    return 0;
}
