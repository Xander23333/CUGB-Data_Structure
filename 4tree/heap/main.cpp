#include<iostream>
#include"heap.h"
using namespace std;

int a[]{1,7,9,4,8,2,3};
Heap<int> H;
int main(){
  for(int i=0;i<7;++i) H.insert(a[i]);
  H.print();

  H.change(2,18);
  H.print();
  H.change(0,100);
  H.print();
  H.change(6,0);
  H.print();

  int b[]{43,12,3};
  H.Heap_sort(a,7);
  for_each(a,a+7,[](int x){cout<<x<<" ";});cout<<endl;
  
  // while(!H.empty()) cout<<H.pop()<<" ";cout<<endl;
}