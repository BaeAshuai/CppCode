#include <iostream>
using namespace std;

class SUM
{
private:
    int array[5][5];
    int s;
    int a;
    int b, m, n;

public:
    SUM(int d[5][5])
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                array[i][j] = d[i][j];
        s = 0;
        a = 1;
        b = array[0][0];
        m = 0;
        n = 0;
    }
    void process1()
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (i == j || i == (4 - j))
                    s += array[i][j];
    }
    void process2()
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (i == j || i == (4 - j))
                    if (i % 2 == 0 && j % 2 == 0)
                        a *= array[i][j];
    }
    void process3()
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (i == j || i == (4 - j))
                    if (array[i][j] > b)
                    {
                        b = array[i][j];
                        m = i;
                        n = j;
                    }
    }
    void print()
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                cout << array[i][j] << '\t';
            cout << endl;
        }
        cout << "s=" << s << endl;
        cout << "a=" << a << endl;
        cout << "b=" << b << " ×ø±êÎª:"
             << "(" << m << "," << n << ")" << endl;
    }
};

int main()
{
    int a[5][5];
    int k = 1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = k++;
    SUM test(a);
    test.process1();
    test.process2();
    test.process3();
    test.print();
    system("pause");
    return 0;
}
