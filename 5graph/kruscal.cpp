#include<bits/stdc++.h>
#include"heap.h"
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

#define fi first
#define se second
#define pb push_back

int fa[20];
int findf(int x){
  if (fa[x]!=x) return fa[x] = findf(fa[x]);
  else return x;
}
void combine(int a,int b) {
  fa[findf(b)] = findf(a);
}

struct edge
{
  int u,v,w;
  edge(int u,int v,int w):u(u),v(v),w(w){}
  bool operator < (const edge& x)const{return w>x.w;}// const 表示常成员函数是放在参数括号后面的
};
priority_queue<edge> Q;

struct node{
  int dest,cost;
  node(int a,int b):dest(a),cost(b){}
};
vector<node> E[20];

int ans = 0;
int n,m;
void kruscal(){
  int cnt = 0;
  int u,v,w;
  while(cnt < n-1 && !Q.empty()){ // bug cnt 必须是 小于 n-1，因为cnt 永远到不了n
    u = Q.top().u,v = Q.top().v, w = Q.top().w;
    // cout<<u+1<<" "<<v+1<<" "<<w<<endl;
    Q.pop();
    // cout<<"size = "<<Q.size()<<endl;
    if (findf(u) != findf(v)) {
      E[u].pb(node(v,w));
      E[v].pb(node(u,w));
      combine(u,v);
      ans += w;
      ++cnt;
    }
  }
}

int main(){
  freopen("map2.txt","r",stdin);
  int u,v,w;
  cin>>n>>m;
  while(cin>>u>>v>>w){
    Q.push(edge(u-1,v-1,w));
  }
  fclose(stdin);

  lp(i,n) fa[i] = i;

  kruscal();

  cout<<"total cost: "<<ans<<endl;
  lp(i,n) {
    cout<<"V"<<i+1<<": ";
    for(auto e:E[i])
      cout<<" ( V"<<e.dest+1<<" "<<e.cost<<" ) ";
    cout<<endl;
  }
}