#include<bits/stdc++.h>
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

const int N = 20;
const db eps = 1e-6;

int n,m;
int A[N][N];
int raw[N],col[N];
int main(){
  freopen("saddle.txt","r",stdin);
  cin>>n>>m;
  lp(i,n) lp(j,m) cin>>A[i][j];
  int tmp;
  lp(i,n){
    tmp = INT_MAX;
    lp(j,m){
      if (A[i][j]<tmp)
        tmp = A[i][j], raw[i] = j;
    }
  }
  lp(j,m){
    tmp = INT_MIN;
    lp(i,n){
      if (A[i][j]>tmp)
        tmp = A[i][j], col[j] = i;
    }
  }
  lp(i,n){
    if (col[raw[i]] == i) 
      printf("i = %d j = %d value = %d\n",i,raw[i],A[i][raw[i]]);
  }
}