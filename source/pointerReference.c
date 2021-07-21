#include <stdio.h>

void squareReference(int *n){

    *n = (*n)*(*n); // doesn't return a value but we can still change by reference
}

int main (void){

    int num = 6, *nPtr = &num;

    squareReference(nPtr);

    printf("%i\n", num);

}

