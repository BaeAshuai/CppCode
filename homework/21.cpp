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
        cout << "ѧ��:" << num << "\t����:" << name << "\t�ɼ�:" << score << endl;
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
        cout << "������ѧ��:";
        cin >> num;
        int score;
        cout << "������ɼ�:";
        cin >> score;
        char name[9];
        cout << "����������:";
        cin >> name;
        s[i].Set(num, name, score);
        if (s[i].check_num(s, i))
        {
            cout << "ѧ���Ѵ���,������������Ϣ\n";
            i--;
        }
    }
    Student m = max(s, 3);
    cout << "�ɼ���ߵ�ѧ����Ϣ:\n";
    m.print();
    system("pause");
    return 0;
}
