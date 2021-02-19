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

template <class T>
class Stack
{
private:
    T arr[100];
    int currentSize;
public:
    Stack() { currentSize = 0; }
    void push(T temp)
    {
        arr[currentSize++] = temp;
    }
    T pop()
    {
        T temp = arr[currentSize - 1];
        arr[currentSize - 1] = NULL;
        currentSize--;
        return temp;
    }
    bool empty()
    {
        return (currentSize == 0) ? true : false;
    }
    bool full()
    {
        return (currentSize == 100) ? true : false;
    }
    int size()
    {
        return currentSize;
    }
    int top()
    {
        return currentSize;
    }
};

int main()
{
    system("pause");
    return 0;
}
