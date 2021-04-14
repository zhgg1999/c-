#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100
class Node
{
public:
    int data;
    vector<int> child;
};
Node tree[MAX];//MAX位置表示当前节点，data为数据域，child为子节点

void preorder(int root)
{
    cout<<tree[root].data;
    for(int i =0;i<tree[root].child.size();i++)
    {
        preorder(tree[root].child[i]);
    }
};

void Layerorder(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int now = q.front();
        cout<<tree[now].data;
        q.pop();
        for(int i =0;i<tree[now].child.size();i++)
        {
            q.push(tree[now].child[i]);
        }
    }
}


