#include <iostream>
#include"SeqQueue.h"

int main(){
    char ch;

    cout<<"(1)\n";
    SeqQueue<char> Q;

    cout<<"(2)\n";
    cout<<( Q.IsEmpty()?"Queue is Empty":"Queue is not Empty")<<endl;

    cout<<"(3)\n";
    for (ch = 'a';  ch <= 'q' ; ++ch) {
        Q.EnQueue(ch);
    }

    cout<<"(4)\n";
    if (Q.DeQueue(ch)) cout<<ch<<endl;
    else cout<<"DeQueue failed!\n";

    cout<<"(5)\n";
    cout<<"Ths Size of The Queue is "<<Q.getSize()<<endl;

    cout<<"(6)\n";
    for (ch = 'r';  ch <= 'z' ; ++ch) {
        Q.EnQueue(ch);
    }

    cout<<"(7)\n";
    // for (int i = 0;i<=25;++i) Q.DeQueue(ch);
    // // cout<<Q;
    while(Q.DeQueue(ch))
        cout<<ch<<" ";
    cout<<endl;

    cout<<"(8)\n";
    return 0;    
}
