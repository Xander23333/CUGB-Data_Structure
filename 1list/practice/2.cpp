#include<iostream>
#include"Set.h"
using namespace std;

Set<int> S1,S2,S3;
int a[]{12,41,123,512,123}, b[]{123,123,12,43,5};
int main(){
  for(int i=0;i<5;++i) S1.Insert_back(a[i]); 
  S1.Output();
  for(int i=0;i<5;++i) S2.Insert_back(b[i]); 
  S2.Output();

  printf("\nS1-S2:\n");
  S1-=S2;
  S1.Output();

  printf("\nS1-S2+S2:\n");
  S1+=S2;
  S1.Output();

  printf("\nS1^S2:\n");
  S1^=S2;
  S1.Output();

  printf("\n");
}   