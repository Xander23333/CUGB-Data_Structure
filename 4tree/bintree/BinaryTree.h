#ifndef BINTREE_H
#define BINTREE_H

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
class BinaryTree{
public:
  BinaryTree();
  BinaryTree(const BinaryTree<T>& x);
  ~BinaryTree(){destroy(root);cout<<"Tree is released!\n";}
  void BuildbyPre(const string& pre);//only for char tree
  void Print(ostream& os);
  int Leaves(){return leaves;}
  int Height(){return height;}
  int Elems(){return elems;}
  int Level(T x){return getlevel(find(root, x));};
  void Sons(T x);
  void Traverse();

  BinTreeNode<T>* Root() const {return root;}// for threadtree use

private:
  BinTreeNode<T> *root;
  int height, leaves, elems;
  void destroy(BinTreeNode<T> *root);
  BinTreeNode<T>* GetbyPre(const string& pre,int& pos);
  void print(ostream& os,BinTreeNode<T>* t);
  int getDepth(BinTreeNode<T> *t);
  BinTreeNode<T>* find(BinTreeNode<T>* t,T x);  
  int getlevel(BinTreeNode<T>* t);
  void copy(BinTreeNode<T> *t,BinTreeNode<T> *s);

  void mid_rec(BinTreeNode<T>* t);
  void mid_unrec(BinTreeNode<T>* t);
  void pre_rec(BinTreeNode<T>* t);
  void pre_unrec(BinTreeNode<T>* t);
  void post_rec(BinTreeNode<T>* t);
  void post_unrec(BinTreeNode<T>* t);
};

template<class T>
BinaryTree<T>::BinaryTree():height(0),leaves(0),elems(0),root(nullptr){}
template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& x):height(x.height),leaves(x.leaves),elems(x.elems){
  root = new BinTreeNode<T>(x.root);
  copy(this->root,x.root);
}
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *root){
  if (root==nullptr) return ;
  destroy(root->lson);destroy(root->rson);
  delete(root);
}
template<class T>
void BinaryTree<T>::copy(BinTreeNode<T> *t,BinTreeNode<T> *s){
  if (s->lson != nullptr) {
    t->lson = new BinTreeNode<T>(s->lson);
    copy(t->lson, s->lson);
    t->lson->fa = t;
  }
  if (s->rson != nullptr) {
    t->rson = new BinTreeNode<T>(s->rson);
    copy(t->rson, s->rson);
    t->rson->fa = t;
  }
}
template<class T>
void BinaryTree<T>::BuildbyPre(const string& pre){
  height = leaves = elems = 0;
  if (pre[0]!='#') {
    int pos = 0;
    root = GetbyPre(pre,pos);
    root->fa = nullptr;
    height = getDepth(root);
  } 
  else cerr<<"空树！\n";
}
template<class T>
BinTreeNode<T>* BinaryTree<T>::GetbyPre(const string& pre,int& pos){
  // cout<<pre[pos]<<endl;
  BinTreeNode<T>* ans = new BinTreeNode<T>(pre[pos++]);

  if (pre[pos]!='#') {
    ans->lson = GetbyPre(pre,pos);
    ans->lson->fa = ans;
  }
  else {
    ans->lson = nullptr;
    ++pos;
  }

  if (pre[pos]!='#') {
    ans->rson = GetbyPre(pre,pos);
    ans->rson->fa = ans;
  }
  else {
    ans->rson = nullptr;
    ++pos;
  }
  if (ans->lson == nullptr && ans->rson == nullptr) ++leaves;
  ++elems;
  return ans;
}
template<class T>
void BinaryTree<T>::Print(ostream& os){
  print(os,this->root);os<<endl;
}
template<class T>
void BinaryTree<T>::print(ostream& os,BinTreeNode<T>* t){
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
int BinaryTree<T>::getDepth(BinTreeNode<T> *root){
  if (root == nullptr) return 0;
  else return max( getDepth(root->lson),getDepth(root->rson) )+1;
}
// template<class T>
// BinTreeNode<T>* BinaryTree<T>::Find(T x){
//   return find(root,x);
// }
template<class T>
BinTreeNode<T>* BinaryTree<T>::find(BinTreeNode<T>* t,T x){
  if (t == nullptr) return nullptr;
  if (t->data == x) return t;
  BinTreeNode<T>* ans;
  if ( (ans = find(t->lson,x)) != nullptr ) return ans;
  if ( (ans = find(t->rson,x)) != nullptr ) return ans;
  return nullptr;
}
template<class T>
int BinaryTree<T>::getlevel(BinTreeNode<T>* t){
  if (t==nullptr) {
    cerr<<"element not exist!\n";
    exit(1);
  }
  int level = 1;
  while(t!=this->root){
    t = t->fa;
    ++level;
  }
  return level;
}
template<class T>
void BinaryTree<T>::Sons(T x){
  BinTreeNode<T>* t = find(root,x);
  if (t!=nullptr)
    printf("node %c  lson = %c rson = %c\n",t->data,t->lson->data,t->rson->data);
}

template<class T>
void BinaryTree<T>::mid_rec(BinTreeNode<T>* t){
  if (t==nullptr) return;
  mid_rec(t->lson);
  cout<<t->data;
  mid_rec(t->rson);
}
template<class T>
void BinaryTree<T>::mid_unrec(BinTreeNode<T>* t){
  stack<BinTreeNode<T>*> S;
  string ans;
  while(t!=nullptr) {
    S.push(t);
    t = t->lson;
  }
  while(!S.empty()){
    t = S.top();S.pop();
    ans += t->data;
    if (t->rson!=nullptr){
      t = t->rson;
      while(t != nullptr) {
        S.push(t);
        t = t->lson;
      }
    }
  }
  cout<<ans;
}
template<class T>
void BinaryTree<T>::pre_rec(BinTreeNode<T>* t){
  if (t==nullptr) return;
  cout<<t->data;
  pre_rec(t->lson);
  pre_rec(t->rson);
}
template<class T>
void BinaryTree<T>::pre_unrec(BinTreeNode<T>* t){
  stack<BinTreeNode<T>*> S;
  string ans;
  S.push(t);
  while(!S.empty()){
    t = S.top();S.pop();
    ans += t->data;
    if (t->rson != nullptr) S.push(t->rson);    
    if (t->lson != nullptr) S.push(t->lson);
  }
  cout<<ans;  
}
template<class T>
void BinaryTree<T>::post_rec(BinTreeNode<T>* t){
  if (t==nullptr) return;
  post_rec(t->lson);
  post_rec(t->rson);
  cout<<t->data;
}
template<class T>
void BinaryTree<T>::post_unrec(BinTreeNode<T>* t){
  stack<BinTreeNode<T>*> S;
  bool *used = new bool[elems];
  BinTreeNode<T>* lastroot = nullptr;
  string ans;
  while(t!=nullptr) {
    S.push(t);
    t = t->lson;
  }
  while(!S.empty()){
    t = S.top();//每个取出的点都遍历完了左孩子
    if (t->rson!=nullptr && t->rson != lastroot){
      t = t->rson;
      while(t != nullptr) {
        S.push(t);
        t = t->lson;
      }
    }
    else {
      ans += t->data;
      lastroot = t;
      S.pop();
    }
  }
  cout<<ans;   
}
template<class T>
void BinaryTree<T>::Traverse(){
  printf("-----中序递归-------\n");
  mid_rec(root);cout<<endl;
  printf("-----中序非递归------\n");
  mid_unrec(root);cout<<endl;
  printf("-----先序递归--------\n");
  pre_rec(root);cout<<endl;
  printf("-----先序非递归------\n");
  pre_unrec(root);cout<<endl;
  printf("-----后序递归--------\n");
  post_rec(root);cout<<endl;
  printf("-----后序非递归------\n");
  post_unrec(root);cout<<endl;
}
#endif // BINTREE_H