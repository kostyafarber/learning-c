#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool myBool = true;
    int a = 33;
    int b = 25;

    bool result = !(a && b);
    
    printf("%d", result);

    return 0;
}