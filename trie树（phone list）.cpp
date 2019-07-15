#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define ll long long
const int maxn=300005;
ll read()
{
    ll s=0,w=1;
    char ch;
    ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<1)+(s<<3)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
struct trie
{
    bool End;
    trie* next[10];
    trie()
    {
        End=false;
        for(int i=0; i<10; ++i)
            next[i]=NULL;
    }
};
trie node[maxn];
trie* root;
string str;
int k,n;
bool flag;
void Insert(string ss)
{
    trie* temp = root;
    int len=ss.size();
    for(int i=0; i<len; ++i)
    {
        int f = ss[i]-'0';
        if(temp->next[f]!=NULL)
        {
            if(temp->next[f]->End)
            {
                flag=false;
                return;
            }
        }
        else
            temp->next[f] = &node[k++];
        temp=temp->next[f];
    }
    temp->End=true;
    for(int i=0; i<10; ++i)
    {
        if(temp->next[i])
        {
            flag=false;
            return;
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        flag=true;
        k=1;
        memset(node,0,sizeof(node));
        root=&node[0];
        cin>>n;
        for(int i=0; i<n; ++i)
        {
            cin>>str;
            if(flag)
                Insert(str);
        }
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
