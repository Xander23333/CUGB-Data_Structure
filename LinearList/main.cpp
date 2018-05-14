#include <iostream>
#include"SeqList.h"
using namespace std;

int main()
{
    char x;

    cout<<"(1)\n";
    SeqList<char> ll(0);

    cout<<"(2)\n";
    for(char i='a';i<='e';++i){
        if (ll.Insert(i,ll.Length()-1)==false) cerr<<"insert "<<i<<" wrong!\n";
        else  cout<<"insert "<<i<<" success!\n";
    }

    cout<<"(3)\n";
    ll.output();
    cout<<ll.Length()<<endl;

    cout<<"(4)\n";
    if (ll.IsEmpty()) cout<<"yes\n";else cout<<"no\n";

    cout<<"(5)\n";
    ll.getData(2,x);
    cout<<x<<endl;

    cout<<"(6)\n";
    cout<<ll.Search('d')<<endl;

    cout<<"(7)\n";
    ll.Insert('f',4-1-1);
    cout<<"f has been inserted.\n";

    cout<<"(8)\n";
    ll.Remove(2,x);
    cout<<x<<" has been removed.\n";

    cout<<"(9)\n";
    ll.output();

    cout<<"(10)\n";

    return 0;
}
