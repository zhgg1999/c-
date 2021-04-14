//
// 从N个数中选择k个数，使得k个数的和为x，如果sum相同，选平方和大
//

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 4;int x = 6;int k =2;int maxsqrt = -1;
int arr[4] = {2,3,3,4} ;
vector<int> temp,ans;

class myp{
public:
    void operator()(int a)
    {
        cout<<a;
    }
};

void DFS(int index,int now,int sum,int sum_sqrt)
{
    if(now == k&&sum == x)
    {
        if(sum_sqrt > maxsqrt)
        {
            maxsqrt = sum_sqrt;
            ans = temp;
        }
        return;
    }
    if(index == n||now>k||sum>x) return;

    temp.push_back(arr[index]);
    DFS(index+1,now+1,sum+arr[index],sum_sqrt+arr[index]*arr[index]);//加入index
    temp.pop_back();
    DFS(index+1,now,sum,sum_sqrt);//不加入index
}

/*
int main()
{
    int now = 0;
    int sum = 0;
    int sum_sqrt = 0;
    int index =0;
    DFS(index,now,sum,sum_sqrt);
    for_each(ans.begin(),ans.end(),myp());
    return 0;
}*/
