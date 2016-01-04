#include "stdio.h"
#include "strings.h"

void show_rule(void);
void to_bin(int, char[256]);

int main(void) {
    int decimal;
    char binary[256];
    show_rule();
    while (scanf("%d", &decimal) == 1) {
        to_bin(decimal, binary);
        printf("  %d -> %s\n", decimal, binary);

        // Cleaning input buffer
        char ch;
        while((ch = getchar()) != '\n');
        show_rule();
    }
    return 0;
}

void show_rule(void) {
    printf("Enter decimal number to convert or \'q\' to exit: ");    
}

void to_bin(int number, char data[256]) {
    int index = 0;
    if (number == 0) {data[0] = '0', index++;};
    while (number > 0) {
        data[index] = (number % 2)? '1': '0';
        number /= 2;
        index++;
    }
    data[index] = '\0';
    
    char temp;
    int len = strlen(data);
    for (int pos = 0; pos < len / 2; pos++) {
        temp = data[pos];
        data[pos] = data[len - pos - 1];
        data[len - pos - 1] = temp;
    }
}
