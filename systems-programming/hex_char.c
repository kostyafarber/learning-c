#include <stdio.h>

int main(void) {
    char one;
    char two;

    printf("Please enter two characters: \n");

    scanf("%c", &one); 
    scanf("%c", &two);

    printf("Character 1: %x and character2: %x \n", one, two); 
    return 0;
}