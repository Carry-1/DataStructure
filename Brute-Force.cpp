#include <iostream>
#include <string>
using namespace std;
#define MaxLen 255
typedef struct    //定义定长顺序存储结构的串
{
    char ch[MaxLen+1];
    int length;
}SString;

int Index_BF(SString S, SString T, int pos);

int main()
{
    SString S;  //主串
    SString T;  //模式串
    strcpy(S.ch,"abcdecabeeee");  //初始化 
    strcpy(T.ch,"cab");    //初始化
    S.length = strlen(S.ch);
    for(int j=S.length-1; j>=0; j--)   //数组第一个位置不存放元素，所有数组元素依次向后移
      S.ch[j+1]=S.ch[j];
    
    T.length = strlen(T.ch);
    for(int j=T.length-1; j>=0; j--) //数组第一个位置不存放元素，所有数组元素依次向后移
       T.ch[j+1]=T.ch[j];
    int position = 1; 
    cout<<"模式串在主串中第一次出现的位置为："<<Index_BF(S, T, position)<<endl;
    return 0;
}

int Index_BF(SString S, SString T, int pos){
    int i = pos; //主串的起始匹配位置
    int j = 1;  
    while(i<=S.length&&j<=T.length)   //若主串指针未指到主串末尾且模式串指针未指到模式串末尾
    {
        if(j==0||S.ch[i]==T.ch[j])
        {
            i++;
            j++;
        }
        else 
        {
            i = i-j+2;
            j = 1;
        }
    }
    if( j>T.length ) return i-T.length;
    else return 0;
}
