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
        p = new int[20][20]();
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
        int(*_p)[20] = p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                (*_p)[j] = num[i][j];
            }
            _p++;
        }
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
    PHALANX test(1, 10);
    test.process();
    test.print();
    system("pause");
    return 0;
}
