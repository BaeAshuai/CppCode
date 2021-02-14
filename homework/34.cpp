#include <iostream>
using namespace std;

class MATRIX
{
private:
    int a[20][20] = {0};
    int startnum;
    int n;

public:
    MATRIX(int s, int m)
    {
        startnum = s;
        n = m;
    }
    void process()
    {
        int k = startnum;
        int cen = 0;
        if (n % 2 == 0)
            cen = n / 2;
        else
        {
            cen = (n + 1) / 2 - 1;
        }
        for (int i = 0; i < cen; i++)
        {
            for (int j = i; j < n - (2 * i) - 1 + i; j++)
            {
                a[i][j] = k++;
            }
            for (int j = 0; j < n - (2 * i) - 1; j++)
            {
                a[i + j][n - i - 1] = k++;
            }

            for (int j = 0; j < n - (2 * i) - 1; j++)
            {
                a[n - i - 1][n - j - i - 1] = k++;
            }
            for (int j = 0; j < n - (2 * i) - 1; j++)
            {
                a[n - j - i - 1][i] = k++;
            }
        }
        if (n % 2 != 0)
        {
            a[(n - 1) / 2][(n - 1) / 2] = k;
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << '\t';
            cout << endl;
        }
    }
};

int main()
{
    MATRIX t(1, 5);
    t.process();
    t.print();
    system("pause");
    return 0;
}
