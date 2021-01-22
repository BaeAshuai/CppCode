#include <iostream>
using namespace std;

class Fract
{
private:
    int num, den;

public:
    Fract(int a = 0, int b = 1);
    int ged(int m, int n);
    Fract add(Fract f);
    void show();
};

Fract::Fract(int a, int b)
{
    num = a;
    den = b;
}

int Fract::ged(int m, int n)
{
    int min = m < n ? m : n;
    while (1)
    {
        if (m % min == 0 && n % min == 0)
            return min;
        else
            min--;
    }
}

Fract Fract::add(Fract f)
{
    int _den = den * f.den / ged(den, f.den);
    int num1 = num * _den / den;
    int num2 = f.num * +_den / f.den;
    int _num = num1 + num2;
    int b = ged(_num, _den);
    Fract res(_num / b, _den / b);
    return res;
}

void Fract::show()
{
    cout << num << '/' << den;
}

int main()
{
    Fract f1(1, 5), f2(7, 20);
    Fract f3 = f1.add(f2);
    f3.show();
    system("pause");
    return 0;
}
