#ifndef CircList_H
#define CircList_H
#include<iostream>
#include<algorithm>
using std::cout;using std::min;using std::endl;
template<class T>
class CircListNode{
public:
  CircListNode* link;
  T data;
  CircListNode(){}
  CircListNode(T x,CircListNode* link = nullptr):data(x),link(link){}
};
template<class T>
class CircList{
public:
  CircList();
  ~CircList();
  void Insert_back(T x){rear->link = new CircListNode<T>(x,rear->link);++sz;rear = rear->link;}
  void Insert(T x, int pos = 1);
  int Size(){return sz;}
  void Output();
  bool IsEmpty(){return head == rear;}
  T at(int pos = 0);
  int Search(T x);
  void Remove_pos(int pos = 0);
private:
  CircListNode<T> *head, *rear;
  int sz = 0;
};
template<class T>
CircList<T>::CircList(){
  head = new CircListNode<T>;
  head->link = head;
  rear = head;
  sz = 0;
}
template<class T>
CircList<T>::~CircList(){
  CircListNode<T>* tmp;
  while(!IsEmpty()){
    Remove_pos();
  }
  printf("delete success!\n");
}
template<class T>
void CircList<T>::Insert(T x, int pos){
  --pos;
  CircListNode<T>* tmp = head;
  for(int i=0;i<min(pos,sz);++i)
    tmp = tmp->link;
  tmp->link = new CircListNode<T>(x,tmp->link);
  if (tmp == rear) rear = rear->link;
  ++sz;
}
template<class T>
void CircList<T>::Output(){
  CircListNode<T>* tmp = head->link;
  while(tmp!=head){
    cout<<tmp->data;
    if(tmp!=rear) cout<<" -> ";else cout<<endl;
    tmp = tmp->link;
  }
}
template<class T>
T CircList<T>::at(int pos){
  if(pos<1) exit(1);
  CircListNode<T>* tmp = head;
  for(int i=0;i<min(pos,sz);++i){
    tmp = tmp->link;
  }
  return tmp->data;
}
template<class T>
int CircList<T>::Search(T x){
  CircListNode<T>* tmp = head->link;
  int cnt = 1;
  while(tmp!=head){
    if (tmp->data == x) return cnt;
    else {tmp = tmp->link;++cnt;}
  }
  return -1;
}
template<class T>
void CircList<T>::Remove_pos(int pos){
  --pos;
  CircListNode<T> * tmp2,* tmp = head;
  for(int i=0;i<min(pos,sz);++i)
    tmp = tmp->link;
  tmp2 = tmp->link;
  if (tmp2!=head){
    tmp->link = tmp2->link;
    if (rear == tmp2) rear = tmp;
    delete tmp2;
    --sz;
    printf("remove success!\n");
  }
  else printf("remove fail!\n");
}
#endif //CircList_H
