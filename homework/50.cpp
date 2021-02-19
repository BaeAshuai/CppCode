#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void Write(char path[], char content[])
{
    ofstream ofs(path);
    ofs << content << endl;
    ofs.close();
}

void *ReadAndAnal(char path[])
{
    char ch;
    char *r = new char[100]();
    char *p = r;
    ifstream ifs;
    ifs.open(path);
    int count = 0;
    int n = 0;
    bool s = false;
    bool f = true;
    int max = 0;
    int min = 0;
    float avg = 0;
    while (!ifs.eof())
    {
        ifs.get(ch);
        *p++ = ch;
        if (ch > '0' && ch < '9')
        {
            n = n * 10 + ch - '0';
            s = true;
        }
        else
        {
            if (s == true)
            {
                if (f)
                {
                    max = n;
                    min = n;
                    f = false;
                }
                else
                {
                    if (max < n)
                        max = n;
                    if (min > n)
                        min = n;
                }
                avg += n;
                n = 0;
                count++;
                s = false;
            }
        }
    }
    avg /= count;
    *p = '\0';
    ifs.close();
    cout << "读入的文本为" << '\n'
         << r;
    cout << "Max=" << max << endl;
    cout << "Min=" << min << endl;
    cout << "Avg=" << avg << endl;
}

class File
{
    char *path;

    File(char p[])
    {
        path = new char[strlen(p) + 1];
        strcpy(path, p);
    }

    bool AppendTo(char content[])
    {
        char *r = new char[100]();
        char *y = Read();
        strcpy(r, y);
        strcat(r, content);
        ofstream f(path, ios::app);
        if (!f.is_open())
            return false;
        f << r << endl;
        f.close();
        return true;
    }

    char *Read()
    {
        char ch;
        char *r = new char[100]();
        char *p = r;
        ifstream ifs;
        ifs.open(path);
        while (!ifs.eof())
        {
            ifs.get(ch);
            *p++ = ch;
        }
        return r;
    }

    void Cpyto(char p[])
    {
        char *y = Read();
        ofstream f(p);
        f << y << endl;
        f.close();
    }
};

int main()
{
    Write("C:\\Users\\10240\\Desktop\\1.txt", "123 234 5456 567");
    ReadAndAnal("C:\\Users\\10240\\Desktop\\1.txt");
    system("pause");
    return 0;
}
