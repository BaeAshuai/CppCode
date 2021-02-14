#include <iostream>
using namespace std;

class PP
{
    int n;
    double x;
    double *p;

public:
    PP(int num, double x1)
    {
        n = num;
        x = x1;
        p = new double[n]();
    }
    ~PP()
    {
        delete p;
    }
    double fun(int n1, double x)
    {
        if (n1 == 0)
            return 1;
        else if (n1 == 1)
            return x;
        else if (n1 > 1)
        {
            return ((2 * n1 - 1) * x * fun(n1 - 1, x) - (n1 - 1) * fun(n1 - 2, x)) / n1;
        }
    }
    void process()
    {
        double *_p = p;
        for (int i = 0; i < n; i++)
            *_p++ = fun(i, x);
    }
    void show()
    {
        cout << "n=" << n << '\t' << "x=" << x << endl;
        double *_p = p;
        for (int i = 0; i < n; i++)
        {
            cout << *_p++ << '\t';
            if ((i+1) % 4 == 0)
                cout << endl;
        }
    }
};

int main()
{
    int num;
    cin >> num;
    double x1;
    cin >> x1;
    PP items(num, x1);
    items.process();
    items.show();
    system("pause");
    return 0;
}
