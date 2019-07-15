#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105],f[10005],ff[10005],n,s;
int main()
{
    while(~scanf("%d",&n))
    {
        s=0;
        memset(f,0,sizeof(f));
        memset(ff,0,sizeof(ff));
        f[0]=1;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        f[a[0]]=1;
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=s;++j)
            {
                for(int k=0;k+j<=s&&k<=a[i];k+=a[i])
                {
                    ff[abs(k-j)]+=f[j];
                    ff[j+k]+=f[j];
                }
            }
            for(int j=0;j<=s;++j)
            {
                f[j]=ff[j];
                ff[j]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<=s;++i)
        {
            if(!f[i])
                ff[cnt++]=i;
        }
        printf("%d\n",cnt);
        for(int i=0;i<cnt;++i)
        {
            printf("%d%c",ff[i],i==cnt-1?'\n':' ');
        }
    }
    return 0;
}
