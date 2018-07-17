#include<iostream>
#include"BST.h"
using namespace std;


int a[]{4,9,0,1,8,6,3,5,2,7};
int main(){
  printf("------------(1)----------\n");  
  BST<int> T(a,10);
  T.Print(cout);
  printf("------------(2)----------\n"); 
  cout<<"of course!\n"; 4ee4a2wqq2  1 `11 w
  printf("------------(3)----------\n");
  T.Find(6);
  printf("------------(4)----------\n");
  T.Del(4);
  T.Print(cout);
  T.Del(5);
  T.Print(cout);
}