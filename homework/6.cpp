#include <iostream>
using namespace std;

class STR
{
private:
    char s1[80], s2[80];
    char s3[160];

public:
    STR(char a[], char b[]);
    void consort();
    void show();
};

STR::STR(char a[], char b[])
{
    int i = 0;
    for (; a[i] != '\0'; i++)
        s1[i] = a[i];
    s1[i] = '\0';
    i = 0;
    for (; b[i] != '\0'; i++)
        s2[i] = b[i];
    s2[i] = '\0';
}

void STR::consort()
{
    int i = 0, x = 0;
    for (; s1[i] != '\0'; i++)
        s3[x++] = s1[i];
    i = 0;
    for (; s2[i] != '\0'; i++)
        s3[x++] = s2[i];
    s3[x] = '\0';
    for (i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - 1 - i; j++)
        {
            if (s3[j] > s3[j + 1])
                swap(s3[j], s3[j + 1]);
        }
    }
}

void STR::show()
{
    cout << s1 << '\n';
    cout << s2 << '\n';
    cout << s3 << '\n';
}

int main()
{
    char s1[] = "pear", s2[] = "apple";
    STR str(s1, s2);
    str.consort();
    str.show();
    system("pause");
    return 0;
}
