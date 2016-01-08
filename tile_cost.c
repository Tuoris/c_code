#include "stdio.h"

double ceil(double number) {
    // Didn't want include math.h
    int integer_part = (int) number;
    return (double) integer_part + (number > integer_part);
}

int main(void) {
    // Mostly used tile size in m ~ 12"x12"
    double tile_width = 0.3, 
           tile_height = 0.3;
    double width, height, tile_cost, total;
    printf("Enter width and height of floor in m\n>>> ");
    scanf("%lf %lf", &width, &height);
    printf("Enter the cost of 1m2 of tile\n>>> ");
    scanf("%lf", &tile_cost);
    // one tile have area of 10cm2
    tile_cost = tile_cost/100;
    total = ceil(width/tile_width) * ceil(height/tile_height) * tile_cost;
    printf("Total: %.2f$\n", total);
    return 0;
}