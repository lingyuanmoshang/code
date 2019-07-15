#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll v[5000],w[5000],dp[5000],m,n;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        for(int i=0;i<m;++i)
            cin>>v[i]>>w[i];
        memset(dp,0,sizeof(dp));
        for(ll i=0;i<m;++i)
        {
            for(ll j=n;j>=w[i];j--)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
