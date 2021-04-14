//
// Created by 周昊 on 2021/3/17.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[5] = {0};//是否被访问
int edge[5][5] = {0};//邻接矩阵
vector<int> Adj[5];//邻接表---vector实现

//邻接表---链表实现
class Enode
{
public:
    int v;
    Enode * next = NULL;
};

class Vertex
{
public:
    Enode * first = NULL;
};
Vertex ADJ[5];

void DFS(int v,int depth)
{
    visit[v] = 1;
    cout<<v;
    for(int i =0;i<5;i++)
    {
        if(visit[i] == 0 && edge[v][i] != 0)
            DFS(i,depth+1);
    }
}

void DFSTravel()
{
    for(int i =0;i<5;i++)
    {
        if(visit[i] == 0)
            DFS(i,1);
    }
}

void DFS1(int v,int depth)
{
    visit[v] = 1;
    cout<<v;
    for(int i =0;i<Adj[v].size();i++)
    {
        int u = Adj[v][i];
        if(visit[u] == 0)
            DFS1(u,depth+1);
    }
}

void DFSTravel1()
{
    for(int i =0;i<5;i++)
    {
        if(visit[i] == 0)
        DFS1(i,1);
    }
}

void BFS(int v)
{
    queue<int> q;
    q.push(v);
    visit[v] = 1;
    while(!q.empty())
    {
        int now = q.front();
        cout<<now;
        q.pop();
        for(int i =0;i<Adj[now].size();i++)
        {
            int next = Adj[v][i];
            if(visit[next] == 0)
            {
                visit[next] = 1;
                q.push(next);
            }

        }
    }
}

void BFSTravel()
{
    for(int i =0;i<5;i++)
    {
        if(visit[i] == 0)
            BFS(i);
    }
}


int main()
{
    Adj[0].push_back(1);
    Adj[0].push_back(2);
    Adj[1].push_back(3);
    Adj[1].push_back(4);
    Adj[2].push_back(1);
    Adj[2].push_back(4);
    Adj[4].push_back(3);
    BFSTravel();
    return 0;
}

