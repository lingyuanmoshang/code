#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[100][100],n,m,a[100],b[100];
int main(){
	while(~scanf("%d%d",&n,&m)){
		if(!n&&!m) break;
		memset(f,0,sizeof(f));
		for(int i=1;i<=m;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(a[j]==b[i])
					f[j][i]=a[j];
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				f[j][i]=a[i];
			}
		}
		for(int i=1;i<=n;++i){
			bool flag=false;
			for(int j=1;j<=m;++j){
				if(!flag&&f[i][j]==b[i]){
					flag=true;
					continue;
				}
				if(flag) {
					f[i][j]=0;
				}
				if(f[i][j]<b[i]||f[i][j]>b[i])
					f[i][j]=0;
			}
			if(!flag)
				f[i][m]=b[i];
		}
		for(int i=1;i<=m;++i){
			bool flag=false;
			for(int j=1;j<=n;++j){
				if(f[j][i]==a[i])
					flag=true;
			}
			if(!flag)
				f[1][i]=a[i];
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				ans+=f[i][j];
			}
		}
		printf("%d\n",ans);
    }
	return 0;
}
