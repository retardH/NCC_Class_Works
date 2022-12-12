//
// Created by HtetZarni on 23/11/2022.
//

#include "stdio.h"
#include "stdlib.h"

int main() {

    int num;
    int userInput;
    int resultArray[1000];
    FILE *fptr;
    FILE *rfptr;

    fptr = fopen("numbers.txt", "w");

    if(fptr == NULL) {
        exit(1);
    }
    printf("Enter a number: ");
    scanf("%d",&userInput);     // prints out the numbers whatever user wants

    for(int i=0; i<userInput; i++) {

        num = i+1;

        fprintf(fptr,"%d\n",(i+1));     // writes to number.txt file for every loop

        rfptr = fopen("numbers.txt","r");

        fscanf(rfptr,"%d",&num);    // reads number.txt file for every loop

        resultArray[i] = num;   // adding read numbers into array

    }

    fclose(fptr);


    // output
    int j=0;
    while (j < userInput) {

        if(resultArray[j] <= userInput) {
            if(resultArray[j] == userInput / 2) {
                printf("%d,\n",resultArray[j]);
            } else {
                printf("%d,",resultArray[j]);
            }
        }

        j++;
    }


    return 0;
}