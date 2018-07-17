#include<iostream>
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

struct node{
  db coef;
  int exp;
  int next;
  node(){}
  void make(db a,int b,int c = -1){next=c;exp = b;coef = a;}
};

class Polynomal{
public:
  Polynomal(){S[head].make(0,-1,-1);++top;}
  void Insert(db coef,int exp);
  void Output();
  Polynomal operator += (const Polynomal& x);
private:
  int sz = 0;
  int head = 0;
  node S[1000];
  int top = 0;
};
void Polynomal::Insert(db coef,int exp){
  int tmp = head;
  while(S[tmp].next != -1 && S[S[tmp].next].exp >= exp ) tmp = S[tmp].next;
  if (S[tmp].exp == exp) {
    S[tmp].coef += coef;
  }
  else{
    S[top].make(coef,exp,S[tmp].next);
    S[tmp].next = top;
    ++top;++sz;
  }
}
void Polynomal::Output(){
  int tmp = S[head].next;
  while(tmp!=-1) {cout<<S[tmp].coef<<"x^"<<S[tmp].exp<<" ";tmp = S[tmp].next;if (tmp!=-1) cout<<"+ ";}
  cout<<endl;
}
Polynomal Polynomal::operator += (const Polynomal& x){
  int tmp = x.S[head].next;
  while(tmp!=-1) {this->Insert(x.S[tmp].coef,x.S[tmp].exp);tmp = x.S[tmp].next;}
  return *this;
}


Polynomal A,B;
int main(){
  freopen("in3.txt","r",stdin);
  int n;db c;int e;
  cin>>n;
  lp(i,n){cin>>c>>e;A.Insert(c,e);}
  cin>>n;
  lp(i,n){cin>>c>>e;B.Insert(c,e);}
  fclose(stdin);  

  A.Output();
  B.Output();

  A+=B;
  A.Output();
}