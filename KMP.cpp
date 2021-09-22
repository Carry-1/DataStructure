 #include <iostream>
#include <string>
using namespace std;
#define MaxLen 255
typedef struct 
{
    char ch[MaxLen+1];
    int length;
}SString;

int Index_KMP(SString S, SString T, int pos, int next[]);
void get_next(SString T, int next[]);
void get_nextval(SString T, int nextval[]); //使用修正之后的next数组


int main()
{
    SString S; SString T;
    int next[MaxLen];    //next[]数组
    //int nextval[MaxLen]；
    strcpy(S.ch,"abcdecabeeee");   
    strcpy(T.ch,"cab");
    S.length = strlen(S.ch);
    for(int j=S.length-1; j>=0; j--)   //数组第一个位置不存放元素，所有数组元素依次向后移
      S.ch[j+1]=S.ch[j];
    
    T.length = strlen(T.ch);
    for(int j=T.length-1; j>=0; j--) //数组第一个位置不存放元素，所有数组元素依次向后移
       T.ch[j+1]=T.ch[j];
    
    get_next( T,  next);  //初始化next数组
    // get_nextval( T,  nextval）； 

    int position = 1; 

    cout<<"模式串在主串中第一次出现的位置为："<<Index_KMP(S, T, position, next)<<endl;
    return 0;
}

int Index_KMP (SString S, SString T, int pos, int next[] )
{
    int i = pos; //主串的起始匹配位置
    int j = 1;  
    while(i<=S.length&&j<=T.length)
    {
        if(j==0||S.ch[i]==T.ch[j])
        {
            i++;
            j++;
        }
        else 
            j = next[j];
        
    }
    if( j>T.length ) return i-T.length;
    else return 0;
}

void get_next(SString T, int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else 
            j = next[j];
    }
}

/* 初始化修正之后的next数组
    void get_nextval(SString T, int nextval[]){
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            i++;
            j++;
            if(T.ch[i]!=T.ch[j])
                nextval[i] = j;
            else nextval[i] = nextval[j];
        }
        else 
            j = nextval[j];
    }
}
    

*/