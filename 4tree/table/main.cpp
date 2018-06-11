#include<bits/stdc++.h>
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;

#define fi first
#define se second
#define pb push_back

struct child{
  int c;
  child(){}
  child(int c,child* l):link(l),c(c){}
  child* link;
};
struct head{
  child* link;
  string data;
  head(){}
  head(string d,child* l):link(l),data(d){}
}; 
class tree{
public:
  tree(){}
  ~tree(){destroy();cout<<"destroyed.\n";}
  void putin();
  void Table(int rt);
  int root = 0;
  int studentnumber(string depart);
  int classnumber(string depart);
  int majornumber(string depart);
private:
  void destroy();
  int convert(string str);
  vector<head*> H;
  map<string,int> ma;
};
int tree::convert(string str){
  stringstream ss;int ans;
  ss<<str;ss>>ans;
  return ans;
}
int tree::studentnumber(string depart){
  child *q, *p = H[ma[depart]]->link;
  int cnt = 0;
  while(p!=nullptr){
    q = H[p->c]->link;
    while(q!=nullptr){
      cnt += convert(H[H[q->c]->link->c]->data);
      q = q->link;
    }
    p = p->link;
  }
  return cnt;
}
int tree::classnumber(string depart){
  child *q,*p = H[ma[depart]]->link;
  int cnt = 0;
  while(p!=nullptr){
    q = H[p->c]->link;
    while(q!=nullptr){
      q = q->link;
      ++cnt;
    }
    p = p->link;
  }
  return cnt;
}
int tree::majornumber(string depart){
  child* p = H[ma[depart]]->link;
  int cnt = 0;
  while(p!=nullptr){
    ++cnt;
    p = p->link;
  }
  return cnt;
}
void tree::Table(int rt){
  child* p = H[rt]->link;
  cout<<H[rt]->data;
  if (p!=nullptr) {
    cout<<" ( ";
    while(p!=nullptr){
      Table(p->c);
      p = p->link;
      if (p!=nullptr) cout<<" , ";
    }
    cout<<" ) ";
  }
}
void tree::putin(){
  string a,b;child* tmp;
  while(cin>>a>>b){
    if (ma.count(a) == 0){
      ma[a] = H.size();
      H.pb(new head(a,nullptr));  
    }
    if (ma.count(b) == 0) {
      ma[b] = H.size();
      H.pb(new head(b,nullptr));  
    }

    tmp = new child(ma[b],H[ma[a]]->link);
    H[ma[a]]->link = tmp;
  }
}
void tree::destroy(){
  for(head* h:H){
    child *q,*p = h->link;
    while(p!=nullptr){
      q = p->link;
      delete p;
      p = q;
    }
    delete h;
  }
}

tree T;
int main(){
  freopen("table.txt","r",stdin);
  printf("------------(1)----------\n"); 
  printf("use prepro.py\n");
  printf("------------(2)----------\n");  
  T.putin();
  printf("------------(3)----------\n");  
  T.Table(0);cout<<endl;
  printf("------------(4)----------\n");  
  cout<<"计算机学院 专业数量为 "<<T.majornumber("计算机学院")<<endl;
  printf("------------(5)----------\n");  
  cout<<"计算机学院 班级数量为 "<<T.classnumber("计算机学院")<<endl;
  printf("------------(6)----------\n");  
  cout<<"电信学院 班级数量为 "<<T.studentnumber("电信学院")<<endl;
  printf("------------(7)----------\n");  
  
  fclose(stdin);
}