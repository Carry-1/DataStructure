#include<iostream>
#include<cstdio>
using namespace std;
# define Maxsize 100010
struct Node
{
    char data;
    int next;
}node[Maxsize];

int main()
{
    int addr1, addr2; // 分别存放两个单词第一个字母的地址
    int n;   //总字母数
    cout<<"please input the value of addr1 addr2 and n"<<endl;
    scanf("%d %d %d", &addr1, &addr2, &n);
    int add1 = addr1, add2 = addr2;    // add1和add2作为分别指向两个链表的工作指针
    int addr;
    for(int i=0; i<n; i++)        //输入所有结点
    {
        cout<<"please input the value of addr"<<endl;
        cin>>addr;
        cout<<"please input the value of data and next"<<endl;
        cin>>node[addr].data>>node[addr].next;
    }

    int length1 = 1, length2 = 1;
    while (node[add1].next!=-1)      //遍历求链表1长度
    {
        length1++;
        add1=node[add1].next;
    }
    while (node[add2].next!=-1)      //遍历求链表2长度
    {
        length2++;
        add2=node[add2].next;
    }
    int diff;    //两个链表的长度差
    diff = length1>length2?(length1-length2):(length2-length1);     //求长度差
    /*将较长的链表先工作指针向前移动到与较短指针“对齐”的位置*/
    add1 = addr1;    //工作指针先归位
    add2 = addr2;
    if (length1>length2)         //若链表1比链表2长
    {
        
        while(diff-- > 0)
        {
            add1=node[add1].next;
        }

    }

    else   //若链表2比链表1长
    {
       
        while(diff-- > 0)
        {
            add1=node[add1].next;
        }
    }

    while(node[add1].next!=-1&&node[add1].data!=node[add2].data)     //若还未遍历到链表末尾且还未遍历到共同后缀起始结点
    {
        add1=node[add1].next;
        add2=node[add2].next;
    }
    if(node[add1].data==node[add2].data)    //若已遍历到共同后缀起始结点
        {
            cout<<"the start node of suffix is:"<<endl;
            cout<<node[add1].data<<" "<<node[add1].next<<endl;
        }
    else     //若已遍历到末尾
        cout<<-1<<endl;        //若无共同后缀
    return 0;
}