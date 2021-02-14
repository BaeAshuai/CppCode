#include <iostream>
using namespace std;

template <typename T>
class Array
{
    T *data;
    int len;
    int max;

public:
    Array(T *d, int len)
    {
        data = new T[len]();
        for (int i = 0; i < len; i++)
            data[i] = d[i];
    }
    void sort()
    {
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len - 1 - i; j++)
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
    }
    void getmax()
    {
        T max = data[0];
        int max_index = 0;
        for (int i = 0; i < len; i++)
            if (max < data[i])
            {
                max = data[i];
                max_index = i;
            }
    }
    T operator[](int a)
    {
        return data[a];
    }
};

int main()
{

    system("pause");
    return 0;
}
