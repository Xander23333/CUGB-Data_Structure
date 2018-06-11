#ifndef SPARSE_H
#define SPARSE_H

#include<iostream>
#include<cstdlib>
#include<algorithm>
using std::cerr;using std::endl;
using std::min;using std::ostream;

const double sparse_factor = 1.0;
const int DefaultSize = 100;
template<class T>
struct Trituple{
  int row,col;
  T value;
  Trituple(int r,int c,T v):row(r),col(c),value(v){}
  Trituple(){}
  Trituple& operator = (const Trituple<T>& x){
    row = x.row;col = x.col;value = x.value;
    return *this;
  }
  friend ostream& operator << (ostream& os, const Trituple<T>& t){
    os<<"i = "<<t.row<<" j = "<<t.col<<" value = "<<t.value;
    return os;
  }
};

template<class T>
class SparseMatrix{
  friend ostream& operator << (ostream& os, const SparseMatrix<T>& M){
    os<<"rows = "<<M.rows<<" cols = "<<M.cols<<" terms = "<<M.terms<<endl;
    for(int i=0;i<M.terms;++i) 
      os<<M.smArray[i]<<endl;
    return os;
  }
public:
  SparseMatrix(int rows,int cols);
  SparseMatrix(const SparseMatrix<T>& x);
  ~SparseMatrix(){delete[] smArray;}
  void insert(int r,int c,T v);
  SparseMatrix<T> operator ~ ();
  SparseMatrix<T> operator + (const SparseMatrix<T>& x);
  SparseMatrix<T> operator * (const SparseMatrix<T>& x);
private:
  int rows,cols,terms;
  Trituple<T>* smArray;
  int maxTerms;
};
template<class T>
SparseMatrix<T>::SparseMatrix(int rows,int cols):
      rows(rows),cols(cols),terms(0),maxTerms((int)(sparse_factor*rows*cols)){
  if (rows*cols<1) {
    cerr<<"初始化值错误！"<<endl;exit(1);
  }
  smArray = new Trituple<T> [maxTerms];
  if (smArray == nullptr){ 
    cerr<<"存储分配错误！"<<endl;exit(1);
  }
}
template<class T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& x):rows(x.rows),cols(x.cols),terms(x.terms),maxTerms(x.maxTerms){
  smArray = new Trituple<T> [maxTerms];
  if (smArray == nullptr){ 
    cerr<<"存储分配错误！"<<endl;exit(1);
  }
  for(int i=0;i<maxTerms;++i) smArray[i] = x.smArray[i];
}
template<class T>
void SparseMatrix<T>::insert(int r,int c,T v){
  if (this->terms == this->maxTerms)
    printf("overflow!\n");
  else this->smArray[this->terms++] = Trituple<T>(r,c,v);
}
template<class T>
SparseMatrix<T> SparseMatrix<T>::operator ~ (){
  SparseMatrix<T> ans(this->rows,this->cols);
  ans.terms = this->terms;
  int* rowSize = new int[this->cols+20];
  int* rowStar = new int[this->cols+20];
  
  for(int i=0;i<this->cols;++i) rowSize[i] = 0;//a bug, I touch the pointer rowSize, and value it to 0

  for(int i=0;i<this->terms;++i) {
    // printf("i = %d col = %d \n",i,this->smArray[i].col);    
    ++(rowSize[(this->smArray[i].col)]);
  }
  
  rowStar[0] = 0;
  for(int i=1;i<this->cols;++i) 
    rowStar[i] = rowStar[i-1] + rowSize[i-1]; 
  Trituple<T> a;
  for(int i=0;i<this->terms;++i){
    a = this->smArray[i];
    ans.smArray[rowStar[a.col]++] = Trituple<T>(a.col, a.row, a.value);
    // std::cout<<a.col<<" "<<a.row<<" "<<a.value<<endl;
  }

  delete[] rowSize;
  delete[] rowStar;
  return ans;
}
template<class T>
SparseMatrix<T> SparseMatrix<T>::operator + (const SparseMatrix<T>& x){
  if (x.rows != this->rows || x.cols != this->cols ){
    cerr<<"sizes are not equal, can not add!\n";
    exit(1);
  }
  SparseMatrix<T> ans(rows, cols);
  int i=0,j=0,index_a,index_b;
  Trituple<T> a,b;
  while(i<x.terms && j<this->terms){
    a = x.smArray[i]; b = this->smArray[j];
    index_a = (a.row-1)*x.cols+a.col;
    index_b = (b.row-1)*this->cols+b.col;
    
    if (index_a<index_b){
      ans.insert(a.row,a.col,a.value);
      ++ i;
    }
    else if (index_a > index_b){
      ans.insert(b.row,b.col,b.value);
      ++ j;
    }
    else{
      ans.insert(a.row,a.col,a.value+b.value);
      ++i,++j;
    }
  } 
  while (i<x.terms){
    a = x.smArray[i];
    ans.insert(a.row,a.col,a.value);
    ++i;
  }
  while (j<this->terms){
    b = x.smArray[i];
    ans.insert(b.row,b.col,b.value);
    ++j;
  }
  return ans;
}
template<class T>
SparseMatrix<T> SparseMatrix<T>::operator * (const SparseMatrix<T>& x){
  if (this->cols != x.rows){
    printf("A.cols != x.rows, can not multiply!\n");
    exit(1);
  }
  SparseMatrix<T> ans(this->rows, x.cols);

  int* rowSize = new int[x.rows+20];
  int* rowStar = new int[x.rows+20];
  for(int i=0;i<x.rows;++i) rowSize[i] = 0;
  for(int i=0;i<x.terms;++i)  
    ++(rowSize[(x.smArray[i].row)]);
  rowStar[0] = 0; 
  for(int i=1;i<x.rows;++i) 
    rowStar[i] = rowStar[i-1] + rowSize[i-1]; 
  rowStar[x.rows] = x.terms;

  Trituple<T> a,b;
  T* tmp = new T[x.cols];
  int rowA, current = 0;
  while(current < this->terms){
    a = this->smArray[current];
    rowA = a.row;
    for(int j=0;j<x.cols;++j) tmp[j] = 0;
    while(current < this->terms && a.row == rowA){
      for(int i = rowStar[a.col];i < rowStar[a.col+1];++i){
        b = x.smArray[i];
        tmp[b.col] += a.value * b.value;
      }
      ++current;
      a = this->smArray[current];      
    }
    for(int j=0;j<x.cols;++j) 
      if (tmp[j] > 0) ans.insert(rowA, j, tmp[j]);    
  }

  delete[] rowSize;
  delete[] rowStar;
  return ans;
}
#endif //SPARSE_H