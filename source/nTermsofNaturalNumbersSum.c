#include <stdio.h>

int main(){

    int n;
    int sum = 0;

    // Get user input for n
    printf("Test Data: ");
    scanf("%i", &n);

    printf("The first %i natural number is: \n", n);
    
    // loop over first n natural numbers and print
    for(int i = 1; i <= n; i++){
        
        printf("%i ", i);

        sum = sum + i;

    }
    printf("\n");
    printf("The Sum of Natural Numbers upto %i terms: %i\n", n, sum);
}
    
        