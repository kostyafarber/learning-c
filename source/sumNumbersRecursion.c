#include <stdio.h>

int sumNumbers(int a){
    if (a == 1)
        return a;
    else
        return a + sumNumbers(a - 1);
}
    
int main(){

    int result = sumNumbers(3);
    printf("%i\n", result);

    return 0;
}