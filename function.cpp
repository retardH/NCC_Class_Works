//
// Created by htetzarni on 10/11/2022.
//

#include "stdio.h";

// function declaration
int maxNumberOutput(int num1, int num2);
char charOutput(char fChar, char sChar);
int totalSum(int totalNums);
int primeNumber(int num);

int main() {



    int myNum = maxNumberOutput(2,4);
    printf("%d\n",myNum);

    char myChar = charOutput('h', 'd');
    printf("\n %c",myChar);

    int sUm = totalSum(9);
    printf("The total sum is %d.\n", sUm);

    primeNumber(9);




    return 0;


}

int maxNumberOutput(int num1, int num2) {
    int result;

    if(num1 > num2) {
        result = num1;
    } else {
        result = num2;
    }

    return result;
}


char charOutput(char fChar, char sChar) {

    printf("\n %c",fChar);
    printf("\n %c",sChar);

    return 'a';
}


int totalSum(int totalNums) {
    int sum = 0;

    for(int n = 1; n <= totalNums; n++) {

        sum += n;
    }


    return sum;
}


int primeNumber(int num) {

    for(int n = 0; n <= num; n++) {

        if(n % 2 != 0) {
            printf("This is a prime number:%d\n",n);
        } else {
            printf("This is not a prime number:%d\n",n);
        }

    }


    return  0;

}