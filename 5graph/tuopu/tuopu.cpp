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

map<int,string> name; 
vector<int> E[20];
int ind[20],oud[20];
int n = 9;

bool used[20];
stack<int> L;

void dfs(int rt){ 
  used[rt] = 1;
  for(auto e:E[rt]){
    if (used[e]!=1) dfs(e);
  }
  L.push(rt); // 当前节点dfs结束，所有依赖它的事件已经查找过，此时放入栈里保证在所有依赖它的事件发生之前发生
}

queue<int> Q;
void kahn(){
  lp(i,n) if (ind[i] == 0) {
    Q.push(i);
    used[i] = 1;
  }
  while(!Q.empty()){
    int i = Q.front();Q.pop();
    cout<<"V"<<i+1<<" "<<name[i]<<" ";

    for(auto e:E[i])
      if (used[e] != 1) {
        --ind[e];
        if (ind[e] == 0) {
          Q.push(e);
          // cout<<e<<endl;
          used[e] = 1;
        }
      } 
  }
  cout<<endl;
}

void clear(stack<int>& q) {
    stack<int> empty;
    swap(empty, q);
}
void print(){
  while(!L.empty()) {
    cout<<"V"<<L.top()+1<<" "<<name[L.top()];
    L.pop();
    if (!L.empty()) cout<<" -> ";
  }cout<<endl;
}
int main(){
  freopen("tuopu.txt","r",stdin);
  string line;
  string ma,na,pre;
  while(getline(cin,line)){
    stringstream ss(line);
    ss>>ma>>na;
    int q = ma[1]-'1';
    name[q] = na;
    while(ss>>pre){
      int p = pre[1]-'1'; 
      E[p].pb(q);   
      ++ind[q];
      ++oud[p];
    }
  }
  fclose(stdin);

  // lp(i,9) {cout<<ind[i]<<endl;for(auto e:E[i]) cout<<e+1<<" ";cout<<endl;}

  // dfs
  printf("-------DFS-----------\n");
  clear(L);//queue 不支持 clear 操作...
  mem(used,0);
  lp(i,n) if (ind[i] == 0) dfs(i);
  print();

  // kahn
  printf("-------KAHN-----------\n");
  clear(L);
  mem(used,0);
  kahn();
}