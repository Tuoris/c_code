#include "stdio.h"
#include "math.h"

int fact(int);
double fast_pi(void);
double sigma(int);

int main(void) {
    double pi = fast_pi();
    printf("%.16lf\n", pi);
    return 0;
}

int fact(int num) {
    int f = (num == 0)? 1: num;
    while (num > 1) {
        num--, f *= num;
    }
    return f;
}

double fast_pi(void) {
    return 9801.0/(2.0*pow(2.0, 0.5)*sigma(1));
}

double sigma(int n) {
    double result = 0;
    for (int k = 0; k <= n; k++) {
        result += (double) fact(4*k)*(1103+26390*k) / 
                  (pow(fact(k), 4.0)*pow(396.0, 4*k));
    }
    return result;
}
