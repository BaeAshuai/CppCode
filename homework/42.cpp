#include <iostream>
using namespace std;

class MOVE
{
    int *array;
    int n;

public:
    MOVE(int b[], int m)
    {
        array = new int[m]();
        for (int i = 0; i < m; i++)
            array[i] = b[i];
        n = m;
    }
    void exchange()
    {
        int max = array[0], min = array[0], max_index = 0, min_index = 0;
        for (int i = 0; i < n; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
                max_index = i;
            }
            else if (array[i] < min)
            {
                min = array[i];
                min_index = i;
            }
        }
        swap(array[max_index], array[min_index]);
    }
    void print()
    {
        for (int i = 0; i < n; i++)
            cout << array[i] << '\t';
        cout << endl;
    }
    ~MOVE()
    {
        delete array;
    }
};

int main()
{
    int num[] = {21, 65, 43, 87, 12, 84, 44, 97, 32, 55};
    MOVE test(num, 10);
    test.print();
    test.exchange();
    test.print();
    system("pause");
    return 0;
}
