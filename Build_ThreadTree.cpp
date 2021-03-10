#include<iostream>
using namespace std;
typedef int ElemType;

typedef struct ThreadNode{       //二叉线索树
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

ThreadTree CreatTree(ThreadTree &root, int Array[]);
ThreadTree FirstNode(ThreadTree T);   
void Build_ThreadTree(ThreadTree &T);
void Traverse_ThreadTree_InOrder (ThreadTree T);


int main()
{
    int Array[] = {1,2,3,4,5,6,7,8}; 
    ThreadTree T =NULL;
    CreatTree(T, Array); // Build Binary Tree
    Build_ThreadTree( T );
    cout<<"遍历线索树："<<endl;
    Traverse_ThreadTree_InOrder(T);
    cout<<endl;
    return 0;
}

ThreadTree newNode(ElemType e)   
{
    ThreadTree p = new ThreadNode;
    p->data = e;
    p->lchild = p->rchild = NULL;
    /*
    注意：一定要为p->ltag与p->rtag设立一个默认值，否则编译器可能会随便为其设置一个值，从而使运行结果出错
    */
    p->ltag = p->rtag = 1;    
    return p;
}

void Insert(ThreadTree &root, ElemType e)
{
    if(root == NULL)
    {
        root = newNode(e);
        return;
    }
    if(e<root->data)  
        Insert(root->lchild, e);
    else
        Insert(root->rchild, e);
}


ThreadTree CreatTree(ThreadTree &root, int Array[])   //生成一个线索树，但未建立线索
{
    for (int i=0; i<8; i++)
        Insert(root, Array[i]);
    return root;
}

void Build_ThreadTree_In_detail(ThreadTree &T, ThreadTree &pre)
{
    ThreadTree p = T;
    if(p)
    {    
        Build_ThreadTree_In_detail(p->lchild, pre);  //左子树递归线索化

        if( !p->lchild ) //若p->指针为空，令其指向pre
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        else p->ltag = 0;

        if( pre )  //pre = NULL时不需要处理其rchild指针和rtag域
        {
            if(pre->rchild == NULL) //若pre->child指针为空，令其指向p
            {
                pre->rchild = p;
                pre->rtag = 1;
            }
            else pre->rtag = 0;
        }
        
        pre = p;

        Build_ThreadTree_In_detail(p->rchild,pre);
    }
}

void Build_ThreadTree(ThreadTree &T)
{
    ThreadTree pre = NULL;
    if(T)
        Build_ThreadTree_In_detail( T , pre);
    /*
    下面这两句按照算法编写时的逻辑应该加上才对，但如果加上的话在编译运行时又会出错。
    经过单步调试找到了原因：我之前将 Build_ThreadTree_In_detail 函数定义成了这样：
    void Build_ThreadTree_In_detail(ThreadTree &T, ThreadTree pre)
    而正确的定义方法应该是这样：
    void Build_ThreadTree_In_detail(ThreadTree &T, ThreadTree &pre)
    显然，pre指针在作为函数实参需要按址传递，否则在递归调用函数退栈时，最中pre不会指向最后一个结点，而是pre=NULL
    */
    pre->rchild = NULL;
    pre->rtag = 1;

}

ThreadTree FirstNode(ThreadTree T)  //Find first Node in InOrder_Traverse
{
    while(T->ltag==0) T = T->lchild;
    return T;
}

ThreadTree NextNode(ThreadTree T) //Find next Node in InOrder_Traverse

{
    if(T->rtag==1)  return T->rchild;
    return FirstNode(T->rchild);
}

void Traverse_ThreadTree_InOrder (ThreadTree T)  //InOrder_Traverse ThreadTree 
{
    for(ThreadTree p = FirstNode(T); p!=NULL; p = NextNode(p))
        cout<<p->data<<" ";
}