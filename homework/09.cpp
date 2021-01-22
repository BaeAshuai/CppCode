#include <iostream>
using namespace std;

class Base
{
protected:
    char name[8];
    int num;

public:
    Base();
    void print();
    virtual int Isgood() = 0;
};

class Student : public Base
{
public:
    Student();
    int Isgood();
};

class Teacher : public Base
{
public:
    Teacher();
    int Isgood();
};

Base::Base()
{
    cout << "����������" << endl;
    cin >> name;
}

void Base::print()
{
    cout << name << '\t';
    cout << num << endl;
}

Student::Student()
{
    cout << "���������" << endl;
    cin >> num;
}

int Student::Isgood()
{
    return num > 90 ? 1 : 0;
}

Teacher::Teacher()
{
    cout << "������������" << endl;
    cin >> num;
}

int Teacher::Isgood()
{
    return num > 3 ? 1 : 0;
}

int main()
{
    int num_stu = 0;
    int num_tea = 0;
    cout << "������ѧ������" << '\n';
    cin >> num_stu;
    cout << "��������ʦ����" << '\n';
    cin >> num_tea;
    Student students[num_stu];
    Teacher teachers[num_tea];
    cout << "����ѧ����:" << '\n';
    for (int i = 0; i < num_stu; i++)
    {
        if (students[i].Isgood())
            students[i].print();
    }
    cout << "�����ʦ��:" << '\n';
    for (int i = 0; i < num_tea; i++)
    {
        if (teachers[i].Isgood())
            teachers[i].print();
    }
    system("pause");
    return 0;
}
