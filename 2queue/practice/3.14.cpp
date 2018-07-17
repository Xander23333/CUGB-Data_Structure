#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

int A[10]{0,20,19,220,18,29,30,10,22};//9

int maxd(int l,int r){
  // cout<<l<<" "<<r<<endl;
  if(l==r) return A[l];
  else return max(maxd(l,((l+r)>>1)),maxd(((l+r)>>1)+1,r));
}
int sumd(int l,int r){
  // cout<<l<<" "<<r<<endl;
  if(l==r) return A[l];
  else return sumd(l,((l+r)>>1))+sumd(((l+r)>>1)+1,r);
}
double aved(int l,int r){
  // cout<<l<<" "<<r<<endl;
  if(l==r) return A[l];
  else return ( aved(l,((l+r)>>1))*( ((l+r)>>1) - l + 1) 
              + aved(((l+r)>>1)+1,r) * (r - ((l+r)>>1)+1 ) )/(r-l+1);
}
int main(){
  cout<<maxd(1,8)<<endl;
  cout<<sumd(1,8)<<endl;
  cout<<aved(1,8)<<endl;
}