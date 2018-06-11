#include<iostream>
using namespace std;

int a[]{9,8,7,6,5,4,3,2,1,0};

int search(int key,int l,int r){
  int mid;
  while(l<r){
    mid = (l+r)/2;
    if (a[mid] == key) {
      l = r = mid;
      break;
    }
    else if (a[mid]<=key) l = mid;
    else r = mid;
  }
  return l;
}
void print(){for(int i=0;i<10;++i) cout<<a[i]<<" ";cout<<endl;}
int main(){
  int n = 10;
  for(int i=1;i<n;++i){
    int key = a[i];
    int pos = search(key,0,i-1);
    if (pos != -1)
    {
      for(int j=i;j>pos;--j) a[j] = a[j-1];
      a[pos] = key;
      print();
    }
    else printf("shit!\n");
  }
}