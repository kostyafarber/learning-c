#include <stdio.h>

int countString(char *Str){
    
    int count;

    while (*Str){
        *Str++;
        count += 1;
        
    }
    return count;
}


int main(void)
{
    char name[] = "Kostya";
    
    char *Ptr = name;

    while(*Ptr){
        printf("%c", *(Ptr));
        ++Ptr;
    }

    printf("\n");
    printf("%s is %i characters long", name, countString(name));
    
}