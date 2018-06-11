#include<iostream>
#include"heap.h"
using namespace std;

int a[]{3,6,2,10,1,8,5,7,4,9};
Heap<int> H(a,10);
int main(){
  for(int i=0;i<10;++i){
    cout<<"gap = "<<i<<endl;
    a[i] = H.pop();
    cout<<"array: ";
    for(int j=0;j<=i;++j){
      cout<<a[j]<<" ";
    }cout<<endl;
    cout<<"heap: ";
    H.print();
    cout<<endl;
  }
}