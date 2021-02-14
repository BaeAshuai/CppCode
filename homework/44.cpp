#include <iostream>
#include <string.h>
using namespace std;

class STR
{
    char *p;

public:
    STR(char *s)
    {
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    void move(char &t1, char &t2)
    {
        swap(t1, t2);
    }
    void fun()
    {
        for (int i = 0; i < strlen(p); i++)
        {
            if (p[i] <= '0' || p[i] >= '9')
            {
                int k = i;
                while (p[k - 1] >= '0' && p[k - 1] <= '9')
                {
                    move(p[k], p[k - 1]);
                    k--;
                }
            }
        }
    }
    ~STR()
    {
        delete p;
    }
    void print()
    {
        cout << p << endl;
    }
};

int main()
{
    STR str("11[22A3A3b4b4ccDD]55");
    str.fun();
    str.print();
    system("pause");
    return 0;
}
