#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int trie[maxn*32][5],tot,a[maxn];
void Insert(int x)
{
    int pos=0;
    for(int i=31;i>=0;--i)
    {
        int u=(x>>i)&1;
        if(!trie[pos][u]) trie[pos][u]=++tot;
        pos=trie[pos][u];
    }
}
int Search(int x)
{
    int pos=0,ans=0;
    for(int i=31;i>=0;--i)
    {
        int u=(x>>i)&1;
        if(trie[pos][u^1])
        {
            pos=trie[pos][u^1];
            ans|=(1<<i);
        }
        else
            pos=trie[pos][u];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        Insert(a[i]);
    }
    int ans=0;
    for(int i=0;i<n;++i)
        ans=max(ans,Search(a[i]));
    cout<<ans<<endl;
    return 0;
}