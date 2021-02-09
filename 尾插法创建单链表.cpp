# include<iostream>
using namespace std;
# define  N 5
typedef struct Lnode {
    int data;
    struct Lnode * next;
}Lnode, *Linklist;


Linklist Creat(int Array[]);   

int main()
{
    int Array[N];
    cout<<"please input "<<N<<" numbers"<<endl;
    for(int i=0; i<N;i++)
        cin>>Array[i];
    Lnode * L = Creat(Array);
    L=L->next;
    cout<<"the Linklist is:"<<endl;
    while(L!=NULL)
    {
        cout<<L->data<<" ";
        L=L->next;
    }
    return 0;
}

Linklist Creat(int Array[])
{
    Linklist p = new Lnode;   // 新建头结点
    Linklist r = p;   //尾指针
    p->next=NULL;
    for (int i =0; Array[i]!='\0';i++)
    {
        Lnode *p1 = new Lnode;
        p1->data=Array[i];
        r->next=p1;
        r=p1;
        r->next=NULL;
    }
    return p;
}