#include "stdio.h"
#include "strings.h"
#include "stdlib.h"

int min(int, int);
int find(char [10]);

struct currency {
    char name[10];
    float rate;
};

struct currency rates[] = {
    {"uah",  1.00},
    {"usd", 24.33},
    {"eur", 26.44},
    {"rub",  0.32},
    {"gbp", 34.83},
    {"chf", 23.51},
    {"cad", 16.41},
    {"pln",  5.73},
    {"end",  0.00}
};

int main(void) {
    puts("\n\t\tCurrency converter");
    puts("Enter your expression in format: \'25 usd to uah\'");
    printf("Available currencies: ");
    for (int i = 0; strcmp(rates[i].name, "end"); ++i) {
        printf("%s ", rates[i].name);
    }
    printf(".\n");

    printf(">>> ");
    char buffer[80], uin[3][10];
    float cash;
    fgets(buffer, 80, stdin);
    fflush(stdin);
    
    char *pch = strtok(buffer, " -\t\n");
    cash = atof(pch);
    int i = 0;
    int len;
    while (pch != NULL && i < 3) {
        pch = strtok(NULL, " -\t\n");
        len = min(9, strlen(pch));
        strncpy(uin[i], pch, len);
        uin[i][len] = '\0';
        /*printf("%s\n", uin[i]);
        printf("%d %d\n", find(uin[i]), i);*/
        i++;
    }
    fflush(stdin);

    if (find(uin[0]) == -1 || find(uin[2]) == -1) {
        puts("!<< can\'t find such rate");
    } else if (!strcmp(uin[0], uin[2])) {
        printf("%.2f %s\n", cash, uin[2]);
    } else {
        float uah_rate = rates[find(uin[0])].rate;
        float rate     = rates[find(uin[2])].rate;
        cash = cash * uah_rate / rate;
        printf("<<< %.2f %s\n", cash, uin[2]);
    }

    return 0;
}

int min(int x, int y) {
    return (x < y)? x : y; 
} 

int find(char cur[10]) {
    int index = -1;
    for (int i = 0; strcmp(rates[i].name, "end"); ++i) {
        if(!strcmp(cur, rates[i].name)) {
            index = i;
            return index;
        }
    }
    return index;
}
