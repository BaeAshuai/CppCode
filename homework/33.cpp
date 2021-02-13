#include <iostream>
using namespace std;

class PHALANX
{
private:
    int (*p)[20];
    int startnum;
    int n;

public:
    PHALANX(int s, int m)
    {
        startnum = s;
        n = m;
        int num[20][20];
        p = num;
    }
    void process()
    {
        int k = startnum;
        int num[20][20];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                num[j][i] = k++;
            }
            for (int j = i - 1; j >= 0; j--)
            {
                num[i][j] = k++;
            }
        }
        p = num;
    }
    void print()
    {
        int(*_p)[20] = p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (*_p)[j] << '\t';
            }
            cout << '\n';
            _p++;
        }
    }
    ~PHALANX()
    {
        //delete p;
    }
};

int main()
{
    PHALANX test(1, 5);
    test.process();
    test.print();
    system("pause");
    return 0;
}
