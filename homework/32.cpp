#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *str;
    int y;

public:
    String(char *s)
    {
        str = new char[strlen(s) + 1]();
        strcpy(str, s);
        y = 0;
    }
    void huiwen()
    {
        char *left = str;
        char *right = str + strlen(str) - 1;
        for (int i = 0; i < strlen(str) / 2; i++)
        {
            if (*left++ != *right--)
            {
                y = 0;
                return;
            }
        }
        y = 1;
    }
    void show()
    {
        cout << str << '\t';
        cout << (y ? "是" : "不是") << "回文字符串" << endl;
    }
};

int main()
{
    char s[] = "ababcedbaba";
    String test(s);
    test.huiwen();
    test.show();
    system("pause");
    return 0;
}
