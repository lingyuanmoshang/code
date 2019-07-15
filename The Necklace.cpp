#include<iostream>
#include<cstring>
using namespace std;
int T,n,d[1005],a,b,edge[55][55];
void dfs(int k)
{
	for(int i=1;i<=50;++i)
	{
		if(edge[k][i])
		{
			edge[k][i]--;
			edge[i][k]--;
			dfs(i);
			cout<<i<<" "<<k<<endl;
		}
	}
}
int main()
{
	cin>>T;
	for(int c=1;c<=T;++c)
	{
		cin>>n;
		memset(d,0,sizeof(d));
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=n;++i)
		{
			cin>>a>>b;
			d[a]++;
			d[b]++;
			edge[a][b]++;
			edge[b][a]++;
		}
		cout<<"Case #"<<c<<endl;
		int flag=0;
		for(int i=1;i<=50;++i)
		{
			if(d[i]&&(d[i]&1))
			{
				flag=1;
				break;
			}
		}
		if(flag)
			cout<<"some beads may be lost"<<endl;
		else
		{
			for(int i=1;i<=50;++i)
				if(d[i])
					dfs(i);
		}
		if(c!=T)
			cout<<endl;
	}
	return 0;
}
