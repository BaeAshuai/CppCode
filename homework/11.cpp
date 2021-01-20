#include <iostream>
using namespace std;

class String_Integer
{
private:
    char *s;

public:
    String_Integer(char *str);
    operator int();
    void show();
    ~String_Integer();
};

String_Integer::String_Integer(char *str)
{
    s = str;
}

String_Integer::operator int()
{
    int res = 0;
    char *_s = s;
    while (*_s++ != '\0')
    {
        if (*_s >= '0' && *_s <= '9')
            res = res * 10 + (*_s - '0');
    }
    return res;
}

String_Integer::~String_Integer()
{
    delete s;
}

void String_Integer::show()
{
    cout << s << endl;
}

int main()
{
    char s[100];
    cout << "�������ַ���";
    cin.getline(s, 100);
    String_Integer test(s);
    cout << "������ַ���Ϊ";
    test.show();
    cout << "ת���õ�������Ϊ" << int(test) << endl;
    system("pause");
    return 0;
}
