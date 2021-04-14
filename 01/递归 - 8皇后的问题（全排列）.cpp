//
// Created by 周昊 on 2021/3/12.
//
#include <iostream>
#include <vector>
using namespace std;
int num;//个数

bool hashtable[9] = {0};
int all[93][9];
int p[9];
int r = 1;

void DFS(int index)
{
    if(index == 9)
    {
        for(int i =1;i<=8;i++)
        {
            all[r][i] = p[i];
        }
        r++;
        return;
    }

    for(int i = 1;i<=8;i++)//枚举1~8，开始全排列，并且这样做的全排列，各位相加的和已经是从小到大开始排列了，毕竟是从小到大进行枚举
    {
        if(hashtable[i] == 0)
        {
            bool flag = true;
                for(int pre = 1;pre<index;pre++)//检查斜线是否合理
                {
                    if(abs(index-pre) == abs(i-p[pre]))
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)//合理才存入数据
                {
                    p[index] = i;
                    hashtable[i] = 1;
                    DFS(index+1);
                    hashtable[i] = 0;
                }
        }
    }

}


/*
int main()
{
    DFS(1);
    scanf("%d",&num);
    for(int i =0;i<num;i++)
    {
        int x;
        cin>>x;
        for(int j =1;j<=8;j++)
            cout<<all[x][j];
        cout<<endl;
    }
    return 0;
}*/
