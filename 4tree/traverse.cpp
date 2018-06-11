#include<iostream>
using namespace std;

struct node{
  char value;
  node* lson;//bug 连着定义就不行，分开才可以??
  node* rson;
  node():lson(nullptr),rson(nullptr){}
};

node* traverse(const string& pre,const string& mid){
  // cout<<pre<<" "<<mid<<endl;
  char root = pre[0];
  int pos = mid.find(root);
  node* tree = new node;
  tree->value = root;
  if (pos>0) tree->lson = traverse(pre.substr(1,pos),mid.substr(0,pos));
  if (pos<pre.length()-1) tree->rson = traverse(pre.substr(pos+1),mid.substr(pos+1));
  return tree;
}
void post(node* tree){
  if (tree->lson!=nullptr) post(tree->lson);
  if (tree->rson!=nullptr) post(tree->rson);
  cout<<tree->value;
}
string pre,mid;
int main(){
  freopen("traverse.txt","r",stdin);
  cin>>pre>>mid;
  node* tree = traverse(pre,mid);
  // cout<<1<<endl;
  post(tree);cout<<endl;
  fclose(stdin);
}