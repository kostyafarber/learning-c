#include <stdio.h>

int main(){

    int n;

    printf("Please enter the multiplication table you wish to print out: ");
    scanf("%i", &n);

    for (int i = 1; i <= 10; i++)
    {
       printf("%i X %i = %i\n", n, i, i*n);
    }
    

    return 0;
}