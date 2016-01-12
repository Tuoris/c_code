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

double get_distance(coordinate a, coordinate b);
int check(char ch, char * string);
void clear_buffer();

int main(int argc, char const *argv[]) {
    coordinate cityA, cityB;
    
    char units;
    printf("Choose units of distance \'k\' for kilometes \'m\' for miles\n>>> ");
    scanf("%c", &units);
    clear_buffer();
    while(!check(units, "km")) {
        printf("Enter \'k\' or \'m\'\n>>> ");
        scanf("%c", &units);
        clear_buffer();
    }

    printf("Enter a coordinates (latitude and longitude) of first city\n>>> ");
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

double get_distance(coordinate a, coordinate b) {
    coordinate radA, radB;
    radA.latitude  = radians(a.latitude), 
    radA.longitude = radians(a.longitude);    
    radB.latitude  = radians(b.latitude), 
    radB.longitude = radians(b.longitude);

    // Using haversine formula
    double distance;
    distance = 2 * E_RAD * asin(sqrt(haversin(radB.latitude - radA.latitude) + 
               cos(radA.latitude)*cos(radB.latitude)*haversin(radB.longitude - 
               radA.longitude)));
    return distance;
}

int check(char ch, char * string) {
    int index = 0;
    while(string[index]) {
        if (ch == string[index])
            return 1;
        index++;
    }
    return 0;
}

void clear_buffer() {
    char c;
    while((c = getchar()) != '\n');
}