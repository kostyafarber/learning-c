#include  <stdio.h>

int main(){
    int userInput = 0;

    printf("How many odd numbers do you want to see: ");
    scanf("%i", &userInput);

    // Print out first n odd numbers
    for(int i = 0; i <= userInput; ++i)
        printf("%i ", 2 + (2*i) - 1 );

    return 0;
}