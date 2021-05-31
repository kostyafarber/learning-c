#include <stdio.h>

int main(){

    int n;

    printf("Please enter the upper bound for the multiplication table you wish to see: ");
    scanf("%i", &n);

   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= n; j++)
       {
           printf("%i x %i = %i ", j, i, i * j);
       }
    printf("\n");
   }
   
   
   
   
    

    return 0;
}