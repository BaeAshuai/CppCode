#include <iostream>
using namespace std;

class Array
{
private:
    int *p, k;
    float *s;

public:
    Array(int *ptr, int n);
    int fun(int n);
    void sum();
    void show();
    ~Array();
};

Array::Array(int *ptr, int n)
{
    p = ptr;
    float _s = 0;
    s = &_s;
    k = n;
}

int Array::fun(int n)
{
    if (n < 2)
        return 0;
    else
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                return 0;
    return 1;
}

void Array::sum()
{
    int *_p = p;
    float _s = 0;
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        if (fun(*_p))
        {
            _s += *_p;
            count++;
        }
        _p++;
    }
    _s /= count;
    *s = _s;
}

void Array::show()
{
    int *_p = p;
    for (int i = 0, x = 1; i < k; i++, x++)
    {
        cout << *_p++ << '\t';
        if (x % 5 == 0)
            cout << '\n';
    }
    cout << '\n';
    cout << *s << '\n';
}

Array::~Array()
{
    delete p;
}

int main()
{
    int ptr[] = {5, 2, 7, 4, 8, 23, 65, 1, 40};
    int *p = ptr;
    Array array(p, 9);
    array.sum();
    array.show();
    system("pause");
    return 0;
}
