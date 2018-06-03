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
  bool operator < (const node& x) const{return cost>x.cost;}
};
vector<node> E[20];
priority_queue<node> Q;

int n,m;
bool used[20]{};
int ans[20];
int pre[20];// 输出路径
void dijkstra(int rt){
  mem(used,0); 
  lp(i,n) ans[i] = INT_MAX/3;
  ans[rt] = 0;pre[rt] = -1;
  Q.push(node(rt,0));

  int cnt = 0;int v,w;
  while(cnt<n-1 && !Q.empty()){
    v = Q.top().dest, w = Q.top().cost;Q.pop();
    if (used[v] != 1){
      used[v] = 1;
      // cout<<v<<" "<<w<<endl;
      for(auto e:E[v]) 
        if (used[e.dest] != 1 && ans[e.dest] > e.cost + w){
          ans[e.dest] = e.cost+w;
          pre[e.dest] = v;
          Q.push(node(e.dest,ans[e.dest]));
        }
      ++cnt;
    }
  }

}

int main(){
  freopen("map824.txt","r",stdin);
  int u,v,w;
  cin>>n>>m;
  while(cin>>u>>v>>w){
    E[u].pb(node(v,w));
  }
  fclose(stdin);

  dijkstra(0);
  stack<int> S;
  lp(i,n) {
    printf("dist[%c] = %d\n",i+'A',ans[i]);
    // printf("pre[%c] = %d\n",i+'A',pre[i]);
    S.push(i);int p = pre[i];
    while(p!=-1){
      S.push(p);p = pre[p];
    }
    while(!S.empty()) {cout<<(char)('A'+S.top());S.pop();if (!S.empty()) cout<<" -> ";}
    cout<<endl;
  }
}