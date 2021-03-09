#include<iostream>
using namespace std;

# define Maxsize 6
typedef struct{
    int *elem;
    int length;
}Sqlist;      // define Sqlist struct

int InsertSqlist(Sqlist &L, int i, int e);
int main(){
    Sqlist L;   //定义一个空顺序表
    L.elem= new int[Maxsize];
    L.length=0;
    int i;
    if(!L.elem) return -1;  // if storage space allocation failed.
    cout<<"please input 5 numbers"<<endl;
    for ( i=0; i<5; i++)
{       
    cin>>L.elem[i];
    L.length++;
}
    cout<<"the Sqlist before insertion is:"<<endl;  //显示插入前的顺序表
    for (i=0; i<5; i++)
            cout<<L.elem[i]<<" ";
    cout<<endl;
    int location = 3; 
    int insert_element = 103;
  InsertSqlist(L,location,insert_element);  //插入
    cout<<"the Sqlist after insertion is:"<<endl;  //显示插入后的顺序表
    for ( i=0; i<L.length; i++)
        cout<<L.elem[i]<<" "; 
    cout<<endl;
    return 0;
}
int InsertSqlist(Sqlist &L, int i, int e)  //插入函数
{
    if (i<1||i>L.length) return -1;   // location  false;
    if (L.length==Maxsize)   return -2; //storage space full;
    if (i==L.length)  //若插入链表最后一个元素之后，直接插入
        L.elem[L.length]=e;
    else
    {
        int j;
        for(j=L.length-1; j>=i-1; j--) //将第i个及其以后的元素全部后移一个位置 
            L.elem[j+1] = L.elem[j]; 

        L.elem[j] = e;   //将待插入元素插入指定位置
    }
    L.length++;   //插入之后表长度加1
    return 0;
}