#include <iostream>
using namespace std;

class String
{
private:
    char *str1, *str2;
    char *str;

public:
    String(char *s1, char *s2);
    void dele();
    void sort();
    void show();
};

String::String(char *s1, char *s2)
{
    str1 = s1;
    str2 = s2;
    str = new char[20]();
    char *p = str;
    while (*str1 != '\0')
    {
        *p = *str1++;
        p++;
    }
    while (*str2 != '\0')
    {
        *p = *str2++;
        p++;
    }
    *p = '\0';
}

void String::dele()
{
    char *p = new char[20]();
    char *_p = p;
    while (*str != '\0')
    {
        if (*str != ' ')
            *_p++ = *str;
        str++;
    }
    *_p = '\0';
    str = p;
}

void String::sort()
{
    char *p1 = str;
    char *p2 = str + 1;
    int l = 0;
    int count = 0;
    while (*p1 != '\0')
    {
        l++;
        p1++;
    }
    p1 = str;
    while (1)
    {
        while (*p1 != '\0' && *p2 != '\0')
        {
            if (*p1 > *p2)
                swap(*p1, *p2);
            p1++;
            p2++;
        }
        p1 = str;
        p2 = str + 1;
        count++;
        if (l == count)
            break;
    }
}

void String::show()
{
    char *p = str;
    while (*p != '\0')
        cout << *p++;
    cout << '\n';
}

int main()
{
    char str1[] = "db a";
    char str2[] = "4  1";
    char *s1 = str1, *s2 = str2;
    String s(s1, s2);
    s.show();
    s.dele();
    s.sort();
    s.show();
    system("pause");
    return 0;
}
