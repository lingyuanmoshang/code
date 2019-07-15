#include<iostream>
#include<cstring>
using namespace std;
int n,a[105][105],b[105];
#define inf 0x3f3f3f3f
int main()
{
    cin>>n;
    int cnt=0,maxx=-inf;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<n;++i)
    {
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;++j)
        {
            int sum=0,max1=0;
            for(int k=1;k<=n;++k)
            {
                b[k]+=a[j][k];
                sum+=b[k];
                if(sum<0)
                    sum=0;
                if(max1<sum)
                    max1=sum;
            }
            if(maxx<max1)
                maxx=max1;
        }
    }
    cout<<maxx<<endl;
    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define inf 0x3f3f3f3f

int mat[105][105];
int temp[105];
int n;

int main()
{
    int max;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    max=-inf;
    for(int i=1;i<n;i++){
        memset(temp,0,sizeof(temp));
        for(int j=i;j<=n;j++){
            int sum=0,max1=0;
            for(int k=1;k<=n;k++){
                temp[k]+=mat[j][k];
                sum+=temp[k];
                if(sum<0) sum=0;
                if(sum>max1) max1=sum;
            }
            if(max<max1) max=max1;
        }
    }
    cout <<max<<endl;
    return 0;
}
*/
