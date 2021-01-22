#include <iostream>
using namespace std;

class NUM
{
private:
    int a[5];

public:
    NUM(int t[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = t[i];
        }
    }
    void sort(int t[], int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (t[j] > t[j + 1])
                    swap(t[j], t[j + 1]);
    }
    int convert(int n)
    {
        int _n = n;
        int len = 0;
        while (_n)
        {
            len++;
            _n /= 10;
        }
        _n = n;
        int s[len] = {0};
        for (int i = len - 1; i >= 0; i--)
            s[i] = _n % 10, _n /= 10;
        int _s[len] = {0};
        int c = 0;
        bool exists = false;
        for (int i = 0; i < len; i++)
        {
            exists = false;
            for (int j = 0; j < i; j++)
                if (s[i] == _s[j])
                    exists = true;
            if (!exists)
                _s[c++] = s[i];
        }
        int res = 0;
        for (int i = 0; i < c; i++)
            res = res * 10 + _s[i];
        return res;
    }
    int fun()
    {
        for (int i = 0; i < 5; i++)
            a[i] = convert(a[i]);
        sort(a, 5);
        return 0;
    }
    void print()
    {
        for (int i = 0; i < 5; i++)
            cout << a[i] << '\t';
    }
};

int main()
{
    int a[5] = {0};
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    NUM n(a, 5);
    n.fun();
    n.print();
    system("pause");
    return 0;
}