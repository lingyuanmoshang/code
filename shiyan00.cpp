#include<iostream>
#include<string>
using namespace std;

class Date
{
private:
    int Year;
    int Month;
    int Day;
public:
    Date();
    Date(int Y,int M,int D);
    void SetDate(int y,int m,int d);
    int GetYear()
    {
        return Year;
    }
    int GetMonth()
    {
        return Month;
    }
    int GetDay()
    {
        return Day;
    }
    virtual ~Date();
};
Date::Date()
{
    Year=0;
    Month=0;
    Day=0;
}

Date::Date(int Y,int M,int D)
{
    Year=Y;
    Month=M;
    Day=D;
}
void Date::SetDate(int y,int m,int d)
{
    Year=y;
    Month=m;
    Day=d;
}
Date::~Date() {}

class people
{
private:
    string Num;
    string Name;
    string Sex;
    Date birthday;
    string Id;
public:
    people();
    people(string num,string name,string sex,int y,int m,int d,string id);
    people(people &p);
    string GetName();
    void Show();
    virtual ~people();
};
people::people() {}
people::people(string num,string name,string sex,int y,int m,int d,string id):birthday()
{
    birthday.SetDate(y,m,d);
    Num=num;
    Name=name;
    Sex=sex;
    Id=id;
}
people::~people() {}
people::people(people &p):birthday(p.birthday)
{
    Num=p.Num;
    Name=p.Name;
    Sex=p.Sex;
    Id=p.Id;
}

void people::Show()
{
    cout<<"��ţ�"<<Num<<endl;
    cout<<"������"<<Name<<endl;
    cout<<"�Ա�"<<Sex<<endl;
    cout<<"�������ڣ�"<<birthday.GetYear()<<"-"<<birthday.GetMonth()<<"-"<<birthday.GetDay()<<endl;
    cout<<"���֤�ţ�"<<Id<<endl;
}
string people::GetName()
{
    return Name;
}

class student:virtual public people
{
private:
    int ClassNo;
public:
    student(people p,int c);
    student(student &s);
    void Show();
    virtual ~student();
};
student::student(people p,int c):people(p)
{
    ClassNo=c;
}
student::student(student &s):people(s)
{
    ClassNo=s.ClassNo;
}
student::~student() {}
void student::Show()
{
    people::Show();
    cout<<"��ţ�"<<ClassNo<<endl;
}

class teacher:virtual public people
{
private:
    string Principalship;
    string Department;
public:
    teacher(people p,string pr,string de);
    teacher();
    teacher(teacher &t);
    void Show();
    virtual ~teacher();
    string GetPrincipalship();
    string GetDepartment();
};
teacher::teacher(people p,string pr,string de):people(p)
{
    Principalship=pr;
    Department=de;
}
teacher::teacher():people()
{
    Principalship=" ";
    Department=" ";
}
teacher::teacher(teacher &t):people(t)
{
    Principalship=t.Principalship;
    Department=t.Department;
}
string teacher::GetPrincipalship()
{
    return Principalship;
}
string teacher::GetDepartment()
{
    return Department;
}
void teacher::Show()
{
    people::Show() ;
    cout<<"ְ��"<<Principalship<<endl;
    cout<<"���ţ�"<<Department<<endl;
}
teacher::~teacher() {}
class graduate:public student
{
private:
    string Subject;
    teacher adviser;
public:
    graduate(teacher t,people p1,int c,string su);
    void Show();
    virtual ~graduate();
};
graduate::graduate( teacher t,people p1,int c,string su ):people(p1),adviser(t),student(p1,c)
{
    Subject=su;
}
void graduate::Show()
{
    student::Show();
    cout<<"רҵ��"<<Subject<<endl;
    cout<<"��ʦ��"<<adviser.GetName()<<endl;;
}
graduate::~graduate() {}
class TA:virtual public graduate,virtual public teacher
{
public:
    TA(  teacher t1,people p,string su,int c,string pr,string de);
    void Show();
private:
    teacher t;
};
TA::TA(teacher t1,people p,string su,int c,string pr,string de):people(p),graduate(t1,p,c,su),teacher(p,pr,de)
{
}
void TA::Show()
{
    graduate::Show();
    cout<<"ְ��"<<teacher::GetPrincipalship()<<endl;
    cout<<"���ţ�"<<teacher::GetDepartment()<<endl;
}
int main()
{
    cout<<"Student:"<<endl;
    people a1("001","С��","��",1990,2,28,"201313138064");
    student b(a1,30) ;
    b.Show();
    cout<<endl;

    cout<<"Teacher:"<<endl;
    people a2("002","С��","Ů",1991,5,12,"201313138065");
    teacher c(a1,"����","�人�Ƽ���ѧ");
    c.Show();
    cout<<endl;

    cout<<"Graduate:"<<endl;
    people a3("003","С��","��",1990,4,28,"201313138066");
    graduate d(c,a3,30,"�������");
    d.Show();
    cout<<endl;

    cout<<"TA:"<<endl;
    people a4("004","����","��",1980,7,8,"2198080808067");
    TA e(c,a4,"�������",30,"����","�人�Ƽ���ѧ");
    e.Show();
    return 0;
}
