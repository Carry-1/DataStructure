#include <iostream>
#include <stack>
using namespace std;
typedef int ElemType;
typedef struct BitNode{       //Binary Tree
    ElemType data;
    struct BitNode *lchild, *rchild;
}BitNode, *BiTree;

BiTree CreatTree(BiTree &root, int Array[]);
void Traverse_PreOrder(BiTree T);
void Traverse_PreOrder_NonRecursion(BiTree T);

stack <BiTree> S;     //store pointer

int main()
{
    int Array[] = {1,2,3,4,5,6,7,8}; 
    BiTree T =NULL;
    CreatTree(T, Array); // Build Binary Tree
    //cout<<"Traverse in PreOrder:"<<endl;
    //Traverse_In_PreOrder(T);
    //cout<<endl;

    cout<<"Traverse in PreOrder(No Recursion):"<<endl;
    Traverse_PreOrder_NonRecursion(T);
    cout<<endl;

    return 0;
}


BiTree newNode(ElemType e)      //generate new node
{
    BiTree p = new BitNode;
    p->data = e;
    p->lchild = p->rchild = NULL;
    return p;
}

void Insert(BiTree &root, ElemType e)     //Insert Node
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


BiTree CreatTree(BiTree &root, int Array[])     //Build Binary Tree
{
    for (int i=0; i<8; i++)
        Insert(root, Array[i]);
    return root;
}
void Traverse_PreOrder(BiTree T)
{
    if(T){
        cout<<T->data<<" ";
        Traverse_PreOrder(T->lchild);
        Traverse_PreOrder(T->rchild);
    }
}

void Traverse_PreOrder_NonRecursion(BiTree T)
{
    BiTree p = T;
    while(p||!S.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }

}
