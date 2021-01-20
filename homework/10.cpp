#include <iostream>
using namespace std;
const int M = 3;

class Array
{
private:
    int b[M][M];

public:
    Array(int (*p)[M]);
    void operator+();
    friend void operator-(Array &b);
    void print();
};

Array::Array(int (*p)[M])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            b[i][j] = (*p)[j];
        }
        p++;
    }
}

void Array::operator+()
{
    int a[M][M];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = b[M - 1 - j][i];
        }
    }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            b[i][j] = a[i][j];
}

void operator-(Array &b)
{
    int a[M][M];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            a[i][j] = b.b[j][M - 1 - i];
        }
    }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            b.b[i][j] = a[i][j];
}

void Array::print()
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            cout << b[i][j] << '\t';
        cout << '\n';
    }
    cout << endl;
}

int main()
{
    int k = 1;
    int a[M][M];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = k++;
    //int(*p)[M] = a;
    Array array(a);
    array.print();
    +array;
    array.print();
    -array;
    array.print();
    system("pause");
    return 0;
}
