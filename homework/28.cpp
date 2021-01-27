#include <iostream>
using namespace std;

class String
{
private:
    int Length;
    char *s;

public:
    String() {}
    String(String &a)
    {
        s = a.s;
        Length = a.Length;
    }
    String(char a[])
    {
        s = a;
        int i = 0;
        while (a[i++] != '\0')
        {
        }
        Length = i - 1;
    }
    ~String()
    {
    }
    String operator+(const String &a)
    {
        char *p1 = s;
        char *p2 = a.s;
        int newLen = Length + a.Length;
        int i = 0;
        char resc[20];
        while (*p1 != '\0')
        {
            resc[i++] = *p1++;
        }
        while (*p2 != '\0')
        {
            resc[i++] = *p2++;
        }
        resc[i] = '\0';
        String n(resc);
        return n;
    }
    String operator=(const String &a)
    {
        s = a.s;
        Length = a.Length;
    }
    void show()
    {
        char *p = s;
        for (int i = 0; i < Length; i++)
            cout << *s++;
        cout << endl;
    }
};

int main()
{
    String s1("123");
    String s2("456");
    String s3;
    s3 = s1 + s2;
    s1.show();
    s2.show();
    s3.show();
    system("pause");
    return 0;
}
