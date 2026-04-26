#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char *words[] = {"apple", "table", "chair", "house", "plant"};
    srand(time(0));
    int index = rand() % 5;
    char word[20];
    strcpy(word, words[index]);
    printf("DEBUG: Word is %s\n", word);
    int length = strlen(word);
    char guessed[20];
    for(int i = 0; i < length; i++) {
        guessed[i] = '_';
    }
    guessed[length] = '\0';
    int attempts = 5;
    while(attempts > 0) {
        printf("\nWord: %s", guessed);
        printf("\nAttempts left: %d", attempts);
        char guess;
        printf("\nEnter a letter: ");
        scanf(" %c", &guess);
        int found = 0;
        for(int i = 1; i < length; i++) {
            if(word[i] == guess) {
                guessed[i] = guess;
                found = 1;
            }
        }
        if(found == 0) {
            attempts--;
            printf("Wrong guess!\n");
        }
        if(strcmp(word, guessed) == 0) {
            printf("\nYou Win! The word is: %s\n", word);
            break;
        }
    }
    if(attempts == 0) {
        printf("\nYou Lose! The word was: %s\n", word);
    }

    return 0;
}