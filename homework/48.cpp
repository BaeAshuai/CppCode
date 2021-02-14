#include <iostream>
using namespace std;
#define MAX 100
class Sample
{
    int A[MAX];
    int n;

public:
    Sample()
    {
        n = 0;
    }
    friend class Process;
};

class Process
{
public:
    void getdata(Sample &s)
    {
        cin >> s.n;
        for (int i = 0; i < s.n; i++)
        {
            cin >> s.A[i];
        }
    }
    void selectsort(Sample &s)
    {
        int min = s.A[0], min_index = 0;
        for (int i = 0; i < s.n; i++)
        {
            min = s.A[i], min_index = i;
            for (int j = i + 1; j < s.n - i; j++)
            {
                if (min > s.A[j])
                {
                    min = s.A[j];
                    min_index = j;
                }
            }
            swap(s.A[i], s.A[min_index]);
        }
    }
    void disp(Sample &s)
    {
        for (int i = 0; i < s.n; i++)
        {
            cout << s.A[i] << '\t';
        }
        cout << endl;
    }
};

int main()
{
    Sample s;
    Process p;
    p.getdata(s);
    p.selectsort(s);
    p.disp(s);
    system("pause");
    return 0;
}
