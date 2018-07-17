#include<iostream>
#include<string>
#include"BinaryTree.h"
#include"ThreadTree.h"
using namespace std;

BinaryTree<char> B;
string str = "ABC##E##DFH###G##";
int main(){
  B.BuildbyPre(str);
  ThreadTree<char> T(B);
  printf("------------(1)----------\n");  
  T.Traverse();  
  printf("------------(2)----------\n"); 
  // char ch;
  // cout<<"查询：";cin>>ch;
  T.PreandNext('E'); 
  printf("------------(3)----------\n");  
  T.Insertlson('@','B');
  T.print();
}