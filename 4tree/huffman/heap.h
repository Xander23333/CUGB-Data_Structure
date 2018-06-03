#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::copy;using std::swap;
using std::min;using std::max;
using std::for_each;
using std::cout;using std::endl;

// Small Root Pile. T must have defined '<‘ operator
template<class T>
class Heap{
public:
  Heap(){}
  Heap(const T a[],int n){build(a,n);}
  ~Heap(){}
  void build(const T a[],int n);
  bool empty(){return D.size() == 0;}
  void print(){for_each(D.begin(),D.end(),[](T x){cout<<x<<" ";});cout<<endl;}
  void push(T x);
  void update(int pos, T x);
  T pop();
  void Heap_sort(int a[],int n);
  int size(){return D.size();};
private:
  vector<T> D;
  void shiftdown(int pos);
  void shiftup(int pos);
  inline int lson(int pos){return (pos<<1|1);}
  inline int rson(int pos){return (pos<<1)+2;}
  inline int lastroot(){return (D.size()-1-1)/2;}
};

template<class T>
void Heap<T>::build(const T a[],int n){
  D.assign(a,a+n);
  for(int i = lastroot();i>=0;--i)
    shiftdown(i);
}
template<class T>
void Heap<T>::shiftdown(int pos){
  int L;
  while(pos<=lastroot()){
    L = pos;
    // printf("pos = %d data = %d\n",pos,D[pos]);    
    if (D[lson(pos)] < D[L]) L = lson(pos);
    if (rson(pos) < D.size() && D[rson(pos)] < D[L] ) L = rson(pos);
    // printf("pos = %d data = %d L = %d data = %d \n",pos,D[pos],L,D[L]);        
    if (pos != L) {
      swap(D[L],D[pos]);
      pos = L;
    }
    else break;
  }
}
template<class T>
void Heap<T>::shiftup(int pos){
  while(pos>0){
    if (D[pos] < D[(pos-1)>>1]) {
      swap(D[pos],D[(pos-1)>>1]);
      pos = (pos-1)>>1;
    }
    else break;
  }
}
template<class T>
T Heap<T>::pop(){
  T tmp = D[0];
  D[0] = D.back();
  D.pop_back();
  shiftdown(0);
  return tmp;
}
template<class T>
void Heap<T>::push(T x){
  D.push_back(x);
  shiftup(D.size()-1);
}
template<class T>
void Heap<T>::Heap_sort(int a[],int n){
  build(a,n);
  for(int i=0;i<n;++i)
    a[i] = this->pop();
}
template<class T>
void Heap<T>::update(int pos, T x){
  swap(x,D[pos]);
  if (x < D[pos]) shiftdown(pos);
  else shiftup(pos);
}

#endif