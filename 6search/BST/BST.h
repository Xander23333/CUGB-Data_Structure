#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using std::ostream;
using std::string;using std::cerr;using std::endl;using std::cout;
using std::max;
using std::stack;

template<class T>
class BinTreeNode{
public:
  T data;
  BinTreeNode<T> *fa,*lson,*rson;
  BinTreeNode():lson(nullptr),rson(nullptr),fa(nullptr){};
  BinTreeNode(T x,BinTreeNode<T> *l = nullptr,
                  BinTreeNode<T> *r = nullptr, BinTreeNode<T> *f = nullptr):
        data(x),lson(l),rson(r),fa(f){};  
  BinTreeNode(const BinTreeNode<T> *x):lson(x->lson),rson(x->rson),fa(x->fa),data(x->data){}
};

template<class T>
class BST{
public:
  BST();
  BST(T A[],int n):elems(0),root(nullptr){build(A,n);}
  ~BST(){destroy(root);cout<<"Tree is released!\n";}
  void Print(ostream& os);
  void Insert(T x);
  void Del(T x);
  void Find(T x);
  T Min();

private:
  BinTreeNode<T> *root;
  int elems;
  void build(T A[],int n);
  void destroy(BinTreeNode<T> *root);
  void copy(BinTreeNode<T> *t,BinTreeNode<T> *s);
  void print(ostream& os,BinTreeNode<T>* t);
  void find(BinTreeNode<T>* t,T x); 
  void find_unrec(BinTreeNode<T>* t,T x); 
  bool insert(BinTreeNode<T>* t, T x);
  bool del(BinTreeNode<T>*& tt, T x);
  T min(BinTreeNode<T>* t);
};

template<class T>
BST<T>::BST():elems(0),root(nullptr){}
template<class T>
void BST<T>::destroy(BinTreeNode<T> *root){
  if (root==nullptr) return ;
  destroy(root->lson);destroy(root->rson);
  delete(root);
}
template<class T>
void BST<T>::build(T A[],int n){
  for(int i = 0;i<n;++i) Insert(A[i]);
  elems = n;
}
template<class T>
void BST<T>::Insert(T x){
  if (root == nullptr) {
    root = new BinTreeNode<T>(x);
    ++elems;
  }
  else{
    if (insert(root, x)) ++elems;
    else printf("insert fail!\n");
  }
}
template<class T>
bool BST<T>::insert(BinTreeNode<T>* t, T x){
  BinTreeNode<T>* tmp = new BinTreeNode<T>(x);
  while(t->data != x){
    if (x<t->data){
      if (t->lson == nullptr) {
        t->lson = tmp;tmp->fa = t;
        return true;
      }
      else t = t->lson;
    }
    else{
      if (t->rson == nullptr) {
        t->rson = tmp;tmp->fa = t;
        return true;
      }
      else t = t->rson;
    }
  }
  return false;
}
template<class T>
void BST<T>::Del(T x){
  if (root!=nullptr) if (del(root,x)) {
    printf("delete success!\n");
    return;
  }
  printf("no such a element!\n");
}
template<class T>
T BST<T>::Min(){
  if (root == nullptr) {printf("tree is null!\n");exit(1);}
  else return min(root);
}
template<class T>
T BST<T>::min(BinTreeNode<T>* t){
  while(t->lson!=nullptr) t = t->lson;
  return t->data;
}
template<class T>
bool BST<T>::del(BinTreeNode<T>*& tt, T x){
  BinTreeNode<T>** tmp = &tt;
  BinTreeNode<T>* t = tt;  
   while(t!=nullptr){
    // cout<<t->data<<" ";
    if (t->data == x){
      if (t->lson == nullptr) {
        (*tmp) = t->rson;
        if (t->rson != nullptr) t->rson->fa = t->fa;
        delete t;
        return true;
      }// 左孩子空或者全空
      else{
        if (t->rson == nullptr){
          (*tmp) = t->lson;
          t->lson->fa = t->fa;
          delete t;
          return true;       
        }// 左孩子非空右孩子空
        else{
          T q = min(t->rson);
          // cout<<"min = "<<q<<endl;
          del(t->rson,q);
          t->data = q;
          return true;
        }// 左右皆非空
      }
    }
    else{
      if (x < t->data) tmp = &(t->lson),t = t->lson;
      else tmp = &(t->rson),t = t->rson;
    }
  }
  return false;
}
template<class T>
void BST<T>::Print(ostream& os){
  print(os,this->root);os<<endl;
}
template<class T>
void BST<T>::print(ostream& os,BinTreeNode<T>* t){
  os<<t->data;
  if (t->lson!=nullptr || t->rson!=nullptr){
    os<<"(";
    if (t->lson!=nullptr) print(os,t->lson);
    os<<",";
    if (t->rson!=nullptr) print(os,t->rson);
    os<<")";
  }
}
template<class T>
void BST<T>::Find(T x){
  printf("-------rec--------\n");
  find(root,x);
  printf("-------unrec--------\n");
  find_unrec(root,x);
}
template<class T>
void BST<T>::find(BinTreeNode<T>* t,T x){// 返回的是真实指针
  if (t == nullptr) 
    cout<<"cannot find!\n";
  else{
    cout<<t->data<<" ";
    if (t->data == x) cout<<"finded!\n";
    else{
      cout<<"-> ";
      if (t->data > x) find(t->lson,x); 
      else find(t->rson,x);     
    }
  }
}
template<class T>
void BST<T>::find_unrec(BinTreeNode<T>* t,T x){
  while(t!=nullptr){
    cout<<t->data<<" ";
    if (t->data == x) {
      cout<<"finded!\n";
      break;
    }
    else{
      cout<<"-> ";
      if (t->data > x) t = t->lson; 
      else t = t->rson;     
    }
  }
}
#endif // BST_H

//zcm@cugb.edu.cn