#include <stdio.h>

int replace(char* text) {
    int num_space_replacements = 0;

    while (*text != '\0') {
        if (*text == ' ') {
            char dash = '-';
            *text = dash;
            num_space_replacements++;

        }

        text++;
    }

    return num_space_replacements;
}

int main() {
    char test[] = "The cat sat";
    int n = replace(test);

    printf("%s\n", test);
    printf("The number of replacements is: %d\n", n);

    return 0;
}