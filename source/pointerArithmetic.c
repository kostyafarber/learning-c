#include <stdio.h>



int main(void){

    int x = 5;

    int *px = &x;


    printf("x\'s value is: %i\n", x);
    printf("x\'s address is: %p\n", &x);

    *px += 25; // add 25 via pointer

    printf("x\'s address is according to the pointer after addition is: %p\n", px);
    printf("pointer *px\'s address is: %p\n", (void *) &px);
    printf("The value *px is pointing to is: %i\n", *px);

    return 0;
}