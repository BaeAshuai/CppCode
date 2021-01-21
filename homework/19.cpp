#include <iostream>
using namespace std;

class STR
{
private:
    char *s;
    int yn;
public:
    STR(char *t);
    ~STR();
    int alph();
    int num();
    void print();
};

int main()
{
    
    system("pause");
    return 0;
}
