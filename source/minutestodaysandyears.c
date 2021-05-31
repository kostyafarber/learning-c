#include <stdio.h>

int main()
{

    int minutes;

    // get input from the user
    printf("Please enter the number of minutes: ");
    scanf("%i", &minutes);

    int minutesAYear = 60*24*365;
    double years = (minutes / minutesAYear);
    double days =  (minutes % minutesAYear)/(60*24);

    printf("%i minutes is %.0f Years and %.0f Days\n", minutes, years, days);
    
    return 0;
}