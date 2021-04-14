#include <iostream>
#include <queue>
using namespace std;

class BTnode
{
public:
    int data;
    BTnode * lchild = NULL;
    BTnode * rchild = NULL;
};
typedef BTnode* BTree;

//新建节点
BTnode * newNode(int x)
{
    BTnode * node = new BTnode;
    node->data = x;
    return node;
}

//BST插入法,左子树小于根节点小于右子树
void insert(BTnode * &root,int x)
{
    if(root == NULL)
    {
        root = newNode(x);
        return;
    }

    if(x<root->data)
        insert(root->lchild,x);
    else
        insert(root->rchild,x);

}


int pre[7] = {5,2,1,6,10,9,13};
int in[7] = {1,2,5,6,9,10,13};
int post[7] = {1,2,9,13,10,6,5};

//根据前中序列进行二叉树的创建
BTnode* createPI(int preL,int preR,int inL,int inR)
{
    if(preL>preR)
        return NULL;

    BTree root = new BTnode;
    root->data = pre[preL];

    int k;
    for(k = inL;k<=inR;k++)
    {
        if(in[k] == pre[preL])
            break;
    }
    int leftnum = k - inL;

    root->lchild = createPI(preL+1,preL+leftnum,inL,k-1);
    root->rchild = createPI(preL+leftnum+1,preR,k+1,inR);

    return root;
}

//根据中后序列进行二叉树的创建
BTnode* createIP(int postL,int postR,int inL,int inR)
{
    if(postL>postR)
        return NULL;

    BTnode *root = new BTnode;
    root->data = post[postR];

    int k;
    for(k = inL;k<=inR;k++)
    {
        if(in[k] == post[postR])
            break;
    }
    int leftnum = k - inL;

    root->lchild = createIP(postL,postL+leftnum-1,inL,k-1);
    root->rchild = createIP(postL+leftnum,postR-1,k+1,inR);

    return root;
}

//递归遍历
void inorder(BTree root)
{
    if(root == NULL)
        return;
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
}

void preorder(BTree root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(BTree root)
{
    if(root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<" ";
}
//层次遍历
void layerorder(BTree root)
{
    if(root == NULL)
        return;
    queue<BTnode*> q;
    q.push(root);
    while (!q.empty())
    {
        BTnode * now = q.front();
        q.pop();
        cout<<now->data<<" ";
        if(now->lchild != NULL) q.push(now->lchild);
        if(now->rchild != NULL) q.push(now->rchild);
    }

}
//BST删除的找前驱后继操作
BTnode * findMin(BTnode * root)
{
    while(root->lchild != NULL)
    {
            root= root->lchild;
    }
    return root;
}

BTnode * findMax(BTnode * root)
{
    while(root->rchild != NULL)
    {
        root= root->rchild;
    }
    return root;
}
//BST的删除操作
void DeleteNode(BTnode * &root,int x)
{
    if(root == NULL)
        return;
    if(root->data == x)
    {
        if(root->lchild == NULL && root->rchild == NULL)
            root = NULL;
        else if(root->lchild != NULL)
        {
            BTnode * pre = findMax(root->lchild);
            root->data = pre->data;
            DeleteNode(root->lchild,pre->data);
        }
        else if(root->rchild != NULL)
        {
            BTnode * next = findMin(root->rchild);
            root->data = next->data;
            DeleteNode(root->rchild,next->data);
        }
    }
    else if(x<root->data)
        DeleteNode(root->lchild,x);
    else
        DeleteNode(root->rchild,x);

}


