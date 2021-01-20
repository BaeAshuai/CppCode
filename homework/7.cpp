#include <iostream>
using namespace std;

class RECT
{
protected:
    double x, y;

public:
    RECT(double x1, double y1);
    virtual double area();
    double peri();
    virtual int isSquare();
};

class CUB : public RECT
{
private:
    double height;

public:
    CUB(double h, double x, double y);
    double volume();
    double area();
    int isSquare();
};

RECT::RECT(double x1, double y1)
{
    x = x1;
    y = y1;
}

double RECT::area()
{
    return x * y;
}

double RECT::peri()
{
    return x * 2 + y * 2;
}

int RECT::isSquare()
{
    return x == y ? 1 : 0;
}

CUB::CUB(double h, double x, double y) : RECT(x, y)
{
    height = h;
}

double CUB::volume()
{
    return x * y * height;
}

double CUB::area()
{
    return RECT::area() * 2 + peri() * height;
}

int CUB::isSquare()
{
    if (RECT::isSquare())
        return x == height ? 1 : 0;
    else
        return 0;
}

int main()
{
    CUB cu(3, 3, 3);
    RECT *re;
    re = &cu;
    cout << "体积为:" << cu.volume() << '\n';
    cout << "表面积为:" << cu.area() << '\n';
    cout << (cu.isSquare() ? "是" : "不是") << "正方体" << '\n';
    system("pause");
    return 0;
}
