#include <iostream>
#include <fstream>
using namespace std;

void Write()
{
    ofstream ofs("1.txt");
    ofs << "1 165 48 9 64 415" << endl;
    ofs.close();
}

void Read()
{
    char ch;
    ifstream ifs("1.txt");
    while (ifs.eof())
    {
        ifs.get(ch);
        cout << ch;
    }
    ifs.close();
}

int main()
{
    Write();
    system("pause");
    return 0;
}
