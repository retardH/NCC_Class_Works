
//
// Created by HtetZarni on 07/12/2022.
//

#include "stdio.h"
#include "stdlib.h"
void find_winhtut();
void find_ncc();
void userInputFind();
int winhtutFound = 0;
int nccFound = 0;
int userInputWordFound = 0;
int count; // for each word's count
int matchingCount; // counts if words from read file and array data match
char wordArray[7];
char nccWordArray[17];
char input_word;

// built typical arrays to compare with the data from wordArray.
char winhtut[7] = {'w','i','n','h','t','u','t'};
char ncc[30] = {'N','a','t','i','o','n','a','l','C','y','b','e','r','C','i','t','y'};

int main() {
//
//    find_winhtut();
//    find_ncc();
    userInputFind();
//    printf("\n\t>>> NationalCyberCity found: %d <<<\n", nccFound);
//    printf("\n\t>>> winhtut found: %d <<<\n",winhtutFound);
    printf("user input word found: %d",userInputWordFound);
    return 0;
}

void find_winhtut() {

    FILE *fptr;
    fptr = fopen("word.txt","r");
    char w = getc(fptr);
    while (w != EOF) {


        // condition will work until w(the data from the file) is whitespace, count already has to be incremented
        // and count can't pass more than 6.
        if(w != ' ' && count > 0 && count < 7 && w != '\n') {
            wordArray[count] = w;
            count++;
        }

        // if 'w' is found, it's added to the array as first item and will check another consecutive words.
        if(w == 'w') {
            count = 0;
            wordArray[count] = w;
            count++; // count's incremented everytime an item is added to the array
        }

        // if count is 7(in another word, after the word reach the whitespace) this condition will work
        if(count == 7) {
            matchingCount = 0;
            for(int x=0; x<7; x++) {

                if(wordArray[x] == winhtut[x]) {
                    matchingCount++; // matching count is incremented everytime two array items are equal.
                    if(matchingCount == 7) {
                        winhtutFound++; // incremented after the whole word is founded and equal to the typical array items
                        count = 0; // after that, count is reset to 0.
                    }
                }
            }
        }


        w = getc(fptr);
    }

    fclose(fptr);


}


void userInputFind() {

    char userInput[100];
    char compareArray[100];
    int array_index = 0;

    for(int a=0; a<100; a++) {
        userInput[a] = '0';
    }
    while (!NULL) {
        printf("Enter each word you'd like to find.\t Enter 0 to quit. \n\t--------: ");
        scanf("%c",&input_word);
        if(input_word == '0') {
            break;
        }
        userInput[array_index] = input_word;
        array_index++;
    }

    FILE *fptr;
    fptr = fopen("word.txt","r");
    char w = getc(fptr);
    while (w != EOF) {

        if (w != ' ' && w!= '\n' && count > 0 && count < array_index) {
            compareArray[count] = w;
            count++;
        }

        if (w == userInput[0]) {
            count = 0;
            compareArray[count] = w;
            printf("%c",w);
            count++;
        }

        if (count == array_index) {
            matchingCount = 0;
            for (int x = 0; x < array_index; x++) {

                if (compareArray[x] == userInput[x]) {
                    matchingCount++;
                    if (matchingCount == 17) {
                        userInputWordFound++;
                        count = 0;
                    }
                }
            }
        }

        w = getc(fptr);
    }





}