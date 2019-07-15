#include<cstdio>
int t1[1005],t2[1005],ans[1005],n,cnt;
void dfs(int l,int *t1,int *t2)
{
    if(l<=0)
        return;
    ans[cnt++]=t1[0];
    int t;
    for(t=0;t2[t]!=t1[0];++t);
    dfs(l-1-t,t1+t+1,t2+t+1);
    dfs(t,t1+1,t2);
}
int main()
{
    while(~scanf("%d",&n))
    {
        cnt=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&t1[i]);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d",&t2[i]);
        }
        dfs(n,t1,t2);
        for(int i=n-1;i>=0;--i)
            printf("%d%c",ans[i],i==0?'\n':' ');
    }
}
