//
// Created by HtetZarni on 26/11/2022.
//


#include <stdio.h>

int main()
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;

    printf("%f ", *ptr2);
    printf("%d", (ptr2 - ptr1));
    // Explanation //
//    When we add a value x to a pointer p,
//    the value of the resultant expression is p + x*sizeof(*p) where sizeof(*p) means size of data type pointed by p.
//    That is why ptr2 is incremented to point to arr[3] in the above code. Same rule applies for subtraction.
//    Note that only integral values can be added or subtracted from a pointer.
//    We can also subtract or compare two pointers of same type.


        // 03 : to ask sayar!
        int a;
        char *x;
        x = (char *) &a;
        a = 512;
        x[0] = 1;
        x[1] = 2;
        printf("%d\n",a);


        // 04
        char *cptr = "GeekForGeeks";
        printf("\n%c",*cptr);








    return 0;

}