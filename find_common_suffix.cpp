#include<iostream>
#include<cstdio>
using namespace std;
# define Maxsize 100010
struct Node
{
    int addr;
    char data;
    int next;
}node[Maxsize];

int main()
{
    int addr1, addr2; // 分别存放两个单词第一个字母的地址
    int n;   //总字母数
    scanf("%d %d %d", &addr1, addr2, &n);
    int add1 = addr1, add2 = addr2;    // 暂存addr1和addr2
    int addr;
    for(int i=0; i<n; i++)
    {
        cin>>addr;
        cin>>node[addr].data>>node[addr].next;
    }

    int length1 = 1, length2 = 1;
    while (node[add1].next!=-1)
    {
        length1++;
        add1=node[add1].next;
    }
    while (node[add2].next!=-1)
    {
        length2++;
        add2=node[add2].next;
    }
    return 0;
}