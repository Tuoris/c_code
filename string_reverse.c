#include "stdio.h"
#define MAX_LEN 80

// Didn't want use string.h
int len(char * string) {
    int len = 0;
    while (string[len] != '\n' && string[len] != '\0') len++;
    return len;
}

void reverse(char * string, char * reversed) {
    int slen = len(string);
    printf("%d\n", slen);
    for (int index = 0; index < slen; index++) {
        reversed[slen - index - 1] = string[index];
    }
    string[slen]   = '\0';
    reversed[slen] = '\0';
}

void insant_reverse(char * string) {
    char temp;
    int slen = len(string);
    for (int shift = 0; shift < slen/2; shift++) {
        temp = string[shift];
        string[shift] = string[slen - shift - 1];
        string[slen - shift - 1] = temp;
    }
}

int main(void) {
    char string [MAX_LEN];
    printf("Enter any string\n>>> ");
    fgets(string, MAX_LEN, stdin);
    char reversed [MAX_LEN];
    reverse(string, reversed);
    printf("Entered string: %s\n", string);
    printf("Reversed string: %s\n", reversed);
    insant_reverse(string);
    printf("Instant reverse: %s\n", string);
    return 0;
}