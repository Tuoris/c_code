#include "stdio.h"
#define MAX_LEN 256
#define V_COUNT 6

int main(void) {
    char vowels[V_COUNT] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int numbers[V_COUNT] = { 0, 0, 0, 0, 0, 0};
    char text[MAX_LEN];

    printf("Enter the text\n>>> ");
    fgets(text, MAX_LEN, stdin);

    int vowels_number = 0;
    int text_pos = 0;
    while (text[text_pos]) {
        for (int i = 0; i < V_COUNT; i++) {
            if (text[text_pos] == vowels[i]) {
                vowels_number++;
                numbers[i]++;
            }
        }
        text_pos++;
    }

    printf("Number of vowels: %d\n", vowels_number);
    char separators[][3] = {", ", ".\n"};
    for (int i = 0; i < V_COUNT; i++) {
        if (numbers[i]) {
            printf("%c - %d", vowels[i], numbers[i]);
            vowels_number -= numbers[i];
            printf("%s", separators[vowels_number == 0]);
        }
    }
    
    return 0;
}