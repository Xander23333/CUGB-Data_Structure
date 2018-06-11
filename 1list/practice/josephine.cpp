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

struct node{
  int next;int data;
}S[1000];
void jose(int n,int s,int m){ // m>=2
  lp(i,n){
    S[i].data = i;S[i].next = i+1;
  }S[n-1].next = 0;
  int pos = s;

  while(S[pos].next!=pos){
    int key = pos;
    do {cout<<S[key].data<<" ";key = S[key].next;}while(pos!=key);cout<<endl;
    lp(i,m-2) pos = S[pos].next;
    S[pos].next = S[S[pos].next].next;
    pos = S[pos].next;
  }
  cout<<S[pos].data<<endl;
}

int main(){
  jose(6,0,3);
  // math(6,0,3);
}