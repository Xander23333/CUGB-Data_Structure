#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int N=10;
int n,m;
int stax,stay,desx,desy;
int maze[N][N];
struct node{
  node(){}
  node(int x,int y):x(x),y(y){}
  int x=1,y=1;
  bool operator == (node q){
    return (q.x == x && q.y == y);
  }
}path[N][N];
vector<node> ans0,ans;
int top=N*N+10;
node direc[4]{{1,0},{-1,0},{0,1},{0,-1}};
bool used[N][N];

void print_path(const vector<node>& ans){
  for (node p:ans){
    printf("(%d,%d)",p.x,p.y);
    if (!(p == ans.back())) printf(" -> ");
    else printf("\n");
  }
}
void dfs(int i,int j,int len){
  if (i==desx && j==desy){
    ans0.clear();
    int x = stax, y = stay;
    ans0.push_back( node(stax,stay) ); 
    while(x!=desx || y!=desy){
      node p = path[x][y];
      ans0.push_back( p ); 
      x = p.x; y = p.y;
    }
    print_path(ans0);    
    if (len < top) {
      ans = ans0;
      top = len;
    }
  }
  else{
    for (int d = 0;d < 4;++d){
      int qi = i+direc[d].x, qj = j+direc[d].y;
      if (!used[qi][qj] && !maze[qi][qj]){
        path[i][j] = node(qi,qj);
        used[qi][qj] = 1;
        dfs(qi,qj,len+1);
        used[qi][qj] = 0;
      }
    }
  }
}
//非递归需要记录当前节点搜索的状态，stu记录了下一步应该搜索的方向，若大于3则该节点搜索结束
node Stack[N*N+10];
int stu[N*N+10];
int topp = 0;
void push(int i,int j){
  Stack[topp] = node(i,j);
  stu[topp] = 0;
  used[i][j] = 1;
  topp++;
}
void pop(){
  topp--;  
  used[Stack[topp].x][Stack[topp].y] = 0;
}
void undfs(){
  push(stax,stay);
  node des(desx,desy);
  
  while(topp != 0){
    // cout<<Stack[topp-1].x<<" "<<Stack[topp-1].y<<" "<<stu[topp-1]<<endl;
    if (Stack[topp-1] == des){
      // cout<<"yes\n";
      ans0.clear();
      ans0.insert(ans0.end(),Stack,Stack+topp);
      print_path(ans0);    
      if (topp < top) {
        ans = ans0;
        top = topp;
      }
      pop();
    } 
    else{
      int i = Stack[topp-1].x,j = Stack[topp-1].y,sstu = stu[topp-1];
      if (sstu>3) pop();
      else{
        ++stu[topp-1];
        int qi = i+direc[sstu].x, qj = j+direc[sstu].y;
        if (!used[qi][qj] && !maze[qi][qj]) push(qi,qj);
      }
    }
  }
}
int main(){
  freopen("maze.txt","r",stdin);
  cin>>n>>m;
  for (int i = 0;i < n;++i)
    for (int j = 0;j < m;++j)
      cin>>maze[i][j];
  cin>>stax>>stay>>desx>>desy;

  printf("递归方法：\n");
  memset(used,sizeof used,0);
  used[stax][stay] = 1;  
  top = N*N;
  dfs(stax,stay,0);
  printf("the shortest:\n");  
  print_path(ans);  

  printf("\n非递归方法：\n");
  memset(used,sizeof used,0);
  used[stax][stay] = 1;  
  top = N*N;//top为当前最短路径的长度
  undfs();
  printf("the shortest:\n");  
  print_path(ans);  
}