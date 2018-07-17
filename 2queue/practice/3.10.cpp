#include<iostream>
#include<string>
using namespace std;

struct node{
  char val;
  node* next;
  node(char val,node* ne):val(val),next(ne){}
  node(){};
};
node* head = new node(0,nullptr);
char stack[1000],top=0;

int main(){
  string str = "0123456789";
  node* pt;
  for (auto i:str){
    pt = new node(i,head->next);
    head->next = pt;
  }

  pt = head;
  while(pt->next!=nullptr){
    pt = pt->next;
    cout<<pt->val;
    stack[top++] = pt->val;
  }cout<<endl;

  while(top!=0){
    cout<<stack[--top];
  }cout<<endl;
}