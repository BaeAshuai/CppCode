#include <iostream>
using namespace std;

class Array
{
private:
    int x[4][4];
    int count;

public:
    Array(int a[4][4])
    {
        count = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                x[i][j] = a[i][j];
    }
    int fun(int n)
    {
        if (n < 2)
            return 0;
        else
            for (int i = 2; i < n; i++)
                if (n % i == 0)
                    return 0;
        return 1;
    }
    int encode()
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j <= i; j++)
                if (fun(x[i][j]))
                    for (int k = x[i][j] + 1;; k++)
                        if (fun(k))
                        {
                            x[i][j] = k;
                            count++;
                            break;
                        }
    }
    void print()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << x[i][j] << '\t';
            cout << endl;
        }
        cout << "count=" << count << endl;
    }
};

int main()
{
    int a[4][4] = {{3, 6, 4, 17}, {8, 5, 9, 10}, {12, 19, 7, 20}, {4, 14, 21, 23}};
    Array A(a);
    A.print();
    A.encode();
    A.print();
    system("pause");
    return 0;
}
