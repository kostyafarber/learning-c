#include <stdio.h>

#define N 10.0

int main(){

    int sum = 0;

    printf("Please input 10 numbers: \n");

    for (int i = 1; i <= N; i++)
    {
        int add = 0;

        printf("Number %i: ", i);
        scanf("%i", &add);

        sum = sum + add;

    }

    printf("The sum of the 10 numbers is: %i\n", sum);
    printf("The average of the 10 numbers is %.2f\n", sum/N);
    return 0;
}