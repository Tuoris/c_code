#include "stdio.h"

int divider(int number, int base) {
    return number % base == 0;
}

int main(void) {
    puts("0");
    for (int i = 1; i <= 100; i++) {
        if (divider(i, 5) && divider(i, 3))
            puts("FizzBuzz");
        else if (divider(i, 5))
            puts("Buzz");
        else if (divider(i, 3))
            puts("Fizz");
        else
            printf("%d\n", i);
    }
    return 0;
}