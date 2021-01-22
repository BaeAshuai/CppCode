#include <iostream>
using namespace std;

class ID
{
private:
    char s[19], x[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

public:
    ID(char *str);
    void fun();
    void print();
};

ID::ID(char *str)
{
    for (int i = 0; i < 15; i++)
        s[i] = *str++;
}

void ID::fun()
{
    for (int i = 14; i > 5; i--)
        s[i + 2] = s[i];
    s[6] = '1';
    s[7] = '9';
    int S = 0;
    for (int i = 0; i < 17; i++)
        S += (s[i] - '0') * w[i];
    s[17] = x[S % 11];
}

void ID::print()
{
    for (int i = 0; i < 18; i++)
        cout << s[i];
    cout << '\n';
}

int main()
{
    char i[] = "340524800101001";
    ID id(i);
    id.fun();
    cout << "原身份证号:" << i << '\n';
    cout << "扩展后的身份证号:";
    id.print();
    system("pause");
    return 0;
}
