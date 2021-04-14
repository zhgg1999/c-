//
// Created by 周昊 on 2021/3/7.
//

#include <iostream>
#include <queue>
using namespace std;
/*int r,c;
const int maxn = 100;

char matrix[maxn][maxn];//迷宫
bool inq[maxn][maxn] = {false};//是否已经入队

int X[4] = {0,0,-1,1};//遍历相邻节点
int Y[4] = {1,-1,0,0};

class Node{
public:
    int x,y,step = 0;
};
Node node,S,T;

bool judge(int x,int y) //判断相邻节点是否满足加入队列的条件
{
    if(x == r || x<0 || y < 0 || y == c)
        return false;
    if(inq[x][y] == true || matrix[x][y] == '*')
        return false;
    return true;
}

int BFS()
{
    queue<Node> q;
    q.push(S);
    while (!q.empty())
    {
        Node temp = q.front();//temp用于遍历，保存当前出队节点
        q.pop();
        if(temp.x == T.x && temp.y == T.y)
            return temp.step;
        for(int i =0;i<4;i++)//遍历邻接点
        {
                int NewX = temp.x+X[i];int NewY = temp.y+Y[i];
                if(judge(NewX,NewY))
                {
                    node.x = NewX;
                    node.y = NewY;//node用于接收新节点入队使用
                    node.step = temp.step+1;
                    inq[NewX][NewY] = true;
                    q.push(node);
                }
        }
    }
    return -1;//队列为空，遍历完毕，说明走不出

}*/

/*int main()
{
    cin>>r>>c;//矩阵的大小
    for(int i =0;i<r;i++)
    {
        getchar();
        for(int j =0;j<c;j++)
        {
            matrix[i][j] = getchar();
        }
        //matrix[i][c+1] = '\0';
    }

    cin>>S.x>>S.y>>T.x>>T.y;
    cout<<BFS()<<endl;
    return 0;
}*/

