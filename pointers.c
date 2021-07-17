#include <stdio.h>

int x = 5;

int *px = &x;

int main(void){

    printf("x\'s value is: %i\n", x);
    printf("x\'s address is according to the pointer is: %p\n", px);
    printf("x\'s address is: %p\n", &x);
    printf("pointer *px\'s address is: %p\n", (void *) &px);
    printf("The value *px is pointing to is: %i\n", *px);

    return 0;
}