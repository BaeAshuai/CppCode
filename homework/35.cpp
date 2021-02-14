#include <iostream>
#include <string.h>
using namespace std;

class SUM
{
private:
    char *p[5];

public:
    SUM(char *s[5])
    {
        for (int i = 0; i < 5; i++)
        {
            p[i] = new char[20]();
            strcpy(p[i], s[i]);
        }
    }
    void process1()
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 4 - i; j++)
            {
                if (strcmp(p[j], p[j + 1]) > 0)
                    swap(p[j], p[j + 1]);
            }
    }
    void print()
    {
        for (int i = 0; i < 5; i++)
            cout << p[i] << '\t';
        cout << endl;
    }
};

int main()
{
    char *s[5] = {"Follow me",
                  "BASIC",
                  "Great wall",
                  "Fortran",
                  "Pascal"};
    SUM test(s);
    test.process1();
    test.print();
    system("pause");
    return 0;
}
