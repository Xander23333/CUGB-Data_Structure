#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int A[1000];
int B[1000];
bool b[1000];

int n;
void permu(int pos){
  if (pos == n+1){
    for(int i=1;i<=n;++i){
      cout<<B[i]<<" ";
    }cout<<endl;
  }
  for(int i=1;i<=n;++i){
    if (b[i]==false){
      b[i] = true;
      B[pos] = i;
      permu(pos+1);
      b[i] = false;
    }
  }
}

int main(){
  cin>>n;
  for(int i=1;i<=n;++i) A[i]=i;
  memset(b,false,sizeof b);
  permu(1);
}