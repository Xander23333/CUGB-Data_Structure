#ifndef DBLLIST_H
#define DBLLIST_H
#include<iostream>
#include<algorithm>
using std::cout;using std::min;using std::endl;
template<class T>
class DblNode{
public:
  DblNode *lLink,*rLink;
  T data;
  DblNode(){}
  DblNode(T x,DblNode* l = nullptr, DblNode* r = nullptr):data(x),lLink(l),rLink(r){}
};
template<class T>
class DblList{
public:
  DblList();
  ~DblList();
  void Insert_back(T x){rear->rLink = new DblNode<T>(x,rear);rear = rear->rLink;++sz;}
  void Insert(T x, int pos = 1);
  int Size(){return sz;}
  void Output();
  bool IsEmpty(){return sz == 0;}
  T at(int pos = 0);
  int Search(T x);
  void Remove_pos(int pos = 0);
private:
  DblNode<T> *head, *rear;
  int sz = 0;
};
template<class T>
DblList<T>::DblList(){
  head = new DblNode<T>;
  rear = head;
  sz = 0;
}
template<class T>
DblList<T>::~DblList(){
  DblNode<T>* tmp;
  while(head!=nullptr){
    tmp = head->rLink;
    delete head;
    head = tmp;
    --sz;
  }
  printf("delete success!\n");
}
template<class T>
void DblList<T>::Insert(T x, int pos){
  --pos;
  DblNode<T>* tmp = head;
  for(int i=0;i<min(pos,sz);++i)
    tmp = tmp->rLink;
  tmp->rLink = new DblNode<T>(x,tmp,tmp->rLink);
  if (tmp == rear) rear = rear->rLink;
  ++sz;
}
template<class T>
void DblList<T>::Output(){
  DblNode<T>* tmp = head->rLink;
  while(tmp!=nullptr){
    cout<<tmp->data;
    if(tmp!=rear) cout<<" -> ";else cout<<endl;
    tmp = tmp->rLink;
  }
}
template<class T>
T DblList<T>::at(int pos){
  if(pos<1) exit(1);
  DblNode<T>* tmp = head;
  for(int i=0;i<min(pos,sz);++i){
    tmp = tmp->rLink;
  }
  return tmp->data;
}
template<class T>
int DblList<T>::Search(T x){
  DblNode<T>* tmp = head->rLink;
  int cnt = 1;
  while(tmp!=nullptr){
    if (tmp->data == x) return cnt;
    else {tmp = tmp->rLink;++cnt;}
  }
  return -1;
}
template<class T>
void DblList<T>::Remove_pos(int pos){
  --pos;
  DblNode<T> * tmp2,* tmp = head;
  for(int i=0;i<min(pos,sz);++i)
    tmp = tmp->rLink;
  tmp2 = tmp->rLink;
  if (tmp2!=nullptr){
    tmp->rLink = tmp2->rLink;
    if (tmp2 == rear) rear = tmp2;
    delete tmp2;
    --sz;
    printf("remove success!\n");
  }
  else printf("remove fail!\n");
}
#endif //DBLLIST_H
