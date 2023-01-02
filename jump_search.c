//
// Created by HtetZarni on 30/12/2022.
//

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int jump_search(int arr[], int size, int key);


int minimum(int x, int y) {
    if(x < y) {
        return x;
    } else {
        return y;
    }
}

int jump_size_find(int size) {



    return 0;
}

int main() {

    int array[] = {1,2,3,5,9,11,22,33,99,102,111,222};

    int sizeOfArray = sizeof (array) / sizeof (array[0]);

    int numToFind = 3;

    int index = jump_search(array,sizeOfArray,numToFind);

    if(index != -1) {
        printf("\t||||___We Found___||||\n");
        printf("Index number is %d | Number you wanted to find is %d\n",index, array[index]);

    } else {
        printf("\t|* * * We can't find * * *|");
    }

    return 0;
}

int jump_search(int arr[], int size, int key) {

    int step = (size / 2);

    int previous_step;

    while (arr[minimum(step,size) - 1] < key) {

        previous_step = step;

        step = step + (size / 2);

        if(previous_step >= size) {
            return -1;
        }

    }

    if(arr[step-1] == key) {
        return step-1;
    }

    for(int v=previous_step; v<step; v++) {
        if(arr[v] == key) {
            return v;
        }
    }
}

