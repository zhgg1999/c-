//
// Created by 周昊 on 2021/3/11.
//
#include <iostream>
#include <algorithm>
using namespace std;

int father[110] ;


int findfather(int son)
{
    if(son == father[son])  return father[son];
    else return findfather(father[son]);
}

//路径压缩版,和上面的进行比较学习
int findFather(int son)
{
    if(son == father[son])  return father[son];
    else
    {
        int F = findFather(father[son]);
        father[son] = F;
        return F;
    }
}

void Union(int a,int b)
{
    int Fa = findfather(a);
    int Fb = findfather(b);
    if(Fa != Fb)
        father[Fb] = Fa;
}

/*
int main()
{
    for(int i =0;i<110;i++)//初始化并查集
    {
        father[i] =i;
    }

    int num,orgnum;
    cin>>num>>orgnum;
    for(int i =0;i<orgnum;i++)
    {
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }
    int count = 0;
    for(int i =1;i<=num;i++) {
        if(father[i] == i)
            count++;
    }
    cout<<count<<endl;
    return 0;
}*/
