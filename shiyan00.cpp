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
    cout<<"编号："<<Num<<endl;
    cout<<"姓名："<<Name<<endl;
    cout<<"性别："<<Sex<<endl;
    cout<<"出生日期："<<birthday.GetYear()<<"-"<<birthday.GetMonth()<<"-"<<birthday.GetDay()<<endl;
    cout<<"身份证号："<<Id<<endl;
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
    cout<<"班号："<<ClassNo<<endl;
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
    cout<<"职务："<<Principalship<<endl;
    cout<<"部门："<<Department<<endl;
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
    cout<<"专业："<<Subject<<endl;
    cout<<"导师："<<adviser.GetName()<<endl;;
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
    cout<<"职务："<<teacher::GetPrincipalship()<<endl;
    cout<<"部门："<<teacher::GetDepartment()<<endl;
}
int main()
{
    cout<<"Student:"<<endl;
    people a1("001","小明","男",1990,2,28,"201313138064");
    student b(a1,30) ;
    b.Show();
    cout<<endl;

    cout<<"Teacher:"<<endl;
    people a2("002","小红","女",1991,5,12,"201313138065");
    teacher c(a1,"助教","武汉科技大学");
    c.Show();
    cout<<endl;

    cout<<"Graduate:"<<endl;
    people a3("003","小李","男",1990,4,28,"201313138066");
    graduate d(c,a3,30,"软件工程");
    d.Show();
    cout<<endl;

    cout<<"TA:"<<endl;
    people a4("004","老王","男",1980,7,8,"2198080808067");
    TA e(c,a4,"软件工程",30,"教授","武汉科技大学");
    e.Show();
    return 0;
}
