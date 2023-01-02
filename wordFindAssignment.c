//
// Created by HtetZarni on 07/12/2022.
//

#include "stdio.h"
#include "stdlib.h"
void find_winhtut();
void find_ncc();
int winhtutFound = 0;
int nccFound = 0;
int count; // for each word's count
int matchingCount; // counts if words from read file and array data match
char wordArray[7];
char nccWordArray[17];

// built typical arrays to compare with the data from wordArray.
char winhtut[7] = {'w','i','n','h','t','u','t'};
char ncc[30] = {'N','a','t','i','o','n','a','l','C','y','b','e','r','C','i','t','y'};

int main() {

        find_winhtut();
        find_ncc();
        printf("\n\t>>> NationalCyberCity found: %d <<<\n", nccFound);
        printf("\n\t>>> winhtut found: %d <<<\n",winhtutFound);
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

void find_ncc() {

    FILE *fptr;
    fptr = fopen("word.txt","r");
    char w = getc(fptr);
    while (w != EOF) {


        if (w != ' ' && count > 0 && count < 17) {
            nccWordArray[count] = w;
            count++;
        } else if (w == 'N') {
            count = 0;
            nccWordArray[count] = w;
            count++;
        } else if (count == 17) {
            matchingCount = 0;
            for (int x = 0; x < 17; x++) {

                if (nccWordArray[x] == ncc[x]) {
                    matchingCount++;
                    if (matchingCount == 17) {
                        nccFound++;
                        count = 0;
                    }
                }
            }
        }
        w = getc(fptr);
    }
    fclose(fptr);

}