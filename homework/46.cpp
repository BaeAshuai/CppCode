#include <iostream>
using namespace std;

class NUM
{
    int *data;
    int span1, span2;
    int num;

public:
    NUM(int n1, int n2)
    {
        span1 = n1;
        span2 = n2;
        num = 0;
        data = new int[span2 - span1]();
    }
    int isComposite(int x)
    {
        if (x < 2)
            return 1;
        else
        {
            for (int i = 2; i < x; i++)
            {
                if (x % i == 0)
                    return 1;
            }
            return 0;
        }
    }
    void process()
    {
        for (int i = span1; i <= span2; i++)
        {
            if (isComposite(i))
            {
                data[num++] = i;
            }
        }
    }
    void print()
    {
        cout << "有" << num << "个合数" << endl;
        for (int i = 0; i < num; i++)
        {
            cout << data[i] << '\t';
            if ((i + 1) % 8 == 0)
                cout << endl;
        }
    }
    ~NUM()
    {
        delete data;
    }
};

int main()
{
    NUM test(100, 200);
    test.process();
    test.print();
    system("pause");
    return 0;
}
