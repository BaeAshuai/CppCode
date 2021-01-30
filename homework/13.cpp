#include <iostream>
#include <cstring>
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
    char *p = new char[strlen(str1.s) + strlen(str2.s) + 1];
    strcpy(p, str1.s);
    strcpy(p + strlen(str1.s), str2.s);
    str1.s = p;
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
    char _s1[] = "abcd";
    char _s2[] = "1234";
    STR s1(_s1);
    STR s2(_s2);
    s1 += s2;
    s1.print();
    system("pause");
    return 0;
}
