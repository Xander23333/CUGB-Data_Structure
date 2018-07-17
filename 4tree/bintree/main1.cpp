#include<iostream>
#include<string>
#include"BinaryTree.h"
using namespace std;

BinaryTree<char> T;
string str = "ABC##E##DFH###G##";
int main(){
  printf("------------(1)----------\n");  
  T.BuildbyPre(str);
  printf("------------(2)----------\n"); 
  T.Traverse(); 
  printf("------------(3)----------\n");
  T.Print(cout);
  printf("------------(4)----------\n");
  T.Sons('D');
  printf("------------(5)----------\n");
  cout<<T.Leaves()<<endl;
  printf("------------(6)----------\n");
  cout<<T.Height()<<endl;
  printf("------------(7)----------\n");
  cout<<T.Level('F')<<endl;
  printf("------------(8)----------\n");
}