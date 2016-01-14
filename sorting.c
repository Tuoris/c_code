#include "stdio.h"

void print_array(int *arr, int length);
void copy_array(int *arr, int *result, int length);
void buble_sort(int *arr, int *result, int length);

int main(void) {
    int numbers [10] = {2, 0, 5, 7, 4, 8, 1, 6, 9, 3};
    int b_result[10];
    buble_sort(numbers, b_result, 10);
    puts("Current array:");
    print_array(numbers, 10);
    puts("After buble sort:");
    print_array(b_result, 10);
    return 0;
}

void print_array(int *arr, int length) {
    printf("{");
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d}\n", arr[length - 1]);
}

void copy_array(int *arr, int *result, int length) {
    for (int i = 0; i < length; i++) {
        result[i] = arr[i];
    }
}

void buble_sort(int *arr, int *result, int length) {
    copy_array(arr, result, length);
    int temp;
    for (int i = 0; i < length; i++) {
        for (int u = 0; u < length - i - 1; u++) {
            if (result[u] > result[u + 1]) {
                temp = result[u];
                result[u] = result[u + 1];
                result[u + 1] = temp;  
            }
        }
    }
}