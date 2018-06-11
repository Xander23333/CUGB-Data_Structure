#include<iostream>
using namespace std;

int a[]{16,74,60,43,54,90,46,31,29,88,77};
int A[13]{};

void insert(int key){
  int pos = key%13;
  while (A[pos] != 0) {
    pos = (pos+1)%13;
    if (pos == key%13) {
      printf("hash table has full!\n");
      break;
    }
  }
  A[pos] = key;
}
int find(int key){
  int pos = key%13;
  while (A[pos] != key) {
    pos = (pos+1)%13;
    if (pos == key%13) {
      printf("can not find!\n");
      return -1;
    }
  }
  return pos;
}
void del(int key){
  int pos = find(key);
  if(pos != -1){
    A[pos] = 0;
    printf("delete success!\n");
  }
}
void print(){
  for(int i=0;i<13;++i) cout<<A[i]<<" ";cout<<endl;
}
int main(){
  int pos = 0;
  printf("------------(1)----------\n");
  for(int i=0;i<11;++i) {
    insert(a[i]);
  } 
  print();
  printf("------------(2)----------\n");
  printf("pos = %d\n",find(29));
  printf("------------(3)----------\n");
  del(77);
  insert(77);
  print();
}