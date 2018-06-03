#include<bits/stdc++.h>
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

struct node{
  char value;
  node *fa,*lson,*rson;//bug *只对一个起作用；cc niubi;
  node():lson(nullptr),rson(nullptr){}
}*root;

char ch;
node* get(char val){
  node* ans = new node;
  ans->value = val;
  cin>>ch;if (ch!='#') {ans->lson = get(ch);ans->lson->fa = ans;}else ans->lson = nullptr;
  cin>>ch;if (ch!='#') {ans->rson = get(ch);ans->rson->fa = ans;}else ans->rson = nullptr;
  return ans;
}
void bfs(node *root, char ans){
  stack<node*> S;
  if (root!=nullptr) S.push(root);
  node* tmp;
  while(!S.empty()){
    tmp = S.top();
    if (tmp->value == ans){
      while(tmp->fa != nullptr){
        cout<<tmp->value<<" <- ";
        tmp = tmp->fa;
      }cout<<tmp->value<<endl;
      break;
    }
    S.pop();
    if(tmp->lson!=nullptr) S.push(tmp->lson);
    if(tmp->rson!=nullptr) S.push(tmp->rson);    
  }
}
int main(){
  freopen("5.26.txt","r",stdin);
  cin>>ch;if (ch!='#') {root = get(ch);root->fa = nullptr;} else root = nullptr;
  bfs(root,'H');
  fclose(stdin);
}