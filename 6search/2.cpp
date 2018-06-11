#include<iostream>
using namespace std;

int a[]{1,2,3,4,5,6,7,8,9,10};
int main(){
  int  key = 5;
  int mid, l = 0, r = 9;
  while(l<r){
    mid = (l+r)/2;
    if (a[mid] == key) {
      l = r = mid;
      break;
    }
    else if (a[mid]<key) l = mid;
    else r = mid;
  }
  if (a[l] != key) printf("can't find!\n");
  else printf("pos = %d\n", l);
}