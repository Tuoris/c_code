#include "stdio.h"
#include "math.h"

double leibniz_pi(int);
double nilakantha_pi(int);
double fast_pi(int);
double sigma(int);
void super_pi(int);
int fact(int);
void show_rule(void) {
    printf("Enter how many numbers of pi you "
           "want to see or \'q\' to exit\n>>> ");
}

int main(void) {
    printf("Gregory-Leibniz series:\t\t%.10f\n", leibniz_pi(100000));
    printf("Nilakantha series\t\t%.10f\n", nilakantha_pi(500));
    printf("Pi by Srinivasa Ramanujan\t%.10f\n", fast_pi(5));
    show_rule();
    int user_input;
    while(scanf("%d", &user_input) == 1) {
        super_pi(user_input);
        char ch;
        while((ch = getchar()) != '\n');
        show_rule();
    }
    return 0;
}

double leibniz_pi(int n) {
    // 14th Madhava of Sangamagrama
    // Slowly coverges to pi 
    // 100000 iterations gives pi correct to 4 decimal places
    double pi = 0.0;
    for (int it = 0; it < n; it++) {
        pi += (it % 2? -1.0: 1.0)/(2 * it + 1);
    }
    return pi*4;
}

double nilakantha_pi(int n) {
    // 15th Nilakantha Somayaji
    // Move to pi faster then Leibniz series
    // But there is a bug and I don't know where
    double pi = 3.0;
    for (long it = 1; it < n; it++) {
        pi += (it % 2? 1.0: -1.0)* 4.0 /((2 * it)*(2 * it + 1)*(2 * it + 2));
    }
    return pi;
}

double fast_pi(int n) {
    // 1914 Srinivasa Ramanujan
    // Very fast but have limitations with c types
    // Calculates only 18 digits after point
    return 9801.0/(2.0*pow(2.0, 0.5)*sigma(n));
}
double sigma(int n) {
    double result = 0;
    for (int k = 0; k <= n; k++) {
        result += (double) fact(4*k)*(1103+26390*k) / 
                  (pow(fact(k), 4.0)*pow(396.0, 4*k));
    }
    return result;
}

void super_pi(int n) {
    // TODO correct precision
    n = (n > 1000)? 1000: n;
    char pi [] = "3.14159265358979323846264338327950288419716939937510" 
    "58209749445923078164062862089986280348253421170679821480865132823"
    "06647093844609550582231725359408128481117450284102701938521105559"
    "64462294895493038196442881097566593344612847564823378678316527120"
    "19091456485669234603486104543266482133936072602491412737245870066"
    "06315588174881520920962829254091715364367892590360011330530548820"
    "46652138414695194151160943305727036575959195309218611738193261179"
    "31051185480744623799627495673518857527248912279381830119491298336"
    "73362440656643086021394946395224737190702179860943702770539217176"
    "29317675238467481846766940513200056812714526356082778577134275778"
    "96091736371787214684409012249534301465495853710507922796892589235"
    "42019956112129021960864034418159813629774771309960518707211349999"
    "99837297804995105973173281609631859502445945534690830264252230825"
    "33446850352619311881710100031378387528865875332083814206171776691"
    "47303598253490428755468731159562863882353787593751957781857780532"
    "1712268066130019278766111959092164201989";
    for (int i = 0; i < n + 2; i++) {
        putchar(pi[i]);
    }
    puts("");
}

int fact(int num) {
    int f = (num == 0)? 1: num;
    while (num > 1) {
        num--, f *= num;
    }
    return f;
}