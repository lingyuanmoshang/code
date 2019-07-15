#include<bits/stdc++.h>
#define ll long long
#define rg register
using namespace std;
const int N=3000000,MAX=2e5+7;
const ll inf=1e18;
int n,m,T;
int a[MAX*2],cnt[N];
int cot;
int v[N],prime[MAX];
void prime_()
{
    cot=0;
    for(rg int i=2;i<N;i++)
    {
        if(!v[i]){
            v[i]=i;prime[++cot]=i;
        }
        for(rg int j=1;j<=cot;j++)
        {
            if(prime[j]>v[i]||prime[j]*i>N) break;
            v[i*prime[j]]=prime[j];
        }
    }
}
int isprime(int x)
{
    for(rg int i=2;i*i<=x;i++)
        if(x%i==0)return i;
    return 0;
}
int main()
{
    prime_();
    cin>>n;
    vector<int>ans;
    for(rg int i=1;i<=n*2;i++)
        scanf("%d",a+i),cnt[a[i]]++;
    sort(a+1,a+2*n+1);
    for(rg int i=n*2;i>=1;i--){
        if(cnt[a[i]]==0)continue;
        int temp=isprime(a[i]);
        if(temp){
            cnt[a[i]]--;
            cnt[a[i]/temp]--;
            ans.push_back(a[i]);
            if(ans.size()>=n)break;
        }
    }
    for(rg int i=1;i<=n*2;i++){
        if(cnt[a[i]]==0)continue;
        if(ans.size()>=n)break;
        cnt[a[i]]--;
        cnt[prime[a[i]]]--;
        ans.push_back(a[i]);
        if(ans.size()>=n)break;
    }
    for(rg int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
