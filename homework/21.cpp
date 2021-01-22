#include <iostream>
using namespace std;

class Student
{
private:
    int num, score;
    char name[9];

public:
    Student()
    {
        num = 0;
        score = 0;
        for (int i = 0; i < 9; i++)
            name[i] = ' ';
    }
    int check_num(Student str[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (str[i].num == num)
                return 1;
        }
        return 0;
    }
    void Set(int id, char *na, int sc)
    {
        num = id;
        score = sc;
        char *p = na;
        int ind = 0;
        while (*p != '\0')
        {
            name[ind++] = *p++;
        }
        name[ind] = '\0';
    }
    int get_score()
    {
        return score;
    }
    void print()
    {
        cout << "学号:" << num << "\t姓名:" << name << "\t成绩:" << score << endl;
    }
};

Student max(Student *s, int n)
{
    int max = 0;
    Student *max_stu;
    Student *p = s;
    for (int i = 0; i < n; i++)
    {
        if ((*p).get_score() > max)
        {
            max_stu = p;
            max = (*p).get_score();
        }
        p++;
    }
    return *max_stu;
}

int main()
{
    Student s[3];
    for (int i = 0; i < 3; i++)
    {
        int num;
        cout << "请输入学号:";
        cin >> num;
        int score;
        cout << "请输入成绩:";
        cin >> score;
        char name[9];
        cout << "请输入姓名:";
        cin >> name;
        s[i].Set(num, name, score);
        if (s[i].check_num(s, i))
        {
            cout << "学号已存在,请重新输入信息\n";
            i--;
        }
    }
    Student m = max(s, 3);
    cout << "成绩最高的学生信息:\n";
    m.print();
    system("pause");
    return 0;
}
