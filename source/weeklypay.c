#include <stdio.h>

// We could include constants 
#define TAXRATE_150 0.2

int main(){

    double hours = 0.0;
    double grossPay = 0.0;
    double taxes = 0.0;
    double netPay = 0.0;
    double basicPay = 12.00;

    // get hours from user
    printf("Please enter the number of hours you have worked: ");
    scanf("%lf", &hours);

    double overtimeHours = hours - 40;
    
    // calculate pay
    if (hours > 40)
        grossPay = (hours - overtimeHours) * basicPay + (overtimeHours * basicPay *1.5);
    
    else
        grossPay = hours * basicPay;

    // calculate taxes
    if (grossPay > 450){
        taxes = (300*0.15) + (150*0.2) + (grossPay - 450) * 0.25;
    }

    else if (grossPay <= 300)
    {
        taxes = grossPay * 0.15;
    }

    else

        taxes = (300 * 0.15) + (grossPay - 300) * 0.2;
    
    printf("Your pay is: $%.2f \n", grossPay);
    printf("Your taxes are: $%.2f \n", taxes);
    printf("Your net pay is: $%.2f \n", netPay = (grossPay - taxes));

    return 0;
}


