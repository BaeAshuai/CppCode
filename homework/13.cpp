#include <iostream>
using namespace std;

class STR
{
private:
    char *s;

public:
    STR(char *p = 0);
    friend STR &operator+=(STR &str1, STR &str2);
    void print();
    ~STR();
};

STR::STR(char *p)
{
    s = p;
}

STR &operator+=(STR &str1, STR &str2)
{
    char *p1 = str1.s;
    char *p2 = str2.s;
    while (*p1++ != '\0')
    {
    }
    p1--;
    while (*p2 != '\0')
    {
        *p1++ = *p2++;
    }
    *p1 = '\0';
    return str1;
}

void STR::print()
{
    cout << s << '\n';
}

STR::~STR()
{
}

int main()
{
    char _s1[10] = "abcd";
    char _s2[] = "1234";
    STR s1(_s1);
    STR s2(_s2);
    s1 += s2;
    s1.print();
    system("pause");
    return 0;
}
