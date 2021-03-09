#include<iostream>
using namespace std;

# define Maxsize 6
typedef struct{
    int *elem;
    int length;
}Sqlist;      // define Sqlist struct

int InsertSqlist(Sqlist &L, int i, int e);
int main(){
    Sqlist L;
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
    cout<<"the Sqlist before insertion is:"<<endl;
    for (i=0; i<5; i++)
            cout<<L.elem[i]<<" ";
    cout<<endl;
  InsertSqlist(L,3,103);
    cout<<"the Sqlist after insertion is:"<<endl;
    for ( i=0; i<L.length; i++)
        cout<<L.elem[i]<<" "; 
    cout<<endl;
    return 0;
}
int InsertSqlist(Sqlist &L, int i, int e)
{
    if (i<1||i>L.length) return -1;   // location  false;
    if (L.length==Maxsize)   return -2; //storage space full;
    if (i==L.length)
        L.elem[L.length]=e;
    else
    {
        int j;
        for(j=L.length-1; j>=i-1; j--) //将第i个及其以后的元素全部后移一个位置 
            L.elem[j+1] = L.elem[j];

        L.elem[j] = e;
    }
    L.length++;
    return 0;
}