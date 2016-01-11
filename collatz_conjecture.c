#include "stdio.h"

int main(void) {
    printf("Collatz conjecture named after Lothar Collatz. The conjecture can be \n"
           "summarized as follows. Take any natural number n. If n is even, divide it\n"
           "by 2 to get n/2. If n is odd, multiply it by 3 and add 1 to obtain  3n+1.\n"
           "Repeat the process.\n"
           "The conjecture is that no matter what number you start with, \n"
           "you will always eventually reach 1.\n\n");
    
    int number, steps;
    printf("Enter a positive number or \'0\' to exit\n>>> ");
    scanf("%d", &number);
    while (number > 0) {
        steps = 0;
        while (number != 1) {
            if (number % 2 == 0)
                number /= 2;
            else
                number = 3 * number + 1;
            steps++;
        }
        printf("It takes %d step%s to reach 1.\n", steps, steps != 1? "s": "");
        printf("Enter next number or \'0\' to exit\n>>> ");
        if (scanf("%d", &number) != 1) break;
    }
    return 0;
}