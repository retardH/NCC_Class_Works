//
// Created by HtetZarni on 29/11/2022.
//

#include "stdio.h"
#include "time.h"
#include "stdlib.h"
void charGenerate();
void printingWords();
void biggestIndex();
void readChar();
void append();
int count[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
int biggestArrayIndex;
int main() {

    charGenerate();
    readChar();
    append();
    biggestIndex();
    printingWords();
//    for(int i=0; i<26; i++) {
//        printf("Total counts of %c in array is:  %d\n",(i+97),count[i]);
//    }

    return 0;
}

void charGenerate() {
    srand(time(NULL));

    FILE *fp;
    fp = fopen("char.txt", "w");

    int i = 0;
    while (i < 1000) {
        int randNum = rand() % 123;
        if(randNum > 96) {
            fprintf(fp,"%c",randNum);

            i++;
        }

    }

    fclose(fp);
}


void readChar() {
    FILE *rp;
    rp = fopen("char.txt", "r");
    int c = getc(rp);
    while (c != EOF) {

        int alphabet = c - 97;
        count[alphabet]++;
        c = getc(rp);

    }
    fclose(rp);
}

void append() {

    FILE *ap;
    ap = fopen("char.txt", "a");
    for(int i=0; i<26; i++) {
        fprintf(ap,"\nTotal counts of %c in array is:  %d",(i+97),count[i]);
    }

    fclose(ap);

}

void biggestIndex() {

    for(int i=0; i<26; i++) {
        if(count[i] > biggestArrayIndex) {
            biggestArrayIndex = count[i];
        }
    }



}

void printingWords() {

    for(int x=0; x<biggestArrayIndex; x++) {

        for(int y=0; y<26; y++) {
            if(count[y] > 0) {
                printf("%c  ",y+97);
                count[y]--;
            } else {
                printf("   ");
            }
        }
        printf("\n");

    }


}
