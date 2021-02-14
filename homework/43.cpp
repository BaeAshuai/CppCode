#include <iostream>
#include <string.h>
using namespace std;

class CString
{
    char *str;
    char (*p)[2];
    int size;

public:
    CString(char *s)
    {
        str = new char[strlen(s) + 1]();
        strcpy(str, s);
        p = 0;
        size = 0;
    }
    void Count()
    {
        p = new char[strlen(str) + 1][2];
        bool exists = false;
        for (int i = 0; i < strlen(str); i++)
        {
            exists = false;
            for (int j = 0; j < size; j++)
            {
                if (p[j][0] == str[i])
                {
                    p[j][1]++;
                    exists = true;
                }
            }
            if (!exists)
            {
                p[size][0] = str[i];
                p[size++][1] = '1';
            }
        }
        char(*_p)[2] = p;
        p = new char[size][2]();
        for (int i = 0; i < size; i++)
        {
            p[i][0] = _p[i][0];
            p[i][1] = _p[i][1];
        }
    }
    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << p[i][0] << ' ' << p[i][1] << endl;
        }
        cout << endl;
    }
    ~CString()
    {
        delete str, p;
    }
};

int main()
{
    char s[] = "abdabcdesffffd";
    CString test(s);
    test.Count();
    test.Show();
    system("pause");
    return 0;
}
