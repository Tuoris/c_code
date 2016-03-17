#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using std::cout; using std::string;
using std::endl; using std::cin;

inline double radians(double degrees) {
// Convert degrees to radians
    return degrees / 180.0 * M_PI;
}

class Shape {
protected:
    string type;
public:
    Shape() : type("Shape") {};
    string getType(void) {
        return type;
    }
};

class Polygon : public Shape {
public:
    Polygon() {
        type = "Polygon";
    };    
};

class Parallelogram : public Polygon {
protected:
    double sideOne, sideTwo, angle;
public:
    Parallelogram(double a, double b, double phi) {
        type = "Parallelogram";
        sideOne = a;
        sideTwo = b;
        angle = phi;
    }
    double getAngle () {return angle;}
    double calcArea() {
        return sideOne * sideTwo * sin(radians(angle));
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b) : Parallelogram(a, b, 90) {
        type = "Rectangle";
    };
    double calcArea() {
        return sideOne * sideTwo;
    }
};

class Square : public Rectangle {
public:
    Square(double a) : Rectangle(a, a) {
        type = "Square";
    }
};

class Rhomb : public Polygon {
    double diagonalOne, diagonalTwo;
public:
    Rhomb(double d1, double d2) {
        type = "Polygon";
        diagonalOne = d1;
        diagonalTwo = d2;
    }
    double calcArea() {
        return 1.0 / 2 * diagonalOne * diagonalTwo;
    }
};

class Triangle : public Polygon {
protected:
    double side, height;
public:
    Triangle(double a, double ha) {
        type = "Triangle";
        side = a;
        height = ha;
    }
    double calcArea() {
        return 1.0 / 2 * side * height;
    }
};

class EquilateralTriangle : public Triangle {
    static double calcHeight(double side) { 
    // Calculate height of equilateral triangle using formula
        return side * 0.8660 / 2.0; 
    }
public:
    EquilateralTriangle(double a) : Triangle(a, EquilateralTriangle::calcHeight(a)) {
        type = "EquilateralTriangle";
    }
};

class Ellipse : public Shape {
protected:
    double axisOne, axisTwo;
public:
    Ellipse(double a, double b) {
        type = "Ellipse";
        axisOne = a;
        axisTwo = b;  
    }
    double calcArea() {
        return axisOne * axisOne * M_PI;
    }
};

class Circle : public Ellipse {
public:
    Circle(double radius) : Ellipse(radius, radius) {
        type = "Circle";
    }
    double calcLength() {
        return 2 * M_PI * axisOne;
    }
};

std::ostream& operator<< (std::ostream& out, Shape shape) {
    out << shape.getType();
    return out;
}

int main(void) {

    Parallelogram parallelogram(10, 20, 45);
    cout << parallelogram << " area: " << parallelogram.calcArea() << endl;

    EquilateralTriangle eltriangle(20);
    cout << eltriangle << " area: " << eltriangle.calcArea() << endl;

    Ellipse ellipse(20, 10);
    cout << ellipse << " area: " << ellipse.calcArea() << endl;
    
    Circle circle(10);
    cout << circle << " area: " << circle.calcArea() << endl;
    cout << circle << " length: " << circle.calcLength() << endl;

    return 0;
}

