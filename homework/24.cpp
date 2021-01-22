#include <iostream>
using namespace std;

class ARRAY
{
private:
    int a[5];
    int n;

public:
    ARRAY(int t[], int n1)
    {
        for (int i = 0; i < n1; i++)
            a[i] = t[i];
        n = n1;
    }
    int num(int n)
    {
        int _n = n;
        int len = 0;
        while (_n)
        {
            len++;
            _n /= 10;
        }
        int s[len];
        for (int i = len - 1; i >= 0; i--)
        {
            s[i] = n % 10;
            n /= 10;
        }
        int res = 0;
        for (int i = 1; i < len; i++)
            res = res * 10 + s[i];
        return res;
    }
    void fun()
    {
        int min = a[0];
        int index = 0;
        for (int i = 0; i < n - 1; i++)
        {
            min = num(a[i]);
            index = i;
            for (int j = i + 1; j < n; j++)
                if (num(a[j]) < min)
                    min = num(a[j]), index = j;
            if (i != index)
                swap(a[i], a[index]);
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << '\t';
        cout << endl;
    }
};

int main()
{
    int a[5] = {134, 445, 423, 233, 811};
    ARRAY array(a, 5);
    array.fun();
    array.print();
    system("pause");
    return 0;
}
