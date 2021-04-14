//
// Created by 周昊 on 2021/3/7.
//

#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include <cstdio>
#include<string>
using namespace std;

class node
{
public:
    double num;
    char op;
    bool flag;// true为num，false为op
};

string s;
stack<node> st;//操作符栈
queue<node> q;//后缀表达式队列
map<char,int> m = {{'*',1},{'/',1},{'+',0},{'-',0}};

void change()
{
    for(int i = 0;i<s.length();)
    {
        node temp;
        if(s[i]>='0'&&s[i]<='9')
        {
            temp.flag = 1;
            temp.num = s[i++]-'0';
            while(i<s.length()&&s[i]>='0'&&s[i]<='9')
            {
                temp.num = temp.num*10+(s[i]-'0');
                i++;
            }
            q.push(temp);
        }
        else
        {
            temp.flag = 0;
            temp.op = s[i];
            while(!st.empty()&&m[s[i]]<=m[st.top().op])
            {
                q.push(st.top());
                st.pop();
            }
            st.push(temp);
            i++;
        }

    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

double calculate()
{
    node temp,temp1,temp2;
    while(!q.empty())
    {
        node x = q.front();
        q.pop();
        if(x.flag == 1)
        {
            st.push(x);
        }
        else
        {
            temp2 = st.top();
            st.pop();
            temp1 = st.top();
            st.pop();
            temp.flag = 1;
            if(x.op == '+') temp.num = temp1.num+temp2.num;
            else if(x.op == '-')temp.num = temp1.num-temp2.num;
            else if(x.op == '*')temp.num = temp1.num*temp2.num;
            else temp.num = temp1.num/temp2.num;
            st.push(temp);
        }
    }
    return st.top().num;
}

/*
int main()
{
    while(getline(cin,s),s!="0")
    {
        for(string::iterator it = s.begin();it != s.end();it++)
            if((*it) == ' ') s.erase(it);//去空格

        while (!q.empty()) q.pop();//初始化
        while (!st.empty()) st.pop();

        change();
        printf("%.2f\n",calculate());
    }
    return 0;
}*/
