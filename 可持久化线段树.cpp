// luogu-judger-enable-o2
#include<algorithm>
#include<cstdio>
#define mid ((l+r)>>1)
#define lson l,mid
#define rson mid+1,r
using namespace std;
const int N = 1000010;
int n,m,node_cnt;
int a[N],b[N],sum[N<<5],lc[N<<5],rc[N<<5],root[N<<5];
void build(int& o,int l,int r){
  o=++node_cnt;
  if(!(l^r)) return;
  build(lc[o],lson);
  build(rc[o],rson);
}
int modify(int &o,int l,int r,int p){
  int oo=++node_cnt;lc[oo]=lc[o],rc[oo]=rc[o],sum[oo]=sum[o]+1;
  if(!(l^r)) return oo;
  if(p<=mid) lc[oo]=modify(lc[oo],lson,p);
  else rc[oo]=modify(rc[oo],rson,p);
  return oo;
}
int query(int u,int v,int l,int r,int k){
  int ans,x=sum[lc[v]]-sum[lc[u]];
  if(!(l^r)) return l;
  if(x>=k) ans=query(lc[u],lc[v],lson,k);
  else ans=query(rc[u],rc[v],rson,k-x);
  return ans;
}
int main(){
  int l,r,k,p;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i) scanf("%d",&a[i]),b[i]=a[i];
  sort(b+1,b+n+1);
  p=unique(b+1,b+n+1)-b-1;
  for(int i=1;i<=n;++i)
    root[i]=modify(root[i-1],1,p,lower_bound(b+1,b+p+1,a[i])-b);
  while(m--){
    scanf("%d%d%d",&l,&r,&k);
    printf("%d\n",b[query(root[l-1],root[r],1,p,k)]);
  }
  return 0;
}