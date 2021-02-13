#include <iostream>
#include <string.h>
using namespace std;

class Str
{
private:
    char s[100];
    int b[20];
    int ss;
    int count;

public:
    Str(char *p = 0)
    {
        char *_s = p;
        int i = 0;
        for (i = 0; i < strlen(p); i++)
        {
            s[i] = *_s++;
        }
        s[i] = '\0';
        ss = 0;
        count = 0;
    }
    int pre(int n)
    {
        if (n < 2)
            return 0;
        else
        {
            for (int i = 2; i < n; i++)
                if (n % i == 0)
                    return 0;
            return 1;
        }
    }
    void SUM()
    {
        int num = 0;
        for (int i = 0; i < 100; i++)
        {
            if (s[i] > '0' && s[i] < '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (num != 0)
            {
                b[count] = num;
                count++;
                if (pre(num))
                    ss += num;
                num = 0;
            }
        }
    }
    void show()
    {
        for (int i = 0;; i++)
        {
            if (s[i] != '\0')
            {
                cout << s[i];
            }
            else
            {
                break;
            }
        }
        cout << '\n';
        for (int i = 0; i < count; i++)
        {
            cout << b[i] << '\t';
        }
        cout << '\n';
        cout << ss << '\n';
    }
};

int main()
{
    char s[] = "1ad34be5c67dw11egg77fuy5";
    Str test(s);
    test.SUM();
    test.show();
    system("pause");
    return 0;
}
