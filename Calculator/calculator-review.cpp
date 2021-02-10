#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
/*声明一些全局变量*/
typedef struct
{
   bool flag;  //  flag=false时为操作符， flag=true时为操作数
   double num;
   char op;
}node;   

string str;  //用于存放中缀表达式
stack<node> s;   //运算符栈
queue<node> q;   //存放操作数
map<char, int> op; 


void change()   // 中缀表达式转后缀表达式
{
    node temp;    // 定义temp变量用于存放操作符或操作数
    for (int i =0; i< str.length();)
    {
       if (str[i]>='0'&&str[i]<='9') //若是操作数
        {
            temp.flag=true;
            temp.num=str[i++]-'0';
            while(str[i]>='0'&&str[i]<='9')  //如果操作数的位数不只一位
            {
                temp.num = temp.num*10+str[i++]-'0';
            }
            q.push(temp);   //将操作数输入后缀表达式
        }
        else
        {
            temp.flag=false;
            if(!s.empty()&&op[s.top().op]>=op[str[i]])  // 若栈顶操作符的优先级大于等于当前遍历到的中缀表达式中的操作符的优先级
            {
                q.push(s.top());   //栈顶操作符出栈并入后缀表达式队列
                s.pop();
            }
            temp.op=str[i++];
            s.push(temp);   //遍历到的操作符入栈
        }
               
    }
    while(!s.empty())
   {
       q.push(s.top());
       s.pop();
   }     
}

double Cal()   //计算后缀表达式
{
    node temp1, temp2;   // 用于存放出栈操作数
    node temp; //用于存放入栈操作数
    node cur;   //cur用于存放出队元素
    while(!q.empty())   //后缀表达式队列中元素逐个出队
    {
        cur = q.front();   
        q.pop();  // 出队
        if(cur.flag==true)   // 若出队元素为操作数，入栈
            s.push(cur);
        else   //若出队元素为操作符，还须从栈顶连续出栈两个操作数进行运算
        {
          
            temp2= s.top();
            s.pop();
            temp1= s.top();
            s.pop();
            switch(cur.op)
            {
                case '+': temp.num=temp1.num+temp2.num; break;
                case '-': temp.num=temp1.num-temp2.num; break;
                case '*': temp.num=temp1.num*temp2.num; break;
                case '/': temp.num=temp1.num/temp2.num; break;
                default: break;
            }
            s.push(temp);
        }
    }
    return s.top().num;
}

int main()   
{
    op['+']=op['-']=0;
    op['*']=op['/']=1;
    cout<<"please input infix expression"<<endl;
    while(getline(cin, str), str != "0") //输入中缀表达式
    {
        for (string ::iterator it = str.end(); it>str.begin(); it--)  //删除中缀表达式中的空格
        {
            if (*it==' ')
                str.erase(it);
        }
        change();
        while(!s.empty())   //初始化栈
            s.pop();    
        cout<<"the output is:"<<endl;
        printf("%.2f", Cal());
    }

    return 0;
}