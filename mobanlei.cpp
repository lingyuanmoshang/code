#include<iostream>
using namespace std;
template<class T>
T findmax(T a,T b,T c)
{
    T x;
	x=a;
	if(x<b)
		x=b;
	if(x<c)
		x=c;
	return x;
}
int main()
{
	double a=1.2,b=2.3,c=3.4;
	double m=findmax(a,b,c);
	cout<<m<<endl;
	cout<<endl;

	int x=1,y=2,z=3;
	int n=findmax(x,y,z);
	cout<<n<<endl;
	cout<<endl;
}
