#include<iostream>
#include"heap.h"
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

#define fi first
#define se second

struct node{
  string str;
  int num,flag=0;
  node* lson = nullptr;
  node* rson = nullptr;
  node(int n,string s,int f = 0):num(n),str(s),flag(f){}
  node(const node& x):num(x.num),str(x.str),lson(x.lson),rson(x.rson),flag(x.flag){}
  node(){}
  bool operator < (const node& x){
    return this->num < x.num;
  }
  // operator = has defined initially
};
Heap<node> S;

struct item{
  string str,code;int num;
  bool operator < (const item& x){return x.code.length() > this->code.length();}
}Q[100];
int qtop = 0;
void print(const node& root,string code){
  if(root.flag) {
    // cout<<root.str<<endl;
    Q[qtop].str = root.str;Q[qtop].num = root.num;Q[qtop].code = code;
    qtop++;
  }
  if (root.lson!=nullptr) print(*(root.lson),code+"0");
  if (root.rson!=nullptr) print(*(root.rson),code+"1");  
}

int main(){
  freopen("huffman.txt","r",stdin);

  string str;int num;
  while(cin>>str){
    cin>>num;
    S.push(node(num,str,1));
  }

  node* tmp;
  while(S.size() > 1){
    tmp = new node;
    tmp->lson = new node(S.pop());
    tmp->rson = new node(S.pop());
    tmp->num = tmp->lson->num + tmp->rson->num;
    tmp->str = "";
    tmp->flag = 0;

    S.push(*tmp);
  }

  print(S.pop(),"");
  sort(Q,Q+qtop);
  cout<<"word\tnum\tcode\n";
  lp(i,qtop){
    cout<<Q[i].str<<"\t"<<Q[i].num<<"\t"<<Q[i].code<<"\n";
  }  
  fclose(stdin);
}