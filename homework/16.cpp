#include <iostream>
using namespace std;

class Array
{
private:
    int *p;
    int n;

public:
    Array(int *ptr, int len)
    {
        p = ptr;
        n = len;
    }
    Array(const Array &a)
    {
        p = a.p;
        n = a.n;
    }
    Array &operator++()
    {
        int *_p = p;
        for (int i = 0; i < n; i++)
        {
            (*_p)++;
            _p++;
        }
        return *this;
    }
    const Array operator++(int)
    {
        Array tmp = *this;
        ++(*this);
        return tmp;
    }
    friend Array &operator--(Array &a)
    {
        int *_p = a.p;
        for (int i = 0; i < a.n; i++)
        {
            (*_p)--;
            _p++;
        }
        return a;
    }
    friend const Array operator--(Array &a, int)
    {
        Array tmp = a;
        --a;
        return tmp;
    }
    void print()
    {
        int *_p = p;
        for (int i = 0; i < n; i++)
        {
            cout << *_p++ << '\t';
        }
        cout << endl;
    }
    ~Array()
    {
        delete p;
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    Array array(a, 7);
    ++array;
    array.print();
    array++;
    array.print();
    --array;
    array.print();
    array--;
    array.print();
    system("pause");
    return 0;
}
