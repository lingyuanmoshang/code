#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
typedef __gnu_pbds::priority_queue<pii,greater<pii>,pairing_heap_tag> Heap;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int n,m,s;
struct Edge{
    int u,v,w;
    Edge(int _u=0,int _v=0,int _w=0){u=_u,v=_v,w=_w;}
};
vector<Edge> E;
vector<int> G[maxn];
void addedge(int u,int v,int w){
    E.push_back(Edge(u,v,w));
    G[u].push_back(E.size()-1);
}
int d[maxn];
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    Heap Q;
    Heap::point_iterator id[maxn];
    d[s]=0;
    id[s]=Q.push(make_pair(d[s],s));
    while(!Q.empty()){
        int u=Q.top().second; Q.pop();
        for(unsigned int i=0;i<G[u].size();i++){
            Edge &e=E[G[u][i]]; int v=e.v;
            if(d[v]>d[u]+e.w){
                d[v]=d[u]+e.w;
                if(id[v]!=0) Q.modify(id[v],make_pair(d[v],v));
                else id[v]=Q.push(make_pair(d[v],v));
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    dijkstra();
    for(int i=1;i<=n;i++) printf("%d%s",d[i],((i==n)?"\n":" "));
}