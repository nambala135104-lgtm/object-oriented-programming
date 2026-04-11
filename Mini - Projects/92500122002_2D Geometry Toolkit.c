
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    int x, y;

public:

    // Constructor
    Point(int a=0, int b=0)
    {
        x = a;
        y = b;
    }

    // Addition
    Point operator+(Point p)
    {
        return Point(x + p.x, y + p.y);
    }

    // Subtraction
    Point operator-(Point p)
    {
        return Point(x - p.x, y - p.y);
    }

    // Multiplication (Scaling)
    Point operator*(int k)
    {
        return Point(x * k, y * k);
    }

    // Division (Scaling down)
    Point operator/(int k)
    {
        return Point(x / k, y / k);
    }

    // Unary operator
    Point operator++()
    {
        x++;
        y++;
        return *this;
    }

    // Distance between two points
    double distance(Point p)
    {
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }

    void display()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

int main()
{
    int x1,y1,x2,y2;
    Point p1,p2,p3;

    cout<<"Enter x and y for Point1: ";
    cin>>x1>>y1;

    cout<<"Enter x and y for Point2: ";
    cin>>x2>>y2;

    // Assign user values to objects
    p1 = Point(x1,y1);
    p2 = Point(x2,y2);

    cout<<"Point1: ";
    p1.display();

    cout<<"Point2: ";
    p2.display();

    p3 = p1 + p2;
    cout<<"Addition: ";
    p3.display();

    p3 = p1 - p2;
    cout<<"Subtraction: ";
    p3.display();

    p3 = p1 * 2;
    cout<<"Multiplication: ";
    p3.display();

    p3 = p2 / 2;
    cout<<"Division: ";
    p3.display();

    ++p1;
    cout<<"After Increment: ";
    p1.display();

    cout<<"Distance: "<<p1.distance(p2);

    return 0;
}
