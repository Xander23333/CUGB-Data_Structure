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

typedef pair<string,int> psi;
string str = "aababcabcdabcde";
vector< psi > ans;
string substr;

bool cmp(psi a,psi b){
  if (a.fi.length() == b.fi.length())
    return a.se>b.se;
  else return a.fi.length()>b.fi.length();
}
int sfind(const string& ps, const string& ds){
  int cnt = 0;
  lp(i,ps.length()-ds.length()+1){
    bool flag = true;
    lp(j,ds.length()){
      if (ps[i+j] != ds[j]) {
        flag = false;
        break;
      } 
    }
    if (flag) cnt ++ ;
  }
  return cnt;
}
int main(){
  int len = str.length();
  int cnt;
  rlp(leng,len-1,1){
    lp(i,len-leng+1){
      substr = str.substr(i,leng);
      // cout<<substr<<endl;
      cnt = sfind(str,substr);
      if (cnt>=2){
        ans.pb( psi(substr,cnt) );
      }
    }
  }
  sort(ans.begin(),ans.end(),cmp);
  for_each(ans.begin(),ans.end(),[](psi a){cout<<a.fi<<" "<<a.se<<endl;});
}