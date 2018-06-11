#ifndef SET_H
#define SET_H

#include<iostream>
#include"List.h"
#include<algorithm>
#include<map>
using std::cout;using std::min;using std::endl;
using std::map;
template<class T>
class Set:public List<T>{
public:   
  Set(){}
  Set(const Set& x);
  Set<T> operator +=(Set& x);
  Set<T> operator ^=(Set& x);
  Set<T> operator -=(Set& x);
  void Insert_back(T x){List<T>::Insert_back(x);judge();}
  void Insert(T x, int pos = 1){List<T>::Insert(x,pos);judge();}
  using List<T>::head; // 使用父类的数据成员需要声明
  using List<T>::rear;
  using List<T>::sz;
private:
  void judge();
  void clear();
};
template<class T>
void Set<T>::judge(){
  map<T,int> ma;
  int cnt = 0;
  ListNode<T> *tmp2, *tmp = this->head;
  while(tmp!=nullptr && tmp->link!=nullptr){
    tmp2 = tmp->link;
    if (ma.count(tmp2->data)) {
      if (rear == tmp2) this->rear = tmp;
      tmp->link = tmp2->link;
      delete tmp2;
      --sz;
    }
    else ma[tmp2->data] = cnt++;
    tmp = tmp->link;
  }  
}
template<class T>
Set<T>::Set(const Set& x){
  head = new ListNode<T>;
  rear = head;
  ListNode<T>* tmp = x.head->link;
  while(tmp!=nullptr){
    rear->link = new ListNode<T>(tmp);
    rear = rear->link;
    ++sz;
    tmp = tmp->link;
  }
}
template<class T>
Set<T> Set<T>::operator +=(Set& x){
  for(int i=0;i<x.sz;++i) Insert_back(x.at(i+1));
  this->judge();
  return *this;
}
template<class T>
Set<T> Set<T>::operator ^=(Set& x){
  map<T,int> ma;
  // this->Output();  
  for(int i=0;i<sz;++i) ++ma[this->at(i+1)];
  // this->Output();  
  clear();
  for(int i=0;i<x.sz;++i) {
    if (ma.count(x.at(i+1))) {
      Insert_back(x.at(i+1));
    }
    // this->Output();
  }
  return *this;
}
template<class T>
void Set<T>::clear(){
  ListNode<T>* tmp;
  while(head->link!=nullptr){
    tmp = head->link;
    head->link = tmp->link;
    delete tmp;
    --sz;
  }
  rear = head;
  printf("clear success!\n");
}
template<class T>
Set<T> Set<T>::operator -=(Set& x){
  map<T,int> ma;
  for(int i=0;i<x.sz;++i) ++ma[x.at(i+1)];
  ListNode<T>* fa = head,* tmp = head->link;
  while(tmp!=nullptr){
    if (ma.count(tmp->data)) {
      fa->link = tmp->link;
      if(tmp == rear) rear = fa;
      delete tmp;
      tmp = fa;
      --sz;
    }
    fa = tmp;
    tmp = tmp->link;
    // this->Output();  
  }
  return *this;
}

#endif