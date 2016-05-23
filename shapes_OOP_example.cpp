// Variant 21
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

using std::cout; using std::string;
using std::endl; using std::cin;

typedef struct {
    int red;
    int green;
    int blue;
} color;

typedef struct {
    double x;
    double y;
} point;

// Convert degrees to radians
inline double radians(double degrees) {
    return degrees / 180.0 * M_PI;
}

class Shape {
  protected:
    point center;
    color strokeColor;
  public:
    Shape(point center, color strokeColor) : center(center), strokeColor(strokeColor) {};
    void move(point to) {
        center = to;
    }
    virtual void draw() {};
    virtual double perimeter() {};
    virtual void rotate(int degree) {
        cout << "Rotating basic shape for " << degree << "degrees." << endl;
    };
};

class Polygon : public Shape {
  public:
    Polygon(point center, color strokeColor) : Shape(center, strokeColor) {};
    virtual void draw() {};
    virtual double area() {};
    virtual void rotate(int degree) {
        cout << "Rotating basic polygon for " << degree << "degrees." << endl;
    };
};

class Parallelogram : public Polygon {
  protected:
    double a, b, angle;
  public:
    Parallelogram(point center, color strokeColor, double argA,
                  double argB, double argAngle) : Polygon(center, strokeColor) {
        a = argA;
        b = argB;
        angle = argAngle;
    };
    virtual void draw() {
        cout << "Drawing parallelogram at " << center.x << ":" << center.y << " with color: #" << 
        strokeColor.red << strokeColor.green << strokeColor.blue << endl;
    };
    virtual void rotate(int degree) {
        cout << "Rotating parallelogram for " << degree << "degrees." << endl;
    };
    virtual double area() {
        return a * b * cos(radians(angle));
    }
    double perimeter() {
        return a * b;
    }
};

class Rectangle : public Parallelogram {
  public:
    Rectangle(point center, color strokeColor, double argA,
              double argB) : Parallelogram(center, strokeColor,  argA, argB, 90.0) {};
    virtual void rotate(int degree) {
        cout << "Rotating rectangle for " << degree << "degrees." << endl;
    };
    virtual void draw() {
        cout << "Drawing rectangle at " << center.x << ":" << center.y << " with color: #" << 
        strokeColor.red << strokeColor.green << strokeColor.blue << endl;
    };
    double area() {
        return a * b;
    }
};

class Square : public Rectangle {
  public:
    Square(point center, color strokeColor, double argA) : Rectangle(center,
                strokeColor,  argA, argA) {};
    void draw() {
        cout << "Drawing square at " << center.x << ":" << center.y << " with color: #" << 
        strokeColor.red << strokeColor.green << strokeColor.blue << endl;
    };
};

class Triangle : public Polygon {
  protected:
    double sideA, sideB, sideC;
  public:
    Triangle(point center, color strokeColor,
             double argSideA, double argSideB, double argSideC) : Polygon(center, strokeColor) {
        sideA = argSideA;
        sideB = argSideB;
        sideC = argSideC;
    };
    double perimeter() {
        return sideA * sideB * sideC;
    }
    void rotate(int degree) {
        cout << "Rotating triangle for " << degree << "degrees." << endl;
    };
    virtual void draw() {
        cout << "Drawing triangle at " << center.x << ":" << center.y << " with color: #" << 
        strokeColor.red << strokeColor.green << strokeColor.blue << endl;
    };
};

class EquilateralTriangle : public Triangle {
  public:
    EquilateralTriangle(point center, color strokeColor,
                        double side) : Triangle(center, strokeColor, side, side, side) {};
};

class Rhomb : public Polygon {
    double diagonalA, diagonalB;
  public:
    Rhomb(point center, color strokeColor, double argA,
          double argB) : Polygon(center, strokeColor) {
        diagonalA = argA;
        diagonalB = argB;
    }
    double area() {
        return diagonalA * diagonalB;
    }
    void draw() {
        cout << "Drawing rhomb at " << center.x << ":" << center.y << " with color: #" << 
        strokeColor.red << strokeColor.green << strokeColor.blue << endl;
    }
};

class Ellipse : public Shape {
  protected:
    double axisA, axisB;
  public:
    Ellipse(point center, color strokeColor, double argA, double argB) : Shape(center, strokeColor) {
        axisA = argA;
        axisB = argB;
    };
    virtual void draw() {
        cout << "Drawing ellipse at " << center.x << ":" << center.y << " with color: #" << 
        strokeColor.red << strokeColor.green << strokeColor.blue << endl;
    };
    void rotate(int degree) {
        cout << "Rotating ellipse for " << degree << "degrees." << endl;
    };
    double perimeter() {
        return M_PI * axisA * axisB;
    }
};

class Circle : public Ellipse {
  public:
    Circle(point center, color strokeColor, double radius) : Ellipse(center, strokeColor, radius, radius) {};
};

void Draw(Shape *shape) {
    shape->draw();
}

double CalcPerimeter(Shape *shape) {
    return shape->perimeter();
}

int main(void) {
    Parallelogram parallelogram((point) {100, 20}, (color) {23, 0, 0}, 34, 35, 45);
    Circle circle((point) {30, -20}, (color) {255, 0, 0}, 10);
    Shape *shapeArray[] = {&parallelogram, &circle};
    for (int i = 0; i < 2; i++) {
        cout << "Perimeter of shape: " << CalcPerimeter(shapeArray[i]) << endl;
    }
    cout << endl;
    Rectangle rectangle((point) {50, 13}, (color) {255, 34, 0}, 11, 35);
    Square square((point) {45, 77}, (color) {0, 0, 12}, 34);
    Triangle triangle((point) {0, 15}, (color) {14, 100, 12}, 12, 45, 3);
    Polygon *parArray[] = {&parallelogram, &square, &rectangle, &triangle};
    for (int i = 0; i < 4; i++) {
        Draw(parArray[i]);
    }
    cout << endl;
    Shape *allShapes[] = {&parallelogram, &rectangle, &square, &circle};
    for (int i = 0; i < 4; i++) {
        allShapes[i]->rotate(15 * i + 3);
    }
}