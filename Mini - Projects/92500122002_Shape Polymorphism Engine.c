#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    virtual void area() = 0;
    virtual void perimeter() = 0;
};

// Circle class
class Circle : public Shape {
    float r;
public:
    void getData() {
        cout << "Enter radius of circle: ";
        cin >> r;
    }

    void area() {
        cout << "Circle Area: " << 3.14 * r * r << endl;
    }

    void perimeter() {
        cout << "Circle Perimeter: " << 2 * 3.14 * r << endl;
    }
};

// Rectangle class
class Rectangle : public Shape {
    float l, b;
public:
    void getData() {
        cout << "Enter length and breadth of rectangle: ";
        cin >> l >> b;
    }

    void area() {
        cout << "Rectangle Area: " << l * b << endl;
    }

    void perimeter() {
        cout << "Rectangle Perimeter: " << 2 * (l + b) << endl;
    }
};

int main() {
    Shape *s;   // pointer to base class

    Circle c;
    Rectangle r;

    // Circle
    c.getData();
    s = &c;
    s->area();
    s->perimeter();

    cout << endl;

    // Rectangle
    r.getData();
    s = &r;
    s->area();
    s->perimeter();

    return 0;
}
