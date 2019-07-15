#include<iostream>
using namespace std;

class Clock
{
	int hour,minute,second;
public:
	Clock(int h=0,int m=0,int s=0)hour(h),minute(m),second(s){}
	Clock(Clock &c)hour(c.hour),minute(c.minute),second(c.second){}
	Clock operator+(const Clock &c);
	Clock operator-(const Clock &c);
	Clock &operator++();
	Clock operator++(int);
	//Clock &operator--();
	//Clock operator--(int);
	void ShowTime()const{
		cout<<hour<<"-"<<minute<<"-"<<second<<endl;
	}
};
Clock Clock::operator+(const Clock &c)
{
	second=second+c.second;
	if(second>=60)
	{ minute++;second-=60; }
	minute=minute+c.minute;
	if(minute>=60)
	{ hour++;minute-=60; }
	hour=(hour+c.hour)%24;
	return *this;
}
Clock Clock::operator-(const Clock &c)
{
	second=second-c.second;
	if(second<0)
	{ minute--;second+=60; }
	minute=minute-c.minute;
	if(minute<0)
	{ hour--;minute+=60; }
	hour=(hour-c.hour+24)%24;
	return *this;
}
Clock& Clock::operator++()
{
	second++;
	if(second>=60)
	{
		second-=60;minute++;
		if(minute>=60)
		{
			minute-=60;
			hour=(hour+1)%24;
		}
	}
	retrun *this;
}
Clock Clock::operator++(int)
{
	Clock old=*this;
	++(*this);
	return old;
}
//Clock& Clock::operator--()
//Clock Clock::operator--(int)
int main()
{
    Clock myClock1(23,59,59),myClock2(0,0,1);
    cout<<"First time output: ";
    myClock1.ShowTime();
    cout<<"Show myClock1+myClock2: ";
    (myClock1+myClock2).ShowTime();
    cout<<"Show myClock1-myClock2: ";
    (myClock1-myClock2).ShowTime();
    cout<<"Show myClock1++:    ";
    (myClock1++).ShowTime();
    cout<<"Show++myClock1:     ";
    (++myClock1).ShowTime();
    return 0;
}

