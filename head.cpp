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

void print(const int a[],int n){
  for_each(a,a+n,[](int x){cout<<x<<" ";});cout<<endl;  
}
class ab{
public:
  ab(int a,int b):a(a),b(b){}
  ab(){}
  virtual void adawd(int a){cout<<"shit"<<endl;}
  virtual void que(){cout<<"1"<<endl;}
protected:
  int a,b;
};
class ab2:public ab{
public:
  // virtual void adawd(double a) override{cout<<"shit2"<<endl;}
  void k(ab q){que();cout<<212<<endl;}
  // virtual void que() override{ab::que();cout<<"2"<<endl;}
};

int main(){
  string line,word;
  while(getline(cin,line))
  {
    stringstream stream(line);
    cout<<stream.str()<<endl;
    while(stream>>word){cout<<word<<endl;}
  }
  // ab2 x1;
  // int a= 1;double b = 2;
  // x1.adawd(a);
  // x1.adawd(b);
  
  // ab x1,x2(1,2);
  // x1 = x2;
  // cout<<x1.a<<" "<<x2.b<<endl;

  // vector<int> q;
  // int a[]{1,2,3,4,45,5,7,8,9};
  // q.assign(a,a+7);
  // for_each(q.begin(),q.end(),[](int x){cout<<x<<" ";});cout<<endl;
  // cout<<q.size()<<endl;
  // q.assign(a,a+3);
  // for_each(q.begin(),q.end(),[](int x){cout<<x<<" ";});cout<<endl;
  // cout<<q.size()<<endl;
  // print(a,7);
}