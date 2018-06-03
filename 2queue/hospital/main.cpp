#include<iostream>
#include<string>
#include "SeqQueue.h"
using namespace std;

SeqQueue<string> Q; 

int menu(){
  int t;
  while(true){
    printf("\t\tMenu\n");
    printf("================================================\n");
    printf("  1. 排队\n");
    printf("  2. 就诊\n");
    printf("  3. 查看排队\n");
    printf("  4. 余下依次就诊\n");
    printf("  5. 退出系统\n");
    printf("================================================\n");
    printf("请输入功能编号(1-5):  ");
    cin>>t;//输入字母会死循环，如何解决？
    if (t<1 || t>5) printf("请输入正确的编号！\n");
    else break;
  }
  return t;
}

int main(){
  int ope;
  string str;
  while( (ope=menu()) != 5){
    switch(ope){
      case 1:
        printf("请输入病历号：  ");
        cin>>str;
        Q.EnQueue(str);
        break;
      case 2:
        if (Q.DeQueue(str) )
          cout<<str<<" 已就诊\n";
        else printf("当前没有人在排队！\n");
        break;
      case 3:
        cout<<Q<<endl;
        break;
      case 4:
        cout<<Q<<" 已就诊"<<endl;
        Q.makeEmpty();
        break;
    }
  }
  printf("欢迎下次使用！\n");
}