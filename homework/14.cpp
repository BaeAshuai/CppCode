#include <iostream>
using namespace std;
#define Pi 3.1415926

class Container
{
protected:
    double x;

public:
    Container(double x) { this->x = x; }
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Cube : public Container
{
public:
    Cube(double x) : Container(x) {}
    double area();
    double volume();
};

class Sphere : public Container
{
public:
    Sphere(double r) : Container(r) {}
    double area();
    double volume();
};

class Cylinder : public Container
{
protected:
    double h;

public:
    Cylinder(double r, double h) : Container(r) { this->h = h; }
    double area();
    double volume();
};

double Cube::area()
{
    return 6 * x * x;
}

double Cube::volume()
{
    return x * x * x;
}

double Sphere::area()
{
    return 4 * Pi * x * x;
}

double Sphere::volume()
{
    return (4 / 3) * Pi * x * x * x;
}

double Cylinder::area()
{
    return Pi * x * x * 2 + 2 * Pi * x * h;
}

double Cylinder::volume()
{
    return Pi * x * x * h;
}

int main()
{
    Cube cu(1);
    cout << cu.area() << endl;
    cout << cu.volume() << endl;
    Sphere sp(1);
    cout << sp.area() << endl;
    cout << sp.volume() << endl;
    Cylinder cy(1, 1);
    cout << cy.area() << endl;
    cout << cy.volume() << endl;
    system("pause");
    return 0;
}
