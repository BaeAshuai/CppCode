#include <iostream>
#include <cmath>
using namespace std;

class TRI
{
private:
    double x, y, z;

public:
    TRI(double x1, double y1, double z1)
    {
        if (x1 + y1 > z1 && x1 + z1 > y1 && y1 + z1 > x1)
        {
            x = x1;
            y = y1;
            z = z1;
        }
        else
        {
            cout << "不能构成三角形" << endl;
            system("pause");
            exit(0);
        }
    }
    virtual double area()
    {
        double s = (x + y + z) / 2;
        return sqrt((s - x) * (s - y) * (s - z) * s);
    };
    double peri()
    {
        return x + y + z;
    }
};

class COL : public TRI
{
private:
    double height;

public:
    COL(double x1, double y1, double z1, double h) : TRI(x1, y1, z1)
    {
        height = h;
    }
    double volume()
    {
        return TRI::area() * height;
    }
    double area()
    {
        return 2 * TRI::area() + peri() * height;
    }
};

int main()
{
    COL co(3, 4, 5, 1);
    TRI *tr = &co;
    cout << co.volume() << endl;
    cout << tr->area() << endl;
    system("pause");
    return 0;
}
