#include <stdio.h>

int main() {
    int totalLoop = 10;
    for(int i = 0; i < totalLoop; i++) {


            for(int j = totalLoop; j > i; j--) {
                printf(" ");
            }

            for(int k = 0; k <= i; k++) {
                if(k == 0) {
                    printf("*");
                } else {
                    printf("**");
                }
            }


        printf("\n");

    }
    printf("\n");



    // reversed triangle

    for(int i = 0; i < totalLoop; i++) {

        for(int j = 0; j <= i; j++) {
            printf(" ");
        }

        for(int k = totalLoop; k > i; k--) {
            if(k != totalLoop) {
                printf("**");
            } else {
                printf("*");
            }
//            printf("*");
        }

        printf("\n");
    }

    return  0;
}