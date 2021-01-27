#include <iostream>
#include <cmath>
using namespace std;

class TRI
{
private:
    double a, b, c;

public:
    TRI(double x = 1, double y = 1, double z = 1)
    {
        a = x, b = y, c = z;
    }
    double sqroot(double m)
    {
        if (m == 1 || m == 0)
            return m;
        double temp = m / 2;
        while (1)
        {
            double a = temp;
            temp = (temp + m / temp) / 2;
            if (fabs(a - temp) < 1e-6)
            {
                return temp;
            }
        }
    }
    double farea()
    {
        double s = (a + b + c) / 2;
        return sqroot(s * (s - a) * (s - b) * (s - c));
    }
    void print()
    {
        cout << a << '\t' << b << '\t' << c << '\t' << farea() << endl;
    }
};

int main()
{
    TRI san(3, 4, 5);
    san.print();
    system("pause");
    return 0;
}
