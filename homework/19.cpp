#include <iostream>
using namespace std;

class STR
{
private:
    char *s;
    int yn;

public:
    STR(char *t)
    {
        s = t;
        char *p = s;
        yn = 1;
        if (*p != '_' && !alph(*p))
            yn = 0, p++;
        else
            while (*p != '\0')
            {
                if (!alph(*p) && !num(*p) && *p != '_')
                    yn = 0;
                p++;
            }
    }
    ~STR()
    {
        delete s;
    }
    int alph(char c)
    {
        if (c >= 'A' && c <= 'z')
            return 1;
        else
            return 0;
    }
    int num(char c)
    {
        if (c >= '0' && c <= '9')
            return 1;
        else
            return 0;
    }
    void print()
    {
        cout << s << (yn ? " 是" : " 不是") << "一个合法的标识符！" << endl;
    }
};

int main()
{
    STR s1("4abc1");
    STR s2("ab c");
    STR s3("_123");
    STR s4("$abc");
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    system("pause");
    return 0;
}
