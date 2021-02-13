#include <iostream>
#include <string.h>
using namespace std;

class Str
{
private:
    char *str;
    char *s;
    int maxlen;

public:
    Str(char *p)
    {
        str = new char[strlen(p) + 1]();
        maxlen = 0;
        strcpy(str, p);
    }
    ~Str()
    {
        delete str, s;
    }
    void process()
    {
        char *ptr = str;
        char lastchar;
        char currentchar;
        int len = 1;
        while (*ptr != '\0')
        {
            lastchar = *ptr++;
            currentchar = *ptr;
            if (lastchar == currentchar)
            {
                len++;
            }
            else
            {
                if (maxlen < len)
                {
                    maxlen = len;
                    s = new char[maxlen + 1]();
                    char *_s = s;
                    for (int i = 0; i < maxlen; i++)
                    {
                        ptr--;
                        *_s++ = *ptr++;
                    }
                    _s = '\0';
                }
                len = 1;
            }
        }
    }
    void show()
    {
        cout << str << '\n'
             << s << '\n'
             << maxlen << '\n';
    }
};

int main()
{
    char text[] = "jkkkaabbbbbaaa";
    Str s(text);
    s.process();
    s.show();
    system("pause");
    return 0;
}
