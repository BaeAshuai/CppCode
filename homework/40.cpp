#include <iostream>
#include <string.h>
using namespace std;

class person
{
private:
    char name[10], num[10];
    friend class compute;
};

class compute
{
private:
    person pn[3];

public:
    void setdata()
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> pn[i].name;
            cin >> pn[i].num;
        }
    }
    void sort()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 2 - i; j++)
                if (strcmp(pn[j].name, pn[j + 1].name) > 0)
                    swap(pn[j], pn[j + 1]);
    }
    void print()
    {
        for (int i = 0; i < 3; i++)
        {
            cout << pn[i].name << '\t' << pn[i].num << '\n';
        }
    }
};

int main()
{
    compute c;
    c.setdata();
    cout << "输入姓名和电话号码：" << endl;
    c.print();
    c.sort();
    cout << "排序后的用户信息为：" << endl;
    c.print();
    system("pause");
    return 0;
}
