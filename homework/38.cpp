#include <iostream>
using namespace std;

class Intersection
{
private:
    int set[20];
    int len;

public:
    Intersection(int *s, int l)
    {
        int *p = s;
        for (int i = 0; i < l; i++)
            set[i] = *p++;
        len = l;
    }
    Intersection()
    {
        for (int i = 0; i < 20; i++)
            set[i] = 0;
        len = 0;
    }
    int f(int num)
    {
        for (int i = 0; i < len; i++)
        {
            if (num == set[i])
                return 1;
        }
        return 0;
    }
    Intersection operator&&(Intersection t)
    {
        int res[20] = {0};
        int count = 0;
        for (int i = 0; i < t.len; i++)
            if (f(t.set[i]))
                res[count++] = t.set[i];
        Intersection r(res, count);
        return r;
    }
    void show()
    {
        for (int i = 0; i < len; i++)
            cout << set[i] << '\t';
        cout << endl;
    }
};

int main()
{
    int s1[6] = {1, 3, 4, 5, 7, 8};
    int s2[7] = {1, 2, 3, 5, 7, 9, 11};
    Intersection obj1(s1, 6);
    Intersection obj2(s2, 7);
    Intersection obj3 = (obj1 && obj2);
    obj3.show();
    system("pause");
    return 0;
}
