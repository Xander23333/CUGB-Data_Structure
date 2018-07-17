#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
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

const int N = 200;

int nex[N];
void getnext(const string& str){
  nex[0] = 0;
  for(int p=1,k=0;p<str.length();++p){
    while(k!=0 && str[p] != str[k])
      k = nex[k-1];
    if (str[p] == str[k]) ++k;
    nex[p] = k;
  }
}
int kmp(const string& s,const string& t){
  int cnt = 0;
  int p=0,k=0;
  while(p<s.length()){
    while(k!=0 && s[p] != t[k]){
      printf("unmatched! s[%d] = %c, t[%d] = %c, k -> %d\n",p,s[p],k,t[k],nex[k-1]);
      k = nex[k-1];
    }
    
    while(s[p] == t[k] && k<t.length()) {
      printf("matched! s[%d] = %c, t[%d] = %c\n",p,s[p],k,t[k]);
      ++p,++k;
    }
    if (k == 0) ++p;
    else if (k == t.length()) {
      k = nex[k-1];
      ++ cnt;
      printf("success! k -> %d\n",k);
    }
  }
  printf("finished!\n");
  return cnt;
}

string s = "aaabbdaabbdaabe",t = "aabbdaab";
int main(){
  cout<<"s = "<<s<<"\nt = "<<t<<endl;
  getnext(t);
  cout<<"next:\n";
  lp(i,s.length()) cout<<nex[i]<<" ";cout<<endl;
  printf("answer = %d\n",kmp(s,t));
}