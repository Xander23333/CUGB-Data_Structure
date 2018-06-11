#include<iostream>
#include<string>
using namespace std;

#define llp(i,x,y) for(int i=x;i<=y;++i)
#define rlp(i,y,x) for(int i=y;i>=x;--i)
#define lp(i,x) for(int i=0;i<x;++i)
#define mem(a,x) memset(a,x,sizeof a)

typedef long long ll;
typedef double db;


struct info{
  string checi,begin,end,origin,dest; 
  info(string a="",string b="",string c="",string d="",string e=""){
    checi = a;begin = b;end = c;origin = d;dest = e;
  } 
  friend ostream& operator << (ostream& os,info x){
    os<<x.checi<<"\t\t"<<x.begin<<"\t\t"<<x.end<<"\t\t"<<x.origin<<"\t\t"<<x.dest;
    return os;
  }
};
struct node{
  int next;
  info in;
  void make(int n, info i){
    next = n;in = i;
  }
  node(){}
  friend ostream& operator << (ostream& os,node x){
    os<<x.in;
    return os;
  }
};

class Train_System{
public:
  Train_System(int sz){S = new node[sz];S[head].next = -1;++top;}
  ~Train_System(){delete[] S;}
  void Insert(info x);
  void Del(string id);
  void Change(info x);
  void Output();
  void Search(string id){int pos = search(id);if(S[pos].next!=-1) {cout<<"车次\t开点\t到点\t始发站\t终点站\n";cout<<S[S[pos].next]<<endl;}}
private:
  int search(string id);
  node *S;
  int top = 0, sz = 0;
  int head = 0, rear = 0;
};
void Train_System::Output(){
  int tmp = S[head].next;
  cout<<"车次\t\t开点\t\t到点\t\t始发站\t\t终点站\n";
  while(tmp!=-1) {
    cout<<S[tmp]<<endl;
    tmp = S[tmp].next;
  }
}
void Train_System::Insert(info x){
  S[top].make(-1,x);
  S[rear].next = top;
  ++sz;rear = top;
  ++top;
  printf("插入成功!\n");
}
int Train_System::search(string id){ // return its father
  int tmp = head;
  while(S[tmp].next!=-1) {
    if (S[S[tmp].next].in.checi == id) break;
    tmp = S[tmp].next;
  }
  return tmp;
}
void Train_System::Del(string id){
  int pos = search(id);
  if (S[pos].next!=-1){
    if (rear == S[pos].next) rear = pos;
    S[pos].next = S[S[pos].next].next;
    printf("删除成功!\n");
  }
}
void Train_System::Change(info x){
  int pos = search(x.checi);
  S[S[pos].next].in = x;
  printf("更改成功!\n");
}




void ShowMenu()
{
    cout << "********************************************" << endl;
    cout << "******       列车时刻表管理系统        ******" << endl;
    cout << "******       0.安全退出系统           ******" << endl;
    cout << "******       1.插入信息             ******" << endl;
    cout << "******       2.删除信息             ******" << endl;
    cout << "******       3.查询车次             ******" << endl;
    cout << "******       4.更改信息             ******" << endl;
    cout << "******       5.查看所有车次          ******" << endl;
    cout << "请选择：";
}
//1 12:231 123:123 beijing ganzhou
//2 12:231 123:123 guangzhou shanghai
//3 12:231 123:123 guangzhou wuhan
void choice(Train_System& TS){
  int op;
  string a,b,c,d,e;
  while(true){
    ShowMenu();
    cin>>op;
    switch (op)
    {
      case 0:
        cout<<"感谢使用！\n";
        return;
        break;
      case 1:
        cout<<"请输入要插入的车次信息：车次、开点、到点、始发站、终点站（中间用空格隔开）\n";
        cin>>a>>b>>c>>d>>e;
        TS.Insert(info(a,b,c,d,e));
        break;
      case 2:
        cout<<"请输入要删除的车次: \n";
        cin>>a;
        TS.Del(a);
        break;  
      case 3:
        cout<<"请输入要查询的车次: \n";
        cin>>a;
        TS.Search(a);
        break;
      case 4:
        cout<<"请输入要更改的车次信息：车次、开点、到点、始发站、终点站（中间用空格隔开）\n";
        cin>>a>>b>>c>>d>>e;
        TS.Change(info(a,b,c,d,e));
        break;
      case 5:
        TS.Output();
        break;
      default:
        cout<<"命令有误，请重新输入！\n";        
        break;
    }
  }
}

Train_System TS(500);
int main(){
  choice(TS);
}