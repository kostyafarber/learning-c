#include <stdio.h>

void iterate_over_character_array(char* name) {
    while (*name != '\0') {
        printf("%c", *name);
        name++;
    }
    printf("\n");
}

void iterate_over_nums_array(int* nums) {
    while (*nums != -1) {
        printf("%d ", *nums);
        nums++;
    }
    printf("\n");
}

void iterate_over_nums_array_size(size_t size, int* nums) {
    int i = 0;
    while (i < size - 1) {
        printf("%d ", *nums);
        nums++;
        i++;
    }
    printf("\n");
}

int main() {
    char* name = "Kostya";
    int nums[7] = {0, 1, 2, 3, 5, 5, -1};
    
    printf("Now iterating over array of characters... \n");
    iterate_over_character_array(name);

    printf("Now iterating over array of numbers... \n");
    iterate_over_nums_array(nums);

    size_t size_nums = sizeof(nums);
    printf("Size of the nums array is: %zu \n", size_nums); 

    signed int num_elements = sizeof(nums) / sizeof(nums[0]);
    printf("Length of nums array is: %d\n", num_elements);

    iterate_over_nums_array_size(7, nums);
    return 0;
}