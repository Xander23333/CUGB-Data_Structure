#include<iostream>
#include"gen_list.h"
using namespace std;

GenList<char> L;

int main(){
  freopen("list.txt","r",stdin);
  printf("------------(1)----------\n");
  L.Input(cin);
  cout<<L<<endl;
  printf("------------(2)----------\n");
  cout<<"length = "<<L.Length()<<endl;
  printf("------------(3)----------\n");
  cout<<"depth = "<<L.Depth()<<endl;

  fclose(stdin);
} 