#include <stdio.h>

int main(){
    
    int nrows;

    printf("How many rows in the pyrmaid would you like, sir? \n");
    scanf("%i", &nrows);

    for (int i = 1; i <= nrows; i++)
    {
        for (int space = nrows; space >=  i; space--)
        {
            printf(" ");
        }
            for (int j = 1; j <= i*2-1; j++)
            {
                printf("*");
            }
    printf("\n");
    }
    
    return 0;
}
