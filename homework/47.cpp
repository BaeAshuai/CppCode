#include <iostream>
using namespace std;

class Saddle_point
{
    int a[4][4];
    int b[4][4];
    int num;

public:
    Saddle_point(int data[][4])
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                a[i][j] = data[i][j];
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                b[i][j] = 0;
        num = 0;
    }
    void process()
    {
        int max = a[0][0], max_pos[2] = {0}, min = a[0][0], min_pos[2] = {0};
        bool y = true;
        for (int i = 0; i < 4; i++)
        {
            max = a[i][0], max_pos[2] = {i}, min = a[i][0], min_pos[2] = {i};
            y = true;
            for (int j = 0; j < 4; j++)
                if (a[i][j] > max)
                {
                    max = a[i][j];
                    max_pos[0] = i;
                    max_pos[1] = j;
                }
            for (int j = 0; j < 4; j++)
            {
                if (a[j][max_pos[1]] < max)
                {
                    y = false;
                    break;
                }
            }
            if (y)
            {
                b[num][0] = max_pos[0];
                b[num][1] = max_pos[1];
                b[num][2] = max;
                num++;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                cout << a[i][j] << '\t';
            cout << endl;
        }
        cout << endl;
        cout << "鞍点个数为:" << num << endl;
        for (int i = 0; i < num; i++)
        {
            cout << b[i][2] << "(" << b[i][0] << "," << b[i][1] << ")" << endl;
        }
    }
};

int main()
{
    int b[][4] = {2, 6, 3, 4, 5, 6, 5, 5, 5, 7, 6, 7, 1, 9, 2, 7};
    Saddle_point fun(b);
    fun.process();
    fun.print();
    system("pause");
    return 0;
}
