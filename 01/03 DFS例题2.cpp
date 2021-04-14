//
// Created by 周昊 on 2021/3/6.
//

#include<iostream>
using namespace std;
int n1,v;
int max_val = -1;
int w[10];
int c1[10];

void DFS(int index,int now_w,int val)
{
    if(index == n1)//已经遍历完n个数了
    {
        return;
    }

    DFS(index+1,now_w,val);//不选index号
    if(now_w+w[index] <= v)
    {
        if (val+c1[index]>max_val)
            max_val = val+c1[index];
        DFS(index+1,now_w+w[index],val+c1[index]);//选index号
    }

}

/*
int main()
{
    cin>>n1>>v;
    for(int i=0;i<n1;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n1;i++)
    {
        cin>>c[i];
    }
    DFS(0,0,0);
    cout<<max_val<<endl;

    return 0;
}*/
