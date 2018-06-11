#include<iostream>
#include"sparse.h"
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

int main(){
  freopen("sparse.txt","r",stdin);
  int n,m,v;

  cin>>n>>m;
  SparseMatrix<int> m1(n,m);
  lp(i,n) lp(j,m)
  {
    cin>>v;
    if (v != 0) m1.insert(i,j,v); 
  }

  cin>>n>>m;
  SparseMatrix<int> m2(n,m);
  lp(i,n) lp(j,m)
  {
    cin>>v;
    if (v != 0) m2.insert(i,j,v); 
  }

  printf("------------(1)----------\n");
  cout<<m1<<endl<<m2<<endl;
  printf("------------(2)----------\n");
  cout<<~m1<<endl;
  printf("------------(3)----------\n");
  cout<<m1 + m2<<endl;
  printf("------------(4)----------\n");
  cout<<m1 * m2<<endl;  

  fclose(stdin);
}