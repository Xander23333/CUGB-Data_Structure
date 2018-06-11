#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int a[]{3,6,2,10,1,8,5,7,4,9};

int gap = 0;
void print(){for(int i=0;i<10;++i) cout<<a[i]<<" ";cout<<endl;}
void qsort(int l,int r){
  if (l == r-1) return ;
  int pos = rand()%(r-l)+l;
  printf("l = %d r = %d pos = %d key = %d\n",l,r,pos,a[pos]);
  int sur = l+1;
  swap(a[l],a[pos]);
  for(int i=l+1;i<r;++i){
    if (a[i]<a[l]) {
      swap(a[i],a[sur]);++sur;
    }
  }
  swap(a[l],a[sur-1]);
  cout<<"gap = "<<gap++<<": ";print(); 
  qsort(l,sur-1);qsort(sur,r);
}
int main(){
  srand((unsigned)time(NULL));
  qsort(0,10);
}