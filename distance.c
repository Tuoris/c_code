#include "stdio.h"
#define _USE_MATH_DEFINES
#include "math.h"
#define E_RAD 6371.3 // Avarage Earth radius

typedef struct {
    double latitude; 
    double longitude;} coordinate;

double radians(double angle) {
    return M_PI * (angle / 180);
}

double haversin(double angle) {
    return pow(sin(angle / 2), 2);
}

double get_distance(coordinate a, coordinate b) {
    coordinate radA, radB;
    radA.latitude  = radians(a.latitude), 
    radA.longitude = radians(a.longitude);    
    radB.latitude  = radians(b.latitude), 
    radB.longitude = radians(b.longitude);
    double distance;
    distance = 2 * E_RAD * asin(sqrt(haversin(radB.latitude - radA.latitude) +
               cos(radA.latitude)*cos(radB.latitude)*haversin(radB.longitude - 
               radA.longitude)));
    return distance;
}

int main(int argc, char const *argv[]) {
    coordinate cityA, cityB;
    char units;
    printf("Choose you units of distance \'k\' for kilometes \'m\' for miles\n>>> ");
    scanf("%c", &units);
    printf("Enter a coordinates of first city\n>>> ");
    scanf("%lf %lf", &cityA.latitude, &cityA.longitude);
    printf("Enter a coordinates of second city\n>>> ");
    scanf("%lf %lf", &cityB.latitude, &cityB.longitude);
    double distance = get_distance(cityA, cityB);
    if (units == 'm')
        distance = (1.0 / 1.609344) * distance;
    printf("\nDistance between this cities: %.3f %s.\n", distance,
           (units == 'k')? "kilometes": "miles");
    return 0;
}