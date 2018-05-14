//
// Created by Elizabeth on 2018/5/7.
//

#ifndef SEQQUEUE_SEQQUEUE_H
#define SEQQUEUE_SEQQUEUE_H

#include <iostream>
using namespace std;
template <T>
class SeqQueue{
public:
    SeqQueue(int sz = 10);
    ~SeqQueue() {delete[] elements;}
    bool EnQueue(const T& x);
    bool DeQueue(T& x);
    bool getFront(T& x);
    void makeEmpty(){front = rear = 0;}
    bool IsEmpty()const {return (front == rear)?true:false;}
    bool IsFull() const {retrun ( (rear+1)%maxSize == front):true:false;}
    int getSize() const {return (rear - front + maxSize)%maxSize; }
    friend ostream& operator << (ostream& os, SeqQueue<T> Q){

    }

private:
    int rear,front;
    T *element;
    int maxSize;
};

#endif //SEQQUEUE_SEQQUEUE_H
