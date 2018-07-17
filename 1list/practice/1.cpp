#include<iostream>
#include"List.h"
using namespace std;

int a[]{123,2,6,12,7,1,8,2,23,46};
List<int> L;
int main(){
  for(int i=0;i<10;++i) L.Insert_back(a[i]);
  L.Output();

  List<int> LL;
  int x = 10;
  for(int i=0;i<10;++i) {
    int tmp = L.at(i+1);
    if (tmp<x) LL.Insert(tmp);
  }
  for(int i=0;i<10;++i) {
    int tmp = L.at(i+1);
    if (tmp>=x) LL.Insert_back(tmp);
  }
  LL.Output();
}