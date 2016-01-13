#include "stdio.h"
#include "stdlib.h" // 
#include "time.h"   // Needs only for srand, rand and time functions

enum coin_state {
    tail,
    head
};

int flip(int state, int flip_num) {
    return (state + flip_num) % 2;
}

int main(void) {
    int flips, state;
    int tails = 0, heads = 0;
    printf("\t**** Coin flip simulator ***\n");
    srand(time(NULL));
    state = rand() % 2;
    printf("Current state: %s\n", 
           state? "Head": "Tail");
    printf("Enter number of flips or \'q\' to exit\n>>> ");
    while (scanf("%d", &flips) == 1) {
        printf("Coin tossing...\n");
        state = flip(state, flips);
        switch(state) {
            case tail: puts("Tail!"); 
                       tails++;
                       break;
            case head: puts("Head!"); 
                       heads++;
                       break;
        }
        while(getchar() != '\n'); // Clears the buffer
        printf("Number of tails - %d, number of heads - %d.\n", 
               tails, heads);
        printf("Enter next number of flips or \'q\' to exit\n>>> ");
    }
    puts("Good bye, User!");
    return 0;
}