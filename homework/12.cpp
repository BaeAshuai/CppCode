#include <iostream>
using namespace std;

class SET
{
private:
    int *a;
    int len;

public:
    SET(int *p, int n);
    int operator==(int m);
    friend int operator==(SET &s1, SET &s2);
    void print();
    ~SET();
};

SET::SET(int *p, int n)
{
    a = p;
    len = n;
}

int SET::operator==(int m)
{
    for (int i = 0; i < len; i++)
        if (*a++ == m)
            return 1;
    return 0;
}

int operator==(SET &s1, SET &s2)
{
    bool exists = false;
    int *p1 = s1.a;
    int *p2 = s2.a;
    if (s1.len == s2.len)
    {
        for (int i = 0; i < s1.len; i++)
        {
            p2 = s2.a;
            exists = false;
            for (int j = 0; j < s1.len; j++)
            {
                if (*p1 == *p2++)
                {
                    exists = true;
                    break;
                }
            }
            if (!exists)
                return 0;
            p1++;
        }
        return 1;
    }
    else
        return 0;
}

void SET::print()
{
    for (int i = 0; i < len; i++)
    {
        cout << *a++ << '\t';
    }
    cout << '\n';
}

SET::~SET()
{
    delete a;
}

int main()
{
    int _a[] = {1, 2, 3, 4, 5};
    int _b[] = {1, 2, 3, 4, 5};
    int _c[] = {1, 2, 3, 4, 5, 6};
    int _d[] = {1, 3, 5, 7, 9};
    SET a(_a, 5);
    SET b(_b, 5);
    SET c(_c, 6);
    SET d(_d, 5);
    cout << "a和b" << (a == b ? "相等" : "不相等") << '\n';
    cout << "a和c" << (a == c ? "相等" : "不相等") << '\n';
    cout << "a和d" << (a == d ? "相等" : "不相等") << '\n';
    system("pause");
    return 0;
}
