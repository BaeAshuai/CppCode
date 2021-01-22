#include <iostream>
using namespace std;

class Number
{
private:
    int data[50][4];
    int count_data;

public:
    Number()
    {
        count_data = 0;
    }
    int isprime(int x)
    {
        if (x < 2)
            return 0;
        else
            for (int i = 2; i < x; i++)
                if (x % i == 0)
                    return 0;
        return 1;
    }
    void fund()
    {
        int sum = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        for (i = 1; i <= 30; i++)
        {
            if (isprime(i))
            {
                for (j = i + 1; j <= 30; j++)
                {
                    if (isprime(j))
                    {
                        for (k = j + 1; k <= 30; k++)
                        {
                            if (isprime(k))
                            {
                                sum = i + j + k;
                                if (isprime(sum))
                                {
                                    data[count_data][0] = sum;
                                    data[count_data][1] = i;
                                    data[count_data][2] = j;
                                    data[count_data++][3] = k;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    void print()
    {
        for (int i = 0; i < count_data; i++)
            cout << "(" << data[i][1] << "," << data[i][2] << "," << data[i][3] << "): " << data[i][0] << endl;
    }
};

int main()
{
    Number n;
    n.fund();
    n.print();
    system("pause");
    return 0;
}
