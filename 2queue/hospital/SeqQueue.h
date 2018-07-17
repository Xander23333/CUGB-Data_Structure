//
// Created by Elizabeth on 2018/5/7.
//

#ifndef SEQQUEUE_SEQQUEUE_H
#define SEQQUEUE_SEQQUEUE_H

#include <iostream>
#include <cassert>
using namespace std;

template <class T>
class SeqQueue{
public:
    SeqQueue(int sz = 10);
    ~SeqQueue() {delete[] element;}
    bool EnQueue(const T& x);
    bool DeQueue(T& x);
    bool getFront(T& x);
    void makeEmpty(){front = rear = 0;}
    bool IsEmpty()const {return (front == rear)?true:false;}
    bool IsFull() const {
        if ((rear+1)%maxSize == front) return true;
        else return false;
    }
    int getSize() const {return (rear - front + maxSize)%maxSize; }
    friend ostream& operator << (ostream& os, const SeqQueue<T>& Q){//不是const引用的时候，拷贝构造出了问题，报错
        int q=Q.front;
        while(q != Q.rear){
            os<<Q.element[q]<<" ";
            q = (q+1)%Q.maxSize;
        }
        // os<<endl;os<<endl;
        return os;
    }

private:
    void ReSize(int sz);
    int rear,front;
    T *element;
    int maxSize;
};

template<class T>
SeqQueue<T>::SeqQueue(int sz):rear(0),front(0),maxSize(sz){
    element = new T[maxSize];
}

template<class T>
void SeqQueue<T>::ReSize(int sz){
    if (this->getSize() > sz) return;
    T* tmp = new T[sz];

    int q = this->front, cnt = 0;
    while(q!=this->rear){
        tmp[cnt++] = this->element[q];
        q = (q+1)%this->maxSize;
    }
    delete[] element;

    element = tmp;
    front = 0;
    rear = cnt;
    maxSize = sz;
    // cout<<cnt<<" ";
}

template<class T>
bool SeqQueue<T>::EnQueue(const T&x){
    if (this->IsFull()) {
        this->ReSize(this->maxSize*2);
    }
    element[rear] = x;
    rear = (rear + 1)%maxSize;
    return true;
}

template<class T>
bool SeqQueue<T>::DeQueue(T& x){
    if (this->IsEmpty()) return false;
    else{
        if (this->maxSize > 4 && this->getSize() <= this->maxSize/4 ){
            this->ReSize(this->maxSize/2);
        }

        x = element[front];
        front = (front + 1)%maxSize;

        return true;
    }    
}

template<class T>
bool SeqQueue<T>::getFront(T& x){
    if (this->IsEmpty()) return false;
    else{
        x = element[front];
        return true;
    }      
}

#endif //SEQQUEUE_SEQQUEUE_H
