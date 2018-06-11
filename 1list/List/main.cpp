#include <iostream>
#include"List.h"
using namespace std;

int main()
{
    char x;

    cout<<"(1)\n";
    List<char> ll;

    cout<<"(2)\n";
    for(char i='a';i<='e';++i){
      ll.Insert_back(i);
    }

    cout<<"(3)\n";
    ll.Output();
    cout<<ll.Size()<<endl;

    cout<<"(4)\n";
    if (ll.IsEmpty()) cout<<"yes\n";else cout<<"no\n";

    cout<<"(5)\n";
    cout<<ll.at(7)<<endl;

    cout<<"(6)\n";
    cout<<ll.Search('d')<<endl;

    cout<<"(7)\n";
    ll.Insert('f',4);
    ll.Output();

    cout<<"(8)\n";
    ll.Remove_pos(3);

    cout<<"(9)\n";
    ll.Output();

    cout<<"(10)\n";

    return 0;
}
