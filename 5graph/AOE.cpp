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



struct node{
  int dest,cost;
  node(int a,int b):dest(a),cost(b){}
};
vector<node> E[20];

int ind[20];
int n,m;
int Ve[20],Vl[20];

stack<int> L,S;
bool used[20];
void dfs(int rt){
  for(auto e:E[rt])
    if (used[e.dest] == 0) {
      used[e.dest] = 1;
      dfs(e.dest);
    }
  L.push(rt);
}

int ans;
int sta[20],top = 0;
void dfs2(int rt){
  if (Ve[rt] == Vl[rt]) {
    sta[top++] = rt;
    if (E[rt].size() == 0) {
      ans = Ve[rt];
      lp(i,top) {cout<<sta[i];if (i!=top-1) cout<<" -> ";else cout<<endl;}
    }
    else 
      for(auto e:E[rt])
        dfs2(e.dest);
    --top;
  }
}

int main(){
  freopen("AOE.txt","r",stdin);
  int u,v,w;
  cin>>n>>m;
  while(cin>>u>>v>>w){
    E[u].pb(node(v,w));
    ++ind[v];
  }
  fclose(stdin);

  lp(i,n) if(ind[i] == 0) dfs(i);
  lp(i,n) Vl[i] = 1000000, Ve[i] = 0;
  lp(i,n){
    int u = L.top();L.pop();
    // cout<<u<<endl;
    if (E[u].size() == 0) Vl[u] = Ve[u];
    else for(auto e:E[u])
            Ve[e.dest] = max(Ve[e.dest],Ve[u] + e.cost);
    S.push(u);
  }

  lp(i,n){
    int u = S.top();S.pop();
    for(auto e:E[u])
      Vl[u] = min(Vl[u],Vl[e.dest] - e.cost);    
  }
  // lp(i,n) cout<<Ve[i]<<" "<<Vl[i]<<endl;
  cout<<"key paths: \n";
  lp(i,n) if(ind[i] == 0) dfs2(i);
  cout<<"longest time: ";
  cout<<ans<<endl;
}