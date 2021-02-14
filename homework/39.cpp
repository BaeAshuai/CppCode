#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class NUM
{
private:
    int data[25];

public:
    NUM()
    {
        int count = 0;
        bool exists = false;
        while (count != 25)
        {
            exists = false;
            int num = 10000 * rand() / (RAND_MAX + 1.0);
            for (int i = 0; i < count; i++)
            {
                if (data[i] == num)
                    exists = true;
            }
            if (!exists)
            {
                data[count++] = num;
            }
        }
    }
    void process()
    {
        for (int i = 0; i < 25; i++)
            for (int j = 0; j < 24 - i; j++)
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
    }
    void times()
    {
        int time = 150;
        //cin >> time;
        int r[10000] = {0};
        bool dl = true;
        for (int i = 0; i < time; i++)
        {
            NUM t;
            for (int j = 0; j < 25; j++)
                r[t.data[j]]++;
        }
        for (int i = 0; i < 10000; i++)
        {
            if (r[i] != 0)
            {
                cout << i << '\t' << "概率:" << r[i] / (time * 25.0) << '\t' << "数学期望" << r[i] * r[i] / (time * 25.0) << endl;
                if ((r[i] / (time * 25.0)) / (r[i] * r[i] / (time * 25.0)) <= 0.95 && (r[i] / (time * 25.0)) / (r[i] * r[i] / (time * 25.0)) >= 1.05)
                    dl = false;
            }
        }
        cout << (dl ? "大数定理成立" : "大数定理不成立") << endl;
    }
    void print()
    {
        for (int i = 0; i < 25; i++)
        {
            cout << data[i] << '\t';
            if (i % 5 == 0)
                cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    NUM t;
    t.process();
    t.print();
    //t.times();
    system("pause");
    return 0;
}
