#include <iostream>
using namespace std;

class ARR
{
private:
    int n;
    int a[100];

public:
    ARR(int x[], int size);
    void change();
    void show();
};

ARR::ARR(int x[], int size)
{
    n = size;
    for (int i = 0; i < size; i++)
    {
        a[i] = x[i];
    }
}

void ARR::change()
{
    int l;
    int r;
    for (int x = 0; x < n / 2; x++)
    {
        for (int i = 0; i <= n / 2; i++)
        {
            if (a[i] >= 0)
            {
                l = i;
                break;
            }
        }
        for (int i = n - 1; i > n / 2; i--)
        {
            if (a[i] <= 0)
            {
                r = i;
                break;
            }
        }
        swap(a[l], a[r]);
    }
}

void ARR::show()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
    cout << '\n';
}

int main()
{
    int b[10] = {1, -3, -1, 3, 2, 4, -4, 5, -5, -2};
    ARR v(b, 10);
    v.show();
    v.change();
    v.show();
    system("pause");
    return 0;
}
