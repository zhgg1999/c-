//
// Created by 周昊 on 2021/3/23.
//
#include <iostream>
#include <algorithm>
#define MAX 100
#define INF 0x3fffffff
using namespace std;

int v[MAX][MAX];//图
int d[MAX];//起始点联通各个顶点所需的开销
int n;//真实定点数
bool vis[MAX] = {false};
int pre[MAX];
int s;


void Dijkstra(int s)
{
    fill(d,d+MAX,INF);
    d[s]= 0;//顶点为0
    for(int m = 0;m<n;m++)//1.循环n次，总共有n个顶点,每次加入一个
    {
        int MIN = INF;
        int u = -1;
        for(int i  = 0;i<n;i++)//2.寻找目前与出发点联通花费最少的点
        {
            if (d[i] < MIN && !vis[i])
            {
                u = i;
                MIN = d[i];
            }
        }

        if (u == -1) return;//表明接下来的定点不连通

        vis[u] = true;
        for (int v1 = 0; v1 < n; v1++)
        {
            if (!vis[v1] && d[v1] > d[u] + v[u][v1] && v[u][v1] != INF)//u作为中转点后是否有对到达未访问过得节点距离优化
            {
                d[v1] = d[u] + v[u][v1];
                pre[v1] = u;//记录前驱节点，用于输出路径
            }
        }
    }
}

void DFS(int x)
{
    if(x == s)
    {
        cout<<s;
        return;
    }
    DFS(pre[x]);
    cout<<x;
}


int main()
{
    int m;
    cin>>n>>m>>s;
    fill(v[0],v[0]+MAX*MAX,INF);
    int h,r,w;
    for(int i =0;i<m;i++)
    {
        cin>>h>>r>>w;
        v[h][r] = w;

    }

    Dijkstra(s);
    for(int i =0;i<n;i++)
    {
        cout<<d[i];
        if(i!=n-1)
            cout<<" ";
    }
    cout<<endl;
    DFS(n-1);

    return 0;
}
