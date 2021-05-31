#include <stdio.h>


// Recursion solution to find the greatest common factor of two numbers.
int gcfTwoNumbers(int a, int b){
    if (a % b == 0)
        return b;
    else
        return gcfTwoNumbers(a, a % b);
}

int main(){
    
    int result = gcfTwoNumbers(234234,45344);
    printf("%i \n", result);
    return 0;
}