#include<iostream>
using namespace std;

int a[]{3,6,2,10,1,8,5,7,4,9};
int main(){
  for(int i=0;i<10;++i) 
    if (a[i] == 5) {
      printf("pos = %d\n",i);
      break;
    }
}