#ifndef LIST_H
#define LIST_H
#include<iostream>
#include<algorithm>
using std::cout;using std::min;using std::endl;
template<class T>
class ListNode{
public:
  ListNode* link;
  T data;
  ListNode(){}
  ListNode(const ListNode* x):data(x->data),link(x->link){}
  ListNode(T x,ListNode* link = nullptr):data(x),link(link){}
};
template<class T>
class List{
public:
  List();
  ~List();
  void Insert_back(T x){rear->link = new ListNode<T>(x);++sz;rear = rear->link;}
  void Insert(T x, int pos = 1);
  int Size(){return sz;}
  void Output();
  bool IsEmpty(){return sz == 0;}
  T at(int pos = 0);
  int Search(T x);
  void Remove_pos(int pos = 0);
protected:
  ListNode<T> *head, *rear;
  int sz = 0;
};
template<class T>
List<T>::List(){
  head = new ListNode<T>;
  rear = head;
  sz = 0;
}
template<class T>
List<T>::~List(){
  ListNode<T>* tmp;
  while(head!=nullptr){
    tmp = head->link;
    delete head;
    head = tmp;
    --sz;
  }
  printf("delete success!\n");
}
template<class T>
void List<T>::Insert(T x, int pos){
  --pos;
  ListNode<T>* tmp = head;
  for(int i=0;i<min(pos,sz);++i)
    tmp = tmp->link;
  tmp->link = new ListNode<T>(x,tmp->link);
  if (tmp == rear) rear = rear->link;
  ++sz;
}
template<class T>
void List<T>::Output(){
  ListNode<T>* tmp = head->link;
  while(tmp!=nullptr){
    cout<<tmp->data;
    if(tmp!=rear) cout<<" -> ";else cout<<endl;
    tmp = tmp->link;
  }
}
template<class T>
T List<T>::at(int pos){
  if(pos<1) exit(1);
  ListNode<T>* tmp = head;
  for(int i=0;i<min(pos,sz);++i){
    tmp = tmp->link;
  }
  return tmp->data;
}
template<class T>
int List<T>::Search(T x){
  ListNode<T>* tmp = head->link;
  int cnt = 1;
  while(tmp!=nullptr){
    if (tmp->data == x) return cnt;
    else {tmp = tmp->link;++cnt;}
  }
  return -1;
}
template<class T>
void List<T>::Remove_pos(int pos){
  --pos;
  ListNode<T> * tmp2,* tmp = head;
  for(int i=0;i<min(pos,sz);++i)
    tmp = tmp->link;
  tmp2 = tmp->link;
  if (tmp2!=nullptr){
    tmp->link = tmp2->link;
    if (tmp2 == rear) rear = tmp2;
    delete tmp2;
    --sz;
    printf("remove success!\n");
  }
  else printf("remove fail!\n");
}
#endif //LIST_H
