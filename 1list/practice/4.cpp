#include<iostream>
#include<string>
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

struct node{
  int coef;
  int exp;
  int next;
  node(){}
  void make(int a,int b,int c = -1){next=c;exp = b;coef = a;}
};

class BigInt{
public:
  BigInt(){S[head].make(0,-1,-1);++top;Insert(0,0);}
  void Insert(int coef,int exp,int start=0);
  void Output();
  BigInt operator += (const BigInt& x);
  int Mid();
private:
  int base = 10;
  int sz = 0;
  int head = 0;
  node S[1000];
  int top = 0;
};
int BigInt::Mid(){
  int hight = S[S[head].next].exp;
  int mid = (hight+1)/2;
  cout<<"pos="<<mid<<endl;
  int tmp = head;
  while(S[tmp].next != -1 && S[S[tmp].next].exp >= mid ) {
    tmp = S[tmp].next;
    // cout<<S[tmp].coef<<" "<<S[tmp].exp<<endl;
  }
  if (S[tmp].exp == mid) 
    return S[tmp].coef;
  else return 0;
}
void BigInt::Insert(int coef,int exp,int start){
  int tmp = start;
  while(S[tmp].next != -1 && S[S[tmp].next].exp >= exp ) tmp = S[tmp].next;
  if (S[tmp].exp == exp) {
    S[tmp].coef += coef;
    if (S[tmp].coef >= base) {
      Insert(S[tmp].coef/base,exp+1,tmp);
      S[tmp].coef %= base;
    }
  }
  else{
    S[top].make(coef,exp,S[tmp].next);
    S[tmp].next = top;
    ++top;++sz;
  }
}
void BigInt::Output(){
  int tmp = S[head].next;
  while(S[tmp].next!=-1) {
    cout<<S[tmp].coef;
    lp(i,S[tmp].exp - S[S[tmp].next].exp-1) cout<<"0";
    tmp = S[tmp].next;
  }
  cout<<endl;
}
BigInt BigInt::operator += (const BigInt& x){
  int tmp = x.S[head].next;
  while(tmp!=-1) {this->Insert(x.S[tmp].coef,x.S[tmp].exp);tmp = x.S[tmp].next;}
  return *this;
}


BigInt A,B;
string a,b;
int main(){
  freopen("in4.txt","r",stdin);
  cin>>a>>b;
  lp(i,a.length()){
    if (a[i]-'0'!=0) A.Insert(a[i]-'0',a.length()-i-1);
  }
  lp(i,b.length()){
    if (b[i]-'0'!=0) B.Insert(b[i]-'0',b.length()-i-1);
  }
  fclose(stdin);  

  A.Output();
  B.Output();

  cout<<A.Mid()<<endl;
  cout<<B.Mid()<<endl;

  A+=B;
  A.Output();

}