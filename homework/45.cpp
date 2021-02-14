#include <iostream>
using namespace std;

class SIN
{
    double x;
    int n;

public:
    SIN(double x, int n)
    {
        this->x = x;
        this->n = n;
    }
    int power(int q)
    {
        int r = 1;
        for (int i = 1; i <= q; i++)
            r *= i;
        return r;
    }
    double mi(double m, int n)
    {
        double r = 1;
        for (int i = 0; i < n; i++)
            r *= m;
        return r;
    }
    double fun()
    {
        double r = 0;
        for (int i = 1; i <= n; i++)
        {
            double s = mi(x, 2 * i - 1);
            double x = power(2 * i - 1);
            double d = mi(-1, i + 1) * s / x;
            r += d;
        }
        return r;
    }
    void show()
    {
        cout << "sin(" << x << ")=" << fun() << endl;
    }
};

int main()
{
    SIN test(3.1415926/6, 9);
    test.show();
    system("pause");
    return 0;
}
