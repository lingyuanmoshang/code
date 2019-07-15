#include<iostream>
using namespace std;

class Date
{

private:

    int y,m,d;

public:

    Date() {}

    Date(int yy,int mm,int dd):y(yy),m(mm),d(dd) {}

    Date(Date &b):y(b.y),m(b.m),d(b.d) {}

    virtual ~Date() {}

    void set(int yy,int mm,int dd)
    {
        y=yy;
        m=mm;
        d=dd;
    }

    void show()
    {
        cout<<"birthdate:"<<y<<"-"<<m<<"-"<<d<<endl;
    }

};

class People
{

private:

    string num,nam,id;

    Date d;

    char sex;

public:

    People() {}

    People(string num1,string nam1,string id1,Date d1,char sex1):num(num1),nam(nam1),id(id1),d(d1),sex(sex1) {}

    People(People &p):num(p.num),nam(p.nam),id(p.id),d(p.d),sex(p.sex) {}

    ~People() {}

    void set(int yy,int mm,int dd,string num1,string nam1,string id1,char sex1)
    {

        d.set(yy,mm,dd);

        num=num1;

        nam=nam1;

        id=id1;

        sex=sex1;

    }

    void show()
    {

        cout<<"number:"<<num<<endl;

        cout<<"name:"<<nam<<endl;

        cout<<"id:"<<id<<endl;

        d.show();

        cout<<"sex:"<<sex<<endl;

    }

    string Getname()
    {

        return nam;

    }

};

class Student:virtual public People
{

private:

    string classNO;

public:

    Student() {}

    Student(People p,string c):People(p),classNO(c) {}

    Student(Student &s):People(s),classNO(s.classNO) {}

    ~Student() {}

    void set(string num1,string nam1,string id1,int y,int m,int d,char sex1,string c)
    {

        People::set(y,m,d,num1,nam1,id1,sex1);

        classNO=c;

    }

    void show()
    {
        People::show();
        cout<<"classNO:"<<classNO<<endl;
    }

};



class Teacher:virtual public People
{
private:

    string principalship,department;

public:

    Teacher() {}

    Teacher(People p,string pr,string dp):People(p),principalship(pr),department(dp) {}

    Teacher(Teacher &t):People(t),principalship(t.principalship),department(t.department) {}

    ~Teacher() {}

    void set(string num1,string nam1,int y,int m,int d,string id1,char sex1,string pr,string dp)
    {

        People::set(y,m,d,num1,nam1,id1,sex1);

        principalship=pr;

        department=dp;

    }

    void show()
    {
        People::show();

        cout<<"principalship:"<<principalship<<endl;

        cout<<"department:"<<department<<endl;

    }

    string  Getprincipalship()
    {
        return principalship;
    }

    string  Getdepartment()
    {
        return department;
    }

};

class Graduate:public Student

{

private:

    Teacher adviser;

    string subject;

public:

    Graduate() {}

    Graduate(People s,string cn,Teacher ad,string su):People(s),Student(s,cn),adviser(ad),subject(su) {}

    Graduate(Graduate &g):Student(g),adviser(g.adviser),subject(g.subject) {}

    virtual ~Graduate() {}

    Teacher GetAdvisor()
    {
        return adviser;
    }

    void set(int y,int m,int d,string num1,string nam1,string id1,char sex1,string c,string su,string pr,string dp)
    {

        Student::set(num1,nam1,id1,y,m,d,sex1,c);

        subject=su;

        adviser.set(num1,nam1,y,m,d,id1,sex1,pr,dp);

    }

    void show()
    {

        Student::show();

        cout<<"subject:"<<subject<<endl;

        cout<<endl;

        cout<<"His/Her advisor's date: "<<endl;

        adviser.show();

        cout<<endl;
    }

};

class TA:virtual public Graduate,virtual public Teacher
{

public:

    TA() {}

    TA(People &p,Teacher &t,string a,string b,string c):People(p),Graduate(p,a,t,b),Teacher(p,c,b) {}

    void show()
    {
        Graduate::show();

        cout<<"His/Her position: "<<Teacher::Getprincipalship()<<endl;

        cout<<"His/Her department: "<<Teacher::Getdepartment()<<endl;

    }

};

int main()
{

    Date d1(2000,10,10),d2(1988,3,6);

    People p1("18","xsy","420625200003180065",d1,'w');

    People p2("20","wyl","420625200000947783",d2,'w');

    Student s(p1,"1801");

    Teacher t(p2,"software","teacher");

    Graduate g(p1,"1801",t,"software");

    //g.show();

    TA ta(p1,t,"1801","sofeware","assitent");

    ta.show();

    return 0;

}
