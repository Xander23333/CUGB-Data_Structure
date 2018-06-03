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
vector<node> E[20],F[20];

int n,m;
bool used[20]{};
int ans;
void prime(int rt){
  mem(used,0); 
  used[rt] = 1;
  for(auto e:E[rt]) 
    if (used[e.dest] != 1) Q.push(edge(rt,e.dest,e.cost));
  int cnt = 0;
  int u,v,w;
  // cout<<Q.size()<<endl;
  while(cnt<n-1 && !Q.empty()){
    u = Q.top().u,v = Q.top().v, w = Q.top().w;
    Q.pop();
    // cout<<u+1<<" "<<v+1<<" "<<w<<endl;
    if (used[v] == 0){
      used[v] = 1;
      for(auto e:E[v]) 
        if (used[e.dest] != 1) Q.push(edge(v,e.dest,e.cost));

      F[u].pb(node(v,w));
      F[v].pb(node(u,w));
      ++cnt;
      ans += w;
    }
  }
}

int main(){
  freopen("map2.txt","r",stdin);
  int u,v,w;
  cin>>n>>m;
  while(cin>>u>>v>>w){
    E[u-1].pb(node(v-1,w));
    E[v-1].pb(node(u-1,w));
  }
  fclose(stdin);

  prime(0);
  cout<<"total cost: "<<ans<<endl;
  lp(i,n) {
    cout<<"V"<<i+1<<": ";
    for(auto e:F[i])
      cout<<" ( V"<<e.dest+1<<" "<<e.cost<<" ) ";
    cout<<endl;
  }
}