#include<iostream>
using namespace std;
int main()
{
    int n,a[25][25],cnt=1;
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1,k=i;j<=i;++j)
			a[k-j+1][j]=cnt++;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n-i+1;++j)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
