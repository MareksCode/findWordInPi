#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getCharFromTwoNumbers(int numbers) {
    return (char)('a' + numbers % 26);
}

void searchPiFor(char *word) {
    FILE *filePointer = fopen("./pi.txt", "r");
    if (filePointer == NULL) {
        printf("Could not open file\n");
        return;
    }
    char ch;
    char prevCh = 0;
    int counter = 0;
    char* fullStringNum = malloc(sizeof(char) * 2);
    int currentReconstructIndex = 0;
    long int returnCounter = 0;
    while ((ch = fgetc(filePointer)) != EOF) {
        counter = (counter + 1)%2;
        returnCounter += 1;
        if (counter == 1) {
            prevCh = ch;
        } else {
            fullStringNum[0] = ch;
            fullStringNum[1] = prevCh;

            char parsedCharacter = (char)((int)'a'+(atoi(fullStringNum)%26));
           // printf("parsedCharacter: %c\n", parsedCharacter);

            if (word[currentReconstructIndex] == parsedCharacter) {
                currentReconstructIndex += 1;
            } else {
                currentReconstructIndex = 0;
            }

            if (currentReconstructIndex == strlen(word)) {
                printf("Found the word! @%llu", returnCounter-strlen(word));
                free(fullStringNum);
                return;
            }
        }
    }
    printf("Found nothing");
    free(fullStringNum);
}

int main() {
    char word[] = "hey";
    searchPiFor(word);
    return 0;
}