#include <iostream>
using namespace std;

const int m = 3;
const int k = 4;
const int n = 3;

class SUM
{
private:
    int A[m][k];
    int B[k][n];
    int (*C)[n];

public:
    SUM(int a[m][k], int b[k][n])
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < k; j++)
                A[i][j] = a[i][j];
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = b[i][j];
        C = new int[m][n]();
    }
    ~SUM()
    {
        delete C;
    }
    void process()
    {
        int s = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s = 0;
                for (int x = 0; x < k; x++)
                    s += A[i][x] * B[x][j];
                C[i][j] = s;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
                cout << A[i][j] << '\t';
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                cout << B[i][j] << '\t';
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << C[i][j] << '\t';
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    int x = 1;
    int a[m][k];
    int b[k][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            a[i][j] = x++;
    x = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = x++;
    SUM test(a, b);
    test.process();
    test.print();
    system("pause");
    return 0;
}