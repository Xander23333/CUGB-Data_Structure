#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<map>
using namespace std;

bool eval(string s, double& num){
  if (s[0]<'0' || s[0]>'9') return false;
  else{
    stringstream ss;
    ss<<s;
    ss>>num;
    return true;
  }
}

stack<char> S;
stack<double> Snum;
map<char,int> prio;
char s[] = "()-+/*";

void calcu(char ope){
  int a,b;
  b = Snum.top();
  Snum.pop();
  a = Snum.top();
  Snum.pop();
  double ans = 0;
  switch(ope){
    case '*':
      ans = a*b;
      break;
    case '-':
      ans = a-b;
      break;
    case '+':
      ans = a+b;
      break;
    case '/':
      ans = a/b;
      break;
  }
  Snum.push(ans);
}
int main(){
  for (int i=0;i<6;++i) prio[s[i]] = i;

  freopen("in.txt","r",stdin);
  string elem0,tmp;
  char elem;
  double num;
  while(cin>>elem0){
    // cout<<elem0<<endl;
    if (eval(elem0,num)){
      cout<<num<<" ";
      Snum.push(num);
    }
    else{
      elem = elem0[0];
      
      switch (elem){
        case '(':
          S.push(elem);
          break;
        case ')':
          while(!S.empty() && S.top()!='('){
            cout<<S.top()<<" ";
            calcu(S.top());
            S.pop();
          } 
          S.pop();
          break;
        default:
          while(!S.empty() && prio[S.top()]>=prio[elem]){
            cout<<S.top()<<" ";
            calcu(S.top());
            S.pop();
          }
          S.push(elem);
          break;
      }
    }
  }
  while(!S.empty()){
    cout<<S.top()<<" ";
    calcu(S.top());
    S.pop();
  }
  cout<<endl;
  cout<<Snum.top()<<endl;
}