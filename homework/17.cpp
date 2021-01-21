#include <iostream>
using namespace std;

class Array
{
private:
    int a[3];

public:
    Array() {}
    Array(int b[3])
    {
        for (int i = 0; i < 3; i++)
            a[i] = b[i];
    }
    Array operator^(Array &b)
    {
        Array t;
        for (int i = 0; i < 3; i++)
            t.a[i] = a[i] * b.a[i];
        return t;
    }

    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << a[i] << '\t';
        }
    }
};

int main()
{
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    Array t1(a);
    Array t2(b);
    Array t3;
    t3 = t1 ^ t2;
    t3.print();
    system("pause");
    return 0;
}
