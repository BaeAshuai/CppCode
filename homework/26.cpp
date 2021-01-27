#include <iostream>
using namespace std;

class STRING
{
private:
    char str1[60];
    char str2[40];
    char str3[100];

public:
    STRING(char *s1, char *s2)
    {
        char *p1 = s1;
        char *p2 = s2;
        int i = 0;
        while (*p1 != '\0')
        {
            str1[i++] = *p1++;
        }
        str1[i] = '\0';
        i = 0;
        while (*p2 != '\0')
        {
            str2[i++] = *p2++;
        }
        str2[i] = '\0';
    }
    void process()
    {
        int i = 0, j = 0, k = 0;
        bool end1 = false, end2 = false;
        while (1)
        {
            if (str1[j] != '\0')
                str3[i++] = str1[j++];
            else
                end1 = true;
            if (str2[k] != '\0')
                str3[i++] = str2[k++];
            else
                end2 = true;
            if (end1 && end2)
                break;
        }
        str3[i] = '\0';
    }
    void print()
    {
        cout << str3 << endl;
    }
};

int main()
{
    char s1[] = "abcde";
    char s2[] = "ABCDEFG";
    STRING test(s1, s2);
    test.process();
    test.print();
    system("pause");
    return 0;
}