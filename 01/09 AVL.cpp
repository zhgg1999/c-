//
// Created by 周昊 on 2021/3/14.
//
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
public:
    int data;
    int height = 1;//初始化为1
    node*lchild = NULL;
    node*rchild = NULL;
};

node* NewNode(int x)
{
    node * root = new node;
    root->data = x;
    return root;
}

int getHeight(node * root)
{
    if(root == NULL) return 0;
    else
        return root->height;
}

void updateHeight(node * root)
{
    root->height = max(root->rchild->height,root->lchild->height)+1;
}

int getBalancedHeight(node *root)
{
    return root->lchild->height - root->rchild->height;
}

void L(node *root)
{
    node*temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node *root)
{
    node*temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void AVL_insert(node * &root,int x)
{
    if(root == NULL)
        root = NewNode(x);
    else if(x<root->data)
    {
        AVL_insert(root->lchild,x);//递归保证了每次调整的都是最大不平衡树
        updateHeight(root);//每一次的递归插入都会检查平衡因子是否合理
        if(getBalancedHeight(root) == 2)
        {
            if(getHeight(root->lchild) == 1)
                R(root);
            else
            {
                L(root->lchild);
                R(root);
            }
        }
        else if(getBalancedHeight(root) == -2)
        {
            if(getHeight(root->rchild) == 1)
            {
                R(root->rchild);
                L(root);
            }
            else
            {
                L(root);
            }
        }
    }
}

/*int main()
{
    int num;
    cin>>num;
    node * root = NULL;
    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        AVL_insert(root,x);
    }
    cout<<root->height<<endl;
    return 0;
}*/


