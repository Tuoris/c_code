#include "stdio.h"
#define MAX_LEN 80

void reverse(char * string, char * reversed);
void insant_reverse(char * string);
int ispalindrome(char * string);

// Didn't want use string.h
int len(char * string) {
    int len = 0;
    while (string[len] != '\n' && string[len] != '\0') len++;
    return len;
}

// Didn't want use ctype.h
inline int tolower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
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
    printf("Palindrome: %s\n", ispalindrome(string)? "yes": "no");
    return 0;
}

void reverse(char * string, char * reversed) {
    int slen = len(string);
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

int ispalindrome(char * string) {
    int p_flag = 1;
    int slen = len(string);
    for (int index = 0; index < slen; index++) {
        if (tolower(string[index]) != tolower(string[slen - index - 1])) {
            p_flag = 0;
            break;
        }
    }
    return p_flag;
}