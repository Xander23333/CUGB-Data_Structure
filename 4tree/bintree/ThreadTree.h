#ifndef T_BINARYTREE_H
#define T_BINARYTREE_H

// 中序线索二叉树

// 不要为了复用代码而继承，继承的目的是多态

// bug2 基类的指针如果指向派生类的对象，并不能调用派生类特有的数据成员和函数成员，只能调用派生对象覆盖的虚函数（因为虚函数是使用特殊的虚函数地址表调用）

#include"BinaryTree.h" // 头文件就是字符串替代

template<class T>
class ThreadNode{
public:
  T data;
  ThreadNode<T> *fa,*lson,*rson;
  int ltag = 0,rtag = 0;
  ThreadNode():lson(nullptr),rson(nullptr){};
  ThreadNode(T x,ThreadNode<T> *l = nullptr,
                  ThreadNode<T> *r = nullptr, ThreadNode<T> *f = nullptr):
        data(x),lson(l),rson(r),fa(f){} // for use ThreadNode(x)
  ThreadNode(const ThreadNode<T> *x):lson(x->lson),rson(x->rson),fa(x->fa),data(x->data),ltag(x->ltag),rtag(x->rtag){}
};

template<class T>
class ThreadTree{
public:
  ThreadTree():root(nullptr){}
  ThreadTree(const BinaryTree<T>& x);
  ~ThreadTree(){destroy (root);}
  void Traverse();
  void PreandNext(T x);
  void Insertlson(T x, T father);

  void print(){mid_unrec(root);cout<<endl;}// 中序
private:
  ThreadNode<T> *root;
  void copy(ThreadNode<T> * t,const BinTreeNode<T> *s);
  void destroy(ThreadNode<T> *rt);
  void threadlize(ThreadNode<T> *cur, ThreadNode<T> *& preptr);
  
  void mid_rec(ThreadNode<T>* t);
  void mid_unrec(ThreadNode<T>* t);
  void pre_rec(ThreadNode<T>* t);
  void pre_unrec(ThreadNode<T>* t);
  void post_rec(ThreadNode<T>* t);
  void post_unrec(ThreadNode<T>* t);
  void post_unrec2(ThreadNode<T>* t);

  ThreadNode<T>* last(ThreadNode<T>*);
  ThreadNode<T>* first(ThreadNode<T>*);
  ThreadNode<T>* next(ThreadNode<T>*);
  ThreadNode<T>* pre(ThreadNode<T>*);

  ThreadNode<T>* find(ThreadNode<T>* rt, T x);
};
template<class T>
ThreadTree<T>::ThreadTree(const BinaryTree<T>& x){
  if (x.Root() == nullptr) cerr<<"wrong !\n";// 常对象只能调用常函数
  root = new ThreadNode<T>(x.Root()->data);
  copy(root, x.Root());// bug，这里直接传指针的引用过去不行，因为函数的参数是基类指针，所以实际上传的是临时值，无法引用。
  ThreadNode<T> *preptr = nullptr;

  threadlize(root,preptr);
  preptr->rtag = 1;// 中序线索化过程无法将最右边的节点封口
}

template<class T>
void ThreadTree<T>::threadlize(ThreadNode<T> *cur, ThreadNode<T> *& preptr){
  if (cur == nullptr)  return;
  if (cur->lson != nullptr)
    threadlize(cur->lson, preptr);
  else {
    cur->lson = preptr;
    cur->ltag = 1;
  }
  if (preptr != nullptr && preptr->rson == nullptr){
    preptr->rson = cur;
    preptr->rtag = 1;
  }

  preptr = cur;
  threadlize(cur->rson, preptr);
}
template<class T>
void ThreadTree<T>::copy(ThreadNode<T> *t,const BinTreeNode<T> *s){
  if (s->lson != nullptr) {
    t->lson = new ThreadNode<T>(s->lson->data);    
    copy(t->lson,s->lson);
    t->lson->fa = t;
  }
  if (s->rson != nullptr) {
    t->rson = new ThreadNode<T>(s->rson->data);    
    copy(t->rson,s->rson);
    t->rson->fa = t;
  }
}
template<class T>
void ThreadTree<T>::destroy(ThreadNode<T> *s){
  if (s->lson != nullptr && s->ltag == 0) 
    destroy(s->lson);
  if (s->rson != nullptr && s->rtag == 0) 
    destroy(s->rson);
  delete(s);
}

template<class T>
ThreadNode<T>* ThreadTree<T>::first(ThreadNode<T>* t){
  while(t->ltag != 1) t = t->lson;
  return t;
}
template<class T>
ThreadNode<T>* ThreadTree<T>::last(ThreadNode<T>* t){
  while(t->rtag != 1) t = t->rson;
  return t;
}
template<class T>
ThreadNode<T>* ThreadTree<T>::next(ThreadNode<T>* t){
  if (t->rtag == 1) return t->rson;
  else return first(t->rson);
}
template<class T>
ThreadNode<T>* ThreadTree<T>::pre(ThreadNode<T>* t){
  if (t->ltag == 1) return t->lson;
  else return last(t->lson);
}

template<class T>
void ThreadTree<T>::mid_rec(ThreadNode<T> *t){
  if (t==nullptr) return;
  // cout<<t->data<<" "<<t->ltag<<" "<<t->rtag<<endl;
  if (t->ltag != 1) mid_rec(t->lson);
  cout<<t->data;
  if (t->rtag != 1) mid_rec(t->rson);  
}
template<class T>
void ThreadTree<T>::pre_rec(ThreadNode<T> *t){
  if (t==nullptr) return;
  cout<<t->data;
  if (t->ltag != 1) pre_rec(t->lson);
  if (t->rtag != 1) pre_rec(t->rson);  
}
template<class T>
void ThreadTree<T>::post_rec(ThreadNode<T> *t){
  if (t==nullptr) return;
  if (t->ltag != 1) post_rec(t->lson);
  if (t->rtag != 1) post_rec(t->rson);  
  cout<<t->data;
}
template<class T>
void ThreadTree<T>::mid_unrec(ThreadNode<T> *t){
  t = first(t);
  while(t!=nullptr){
    cout<<t->data;
    t = next(t);
  }
}
template<class T>
void ThreadTree<T>::pre_unrec(ThreadNode<T> *t){
  while(t != nullptr){
    cout<<t->data;
    if (t->ltag != 1) t = t->lson;
    else if (t->rtag != 1) t = t->rson;
    else{
      while(t!=nullptr && t->rtag == 1)
        t = t->rson;
      if (t != nullptr) t = t->rson;
    } 
  }
}
template<class T>
void ThreadTree<T>::post_unrec(ThreadNode<T> *t){
  while(t->rtag == 0 || t->ltag == 0)
    if (t->ltag == 0) t = t->lson;
    else t = t->rson;
  cout<<t->data;
  while(t->fa != nullptr){
    if (t == t->fa->rson || t->fa->rtag == 1) t = t->fa;
    else{
      t = t->fa->rson;
      while(t->rtag == 0 || t->ltag == 0)
        if (t->ltag == 0) t = t->lson;
        else t = t->rson;
    }
    cout<<t->data;
  }
} 
template<class T>
void ThreadTree<T>::post_unrec2(ThreadNode<T> *t){
  // 另外一种有趣的非递归不用栈后序遍历的思路————根右左，倒过来后序遍历
  string str = "";
  while(t != nullptr){
    str+=t->data;
    if (t->rtag != 1) t = t->rson;
    else if (t->ltag != 1) t = t->lson;
    else{
      while(t!=nullptr && t->ltag == 1)
        t = t->lson;
      if (t != nullptr) t = t->lson;
    } 
  } 
  std::reverse(str.begin(),str.end());
  cout<<str;
} 

template<class T>
void ThreadTree<T>::Traverse(){
  // 递归还是像普通二叉树一样
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
  printf("-----后序非递归1------\n");
  post_unrec(root);cout<<endl;
  printf("-----后序非递归2------\n");
  post_unrec2(root);cout<<endl;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::find(ThreadNode<T>* rt,T x){
  if (rt == nullptr) return nullptr;
  if (x == rt->data) return rt;
  ThreadNode<T>* ans;
  if ( rt->ltag == 0 && (ans = find(rt->lson,x)) != nullptr ) return ans;
  if ( rt->rtag == 0 && (ans = find(rt->rson,x)) != nullptr ) return ans;
  return nullptr;
}
template<class T>
void ThreadTree<T>::PreandNext(T x){
  ThreadNode<T>* t = find(root,x);
  if (t!=nullptr) {
    if (pre(t) != nullptr)
      cout<<"pre: "<<pre(t)->data<<"\t";
    if (next(t) != nullptr)
      cout<<"next: "<<next(t)->data;
    cout<<endl;
  }
}
template<class T>
void ThreadTree<T>::Insertlson(T x, T father){
  // 插入成为左孩子的特点是，在中序遍历中是父亲的相邻节点
  ThreadNode<T>* t = find(root,father);ThreadNode<T>* p = pre(t);

  ThreadNode<T>* tmp = new ThreadNode<T>(x,t->lson,t,t);
  tmp->rtag = 1;tmp->ltag = t->ltag;// 处理 插入的节点，

  if (t->ltag == 0) t->lson->fa = tmp;
  if (p!=nullptr && p->rtag == 1)
    p->rson = tmp;// 处理父亲的原左孩子和前趋
  
  t->lson = tmp;
  t->ltag = 0;// 处理父亲
}
#endif