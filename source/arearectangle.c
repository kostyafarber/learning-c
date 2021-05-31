#include <stdio.h>

int main()
{
    double width;
    double height;
    
    printf("Please Enter the Dimensions of your Rectangle.\n");
    scanf("%lf %lf", &width, &height);

    double area = width * height;
    double perimeter = (width + height) * 2;

    printf("Width = %.2lf, Height = %.2lf, Perimeter = %2.lf\n", width, height, perimeter);
    printf("Width = %.2lf, Height = %.2lf, Area = %2.lf\n", width, height, area);

    return 0;
}
