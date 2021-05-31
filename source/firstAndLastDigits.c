#include <stdio.h>

int main(){

    int n;
    int lastDigit;
    // find first last digit

    printf("Please enter a number: ");
    scanf("%i", &n);

    lastDigit = n % 10;

    while (n >= 10){
        n = n / 10; 
    }
        
        printf("Last digit is: %i and first digit is: %i\n", lastDigit, (int)n);

    return 0;
}