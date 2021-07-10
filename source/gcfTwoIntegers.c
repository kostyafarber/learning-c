#include <stdio.h>
#include <math.h>

// Recursion solution to find the greatest common factor of two numbers.
int gcfTwoNumbers(int a, int b){
    if (a % b == 0)
        return b;
    else
        return gcfTwoNumbers(b, a % b);
}

// absolute value of a number
double absoluteValue(double a){
    if (a > 0) 
        return a;
    else
        return -a;
}
 
 double sqrt(double a){
     if (a < 0)
        return pow(-a, 0.5);
    else
        return pow((double)a, 0.5);
 }
int main(){
    
    // test gcf algorithm
    int result = gcfTwoNumbers(1026,405);
    printf("%i \n", result);

    // test absolute value function
    double value = absoluteValue(-9);
    printf("%.2f \n" , value);

    double sqrtResult = sqrt(-9);
    printf("%f \n", sqrtResult);

    return 0;
}