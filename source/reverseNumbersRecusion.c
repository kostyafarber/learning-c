#include <stdio.h>

void reverseNumbers(int a){
    printf("%i ", a);
    if (a > 0)
        reverseNumbers(a - 1);
    else
        printf("\n");
}

int main(){

    reverseNumbers(10);

}