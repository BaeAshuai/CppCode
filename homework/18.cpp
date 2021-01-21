#include <iostream>
using namespace std;

class Modistr
{
private:
    char *str;

public:
    Modistr(char *s)
    {
        str = s;
    }
    void print()
    {
        cout << str << endl;
    }
    void modify(char *wordp)
    {
        char *s = str;
        char *w = wordp;
        int s_len = 0;
        int w_len = 0;
        int index = 0;
        while (*s++ != '\0')
        {
            s_len++;
        }
        while (*w++ != '\0')
        {
            w_len++;
        }
        s = str;
        w = wordp;
        while (*s != '\0')
        {
            index++;
            while (*s == *w && *w != '\0')
            {
                s++;
                w++;
                index++;
            }
            if (*w == '\0')
            {
                s = str + s_len + 1;
                for (int i = s_len; i >= index - 1; i--, s--)
                {
                    char _s = *--s;
                    s++;
                    *s = _s;
                }
                *s = 's';
                s_len++;
            }
            w = wordp;
            s++;
        }
    }
    ~Modistr()
    {
    }
};

int main()
{
    char s[100] = "We are student, you are student, too.";
    char _s[] = "student";
    Modistr mys(s);
    mys.modify(_s);
    mys.print();
    system("pause");
    return 0;
}
