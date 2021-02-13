#include <iostream>
#include <string.h>
using namespace std;

class STR
{
private:
    char *s;

public:
    STR(char *t)
    {
        s = new char[strlen(t) + 1]();
        strcpy(s, t);
    }
    void backward(char *t1, char *t2)
    {
        char *p1 = t1, *p2 = t2;
        if (p1 < p2)
        {
            char *newstr = new char[p2 - p1 + 2](), *_n = newstr;
            for (int i = 0; i < t2 - t1 + 1; i++)
            {
                *_n++ = *p2--;
            }
            *_n = '\0';
            _n = newstr;
            for (int i = 0; i < t2 - t1 + 1; i++)
            {
                *p1++ = *_n++;
            }
        }
    }
    void fun()
    {
        char *fp = s;
        char *sp = s;
        while (*sp != '\0')
        {
            if ((*sp >= 'a' && *sp <= 'z') || (*sp >= 'A' && *sp <= 'Z'))
            {
                sp++;
            }
            else
            {
                sp--;
                backward(fp, sp);
                sp += 2;
                fp = sp;
            }
        }
    }
    void print()
    {
        cout << s;
    }
    ~STR()
    {
        delete s;
    }
};

int main()
{
    char s[] = "I ma a tneduts!";
    cout << "原字符串:" << s << '\n';
    STR test(s);
    test.fun();
    cout << "处理后的字符串:";
    test.print();
    cout << '\n';
    system("pause");
    return 0;
}
