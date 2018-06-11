#include <iostream>
#include "seqstack.h"

int main()
{
    cout<<"(1)\n";
    SeqStack<char> s;

    cout<<"(2)\n";
    cout<<( s.IsEmpty()?"Stack is Empty":"Stack is not Empty")<<endl;

    cout<<"(3)\n";
    for (char ch = 'a';  ch <= 'e' ; ++ch) {
        s.Push(ch);
    }

    cout<<"(4)\n";
    cout<<"Ths Size of The Stack is "<<s.getSize()<<endl;

    cout<<"(5)\n";
    cout<<s<<endl;

    cout<<"(6)\n";
    char x;
    while(s.Pop(x)){
        cout<<x<<" ";
    }cout<<endl;


    cout<<"(7)\n";

    return 0;
}
