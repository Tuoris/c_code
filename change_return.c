#include "stdio.h"

typedef struct {
    int ipart; // dollars part
    int cpart; // coins part
} CASH;

void give_change(double cost, double money, CASH * change);
void print_change(int coin_change);

int main(void) {
    double cost, money;
    CASH change;
    printf("Enter a cost and the amount of money that given\n>>> ");
    scanf("%lf %lf", &cost, &money);
    printf("%f %f\n", cost, money);
    give_change(cost, money, &change);
    printf("\nYour change: %d dollar(s) and %d cent(s).\n", change.ipart, change.cpart);
    if (change.cpart) print_change(change.cpart);
    return 0;
}

void give_change(double cost, double money, CASH * change) {
    change->ipart = (int)(money - cost);
    change->cpart = (int)((int)(money*100) - (int)(cost*100)) % 100;
    return;
}

void print_change(int coin_change) {
    int    coins [5] = {50, 25, 10, 5, 1};
    char * names [5] = {"half", "quarter", "dime", "nickel", "penny"};
    int number; // number of coins need
    printf("You will get: ");
    for (int i = 0; i < 5; i++) {
        number = coin_change/coins[i];
        if (number != 0) {
            coin_change -= number*coins[i];
            printf("%d %s%s%c ", 
                   number, 
                   names[i],
                   (number != 1)? "s": "", 
                   (coin_change > 0)? ',': '.'
                   );
        }
    }
} 