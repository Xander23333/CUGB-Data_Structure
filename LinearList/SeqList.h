//
// Created by Elizabeth on 2018/4/14.
//

#ifndef UNTITLED_SEQLIST_H
#define UNTITLED_SEQLIST_H

#include"LinearList.h"
#include<iostream>
#include<algorithm>
template <class T>
class SeqList//:public LinearList<T>
{
protected:
    T *data;
    int maxSize; 
    int last;
    void reSize(int newSize);
public:
        SeqList(int sz=100);
        SeqList(SeqList<T>& L)=default;
        ~SeqList();
        int Size() const {return maxSize;}
        int Length() const {return last;}
        int Search(const T& x) const;
        int Locate(int i) const;
        bool getData(int,T&)const;
        void setData(int,const T& );
        bool IsEmpty() const{return last==0;}
        bool IsFull() const{return last==maxSize;}

        bool Insert(const T&,int pos);
        bool Remove(int,T&);

        void Sort(){sort(data,data+last);}//,T must have define operator "<"
        void input(int cnt=0);//make the list as the input
        void output();
//        SepList<T> operator = (SepList<T>&);
};
template <class T>
void SeqList<T>::reSize(int newSize){
    if (newSize<=0) std::cerr<<"reSize Wrong!\n";
    if (newSize==maxSize) return;
    else{
        if (newSize>this->maxSize){
            T* dd{new T[newSize]};
            for(int i=0;i<last;++i){
                dd[i]=this->data[i];
            }
            delete[] this->data;
            this->data=dd;
        }
        else{
            last=newSize;
        }
        this->maxSize=newSize;
        return;
    }
}
template <class T>
SeqList<T>::SeqList(int sz){
    data=new T[sz];
    maxSize=sz;
    last=0;
    std::cout<<"SeqList constructed!\n";
}
template <class T>
SeqList<T>::~SeqList(){
    delete[] data;
    std::cout<<"SeqList destructed!\n";
}
template <class T>
int SeqList<T>::Search(const T& x) const{
    for(int i=0;i<last;++i){
        if (this->data[i]==x) return i;
    }
    return -1;
}
template <class T>
int SeqList<T>::Locate(int i) const{
    if ((i>=0 && i<last)) return i;
    else return -1;//last can't be 0,
}
template <class T>
bool SeqList<T>::getData(int i,T& x) const{
    if (Locate(i)!=-1) {
        x=this->data[i];
        return true;
    }
    else return false;
}
template <class T>
void SeqList<T>::setData(int i,const T& x){
    if (Locate(i)!=-1) {
        this->data[i]=x;
    }
    else std::cerr<<"setData wrong!\n";
}
template <class T>
void SeqList<T>::input(int cnt){
    if (cnt<0 ) std::cerr<<"input wrong!\n";
    if (cnt>maxSize) this->reSize(cnt);
    last=0;
    while(last<cnt)  std::cin>>this->data[last++];
}
template <class T>
void SeqList<T>::output(){
    for(int i=0;i<last;++i) std::cout<<this->data[i]<<" ";std::cout<<"\n";
}
template <class T>
bool SeqList<T>::Insert(const T& x,int pos){
    if (Locate(pos)==-1 && !(pos==-1 && last==0)) return false;

    if (last+1>maxSize) this->reSize(2*maxSize+3);//in case of maxSize=0
    ++last;
    for(int i=last-1;i>pos;--i){
        this->data[i+1]=this->data[i];
    }
    this->data[pos+1]=x;
    return true;
}
template <class T>
bool SeqList<T>::Remove(int pos,T& x){
    if (Locate(pos)==-1) return false;

    x=this->data[pos];
    for(int i=pos;i<last-1;++i){
        this->data[i]=this->data[i+1];
    }
    --last;

    return true;
}
#endif //UNTITLED_SEQLIST_H
