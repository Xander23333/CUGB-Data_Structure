#ifndef GEN_LIST_H
#define GEN_LIST_H

#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>
using std::cerr;using std::endl;using std::cout;
using std::string;using std::stringstream;
using std::stack;using std::max;
using std::ostream;using std::istream;

template<class T>
struct GenListNode{
  int utype;
  GenListNode<T>* tlink;
  union{
    int ref;
    T value;
    GenListNode<T>* hlink;
  }info;
  GenListNode():utype(0){info.ref = 0;}
  GenListNode(const GenListNode& x):utype(x.utype),tlink(x.tlink),info(x.info){} 
  friend ostream& operator << (ostream& os,const GenListNode<T>& x){
    os<<"type = "<<x.utype<<" info = ";
    switch(x.utype){
      case 0:os<<x.info.ref;break;
      case 1:os<<x.info.value;break;
      case 2:os<<x.info.hlink;break;
    }
    return os;
  }
};

template<class T>
class GenList{
  friend ostream& operator << (ostream& os,const GenList<T>& L){
    L.printlist(os,L.first);//bug 调用了常对象的非常函数，不合适
  }
public:
  GenList();
  ~GenList();
  GenListNode<T>* First(){return first->hlink;}
  bool IsNull(){return first->tlink == nullptr;};
  GenListNode<T>* Next(GenListNode<T>* elem){return elem->tlink;}
  // void Copy(const GenList<T>& R);
  int Length();
  int Depth();
  void Input(istream& is);
  bool operator == (const GenList<T>& L){
    return equal(this->first,L.first);
  }
private:
  GenListNode<T>* first;
  int depth(GenListNode<T>* ls);
  bool equal(GenListNode<T>* s,GenListNode<T>* t);
  void Remove(GenListNode<T>* ls);
  T trans(string str);
  void input(istream& is, GenListNode<T>* cur);
  void printlist(ostream& os,GenListNode<T>* ls) const;
};

template<class T>
GenList<T>::GenList(){
  first = new GenListNode<T>;
}
template<class T>
GenList<T>::~GenList(){
  Remove(this->first);
}
template<class T>
int GenList<T>::Length(){
  GenListNode<T>* p = this->first->tlink;
  int cnt = 0;
  while(p != nullptr){
    ++ cnt;
    p = p->tlink;
  }
  return cnt;
}
template<class T>
int GenList<T>::Depth(){
  return depth(first);
}
template<class T>
int GenList<T>::depth(GenListNode<T>* ls){
  GenListNode<T>* p = ls->tlink;
  int dep = 1 , tmp;
  while(p != nullptr){
    if (p->utype == 2)
      dep = max(dep, depth(p->info.hlink)+1);
    p = p->tlink;
  }
  return dep;
}
template<class T>
void GenList<T>::Remove(GenListNode<T>* ls){
  if (ls->tlink != nullptr) 
    Remove(ls->tlink);
  if (ls->utype == 2)
    Remove(ls->info.hlink);
  // cout<<*ls<<" delete success!\n";
  delete ls;
}
template<class T>
bool equal(GenListNode<T>* s,GenListNode<T>* t){
    if (s->utype == t->utype){//only compare† 
      bool flag = 0;
      switch(s->utype){
        case 0:
          flag = true;
          break;
        case 1:
          flag = equal(s->info.hlink,t->info.hlink);
          break;
        case 2:
          flag = s->value == t->value;
          break;
      }
      if (!flag) return false;
      if ( (s->tlink == nullptr && t->tlink == nullptr) )
        return true;
      else return equal(s->tlink,t->tlink);
    }
    return false;
}
template<class T>
void GenList<T>::Input(istream& is){
  char ch;is>>ch;
  if (ch == '('){
    first->utype = 0;
    first->info.ref = 0;
    input(is, first);
  }
  else printf("输入格式错误！\n");
}
template<class T>
T GenList<T>::trans(string str){
  T tmp;
  stringstream ss;
  ss<<str;
  ss>>tmp;
  return tmp;
}
template<class T>
void GenList<T>::input(istream& is, GenListNode<T>* cur){// ...)
  char ch;
  string str = "";
  while(is>>ch){
    // cout<<*cur<<" ";
    // cout<<ch<<endl;//debug
    if (ch == ',' || ch == ')'){
      if (str.length()!=0){ 
        T tmp = trans(str);
        // cout<<"value = "<<tmp<<endl;//debug
        str = "";
        cur->tlink = new GenListNode<T>;
        cur = cur->tlink;      
        cur->utype = 1;
        cur->info.value = tmp;
      }
      if (ch == ')'){
        cur->tlink = nullptr;
        return;
      }
    }
    else if (ch == '('){
      cur->tlink = new GenListNode<T>;
      cur = cur->tlink;      
      cur->utype = 2;
      cur->info.hlink = new GenListNode<T>;

      cur->info.hlink->utype = 0;
      cur->info.hlink->info.ref = 1;
      input(is,cur->info.hlink);
    }
    else{
      str += ch;
    }
  }
}
template<class T>
void GenList<T>::printlist(ostream& os,GenListNode<T>* ls) const{
  GenListNode<T>* p = ls->tlink;
  os<<"(";
  while(p != nullptr){
    // os<<*p<<endl;
    if (p->utype == 2)
      printlist(os,p->info.hlink);
    else os<<p->info.value;
    p = p->tlink;
    if (p != nullptr) os<<",";
  }
  os<<")";
}
#endif // GEN_LIST_H