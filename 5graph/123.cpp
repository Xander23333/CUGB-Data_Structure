#include<bits/stdc++.h>
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

int n,m;
int matrix[10][10]{},matrix2[10][10]{};


struct edge{
  int dest,cost = 0;
  edge(int a,int b):dest(a),cost(b){}
};
vector<edge> E[10];

bool used[10];
void dfs(int rt){
  cout<<rt+1<<" ";
  used[rt] = 1;
  for(auto e:E[rt]){
    if (used[e.dest] == 0) dfs(e.dest);
  }
}
void dfs_unrec(int rt){
  mem(used,0);
  stack<int> S;
  S.push(rt);used[rt] = 1; 
  while(!S.empty()){
    int p = S.top();S.pop(); 
    cout<<p+1<<" ";   
    for(auto e:E[p])
      if (used[e.dest] != 1) {
        S.push(e.dest);
        used[e.dest] = 1;
      }
  }
  cout<<endl;
}
void bfs(int rt){
  mem(used,0);
  queue<int> Q;
  Q.push(rt);used[rt] = 1;
  while(!Q.empty()){
    int p = Q.front();Q.pop();
    cout<<p+1<<" ";   
    for(auto e:E[p])
    if (used[e.dest] != 1) {
      Q.push(e.dest);
      used[e.dest] = 1;
    }
  }
  cout<<endl;
}

int main(){
  freopen("map2.txt","r",stdin);
  cin>>n>>m;
  lp(i,n) lp(j,n) if (i!=j) matrix[i][j] = INT_MAX;else matrix[i][j] = 0;
  int u,v,w;
  lp(i,m){
    cin>>u>>v>>w;
    matrix[u-1][v-1] = w;
  }
  fclose(stdin);

  printf("------------题目一----------\n"); 
  printf("------------(1)----------\n");  
  lp(i,n){
    lp(j,n) 
      if (matrix[i][j] == INT_MAX)
        cout<<"inf"<<"\t";
      else cout<<matrix[i][j]<<"\t";
    cout<<endl;
  }

  printf("------------(2)----------\n"); 
  lp(i,n) lp(j,n)
    if (matrix[i][j] != INT_MAX && i!=j){
      E[i].pb(edge(j,matrix[i][j]));
    }
  lp(i,n){
    cout<<"v"<<i+1;
    for(auto e:E[i]){
      cout<<" -> ( v"<<e.dest+1<<", "<<e.cost<<" )";
    }
    cout<<endl;
  }

  printf("------------(3)----------\n"); 
  lp(i,n) lp(j,n) if (i!=j) matrix2[i][j] = INT_MAX;else matrix2[i][j] = 0;
  lp(i,n){
    for(auto e:E[i]){
      matrix2[i][e.dest] = e.cost;
    }
  }
  lp(i,n){
  lp(j,n) 
    if (matrix2[i][j] == INT_MAX)
      cout<<"inf"<<"\t";
    else cout<<matrix2[i][j]<<"\t";
    cout<<endl; 
  }

  printf("\n------------题目二----------\n"); 
  printf("------------(1)----------\n");
  mem(used,0);
  dfs(0); cout<<endl;
  printf("------------(2)----------\n"); 
  dfs_unrec(0);
  printf("------------(3)----------\n"); 
  bfs(0);

  printf("\n------------题目三----------\n"); 
  int index[10]{};
  lp(i,n)
    for(auto e:E[i])
      ++index[e.dest];
  lp(i,n) cout<<"v"<<i+1<<": "<<index[i]<<endl;
}