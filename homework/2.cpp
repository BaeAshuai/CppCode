#include <iostream>
using namespace std;

class ARRAY
{
private:
    float a[10], b[10];

public:
    ARRAY(float t[10]);
    void process();
    void print();
};

ARRAY::ARRAY(float t[10])
{
    for (int i = 0; i < 10; i++)
        a[i] = t[i];
}

void ARRAY::process()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
            b[i] = (a[0] + a[1] + a[9]) / 3;
        else if (i == 9)
            b[i] = (a[0] + a[8] + a[9]) / 3;
        else
            b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
    }
}

void ARRAY::print()
{
    for (int i = 0; i < 10; i++)
        cout << a[i] << '\t';
    cout << '\n';
    for (int i = 0; i < 10; i++)
        cout << b[i] << '\t';
    cout << '\n';
}

int main()
{
    float a[10] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27};
    ARRAY array(a);
    array.process();
    array.print();
    system("pause");
    return 0;
}
