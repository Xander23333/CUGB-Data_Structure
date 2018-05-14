//
// Created by Elizabeth on 2018/4/14.
//

#ifndef UNTITLED_LINEARLIST_H
#define UNTITLED_LINEARLIST_H

template<class T>
class LinearList
{
public:
    LinearList()=default;
    virtual ~LinearList()=default;
    virtual int Size() const =0;
    virtual int Length() const =0;
    virtual int Search(T& ) const =0;
    virtual int Locate(int ) const =0;
    virtual int getData(int,T& ) = 0;
    virtual void setData(int,const T& ) =0;
    virtual bool Insert(int,T& ) = 0;
    virtual bool Remove(int,T& ) =0;
    virtual bool IsEmpty() const =0;
    virtual bool IsFull() const=0;
    virtual void Sort()=0;
    virtual void input()=0;
    virtual void output()=0;
};

#endif //UNTITLED_LINEARLIST_H
