#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;

class Student
{
public:
    Student(string n,int g)
    {
        this->grade = g;
        this->name = n;
    }

    int grade;
    string name;
};

class great
{
public:
    bool operator()(Student &s1,Student&s2)
    {
        return s1.grade>s2.grade;
    }

};

void test01()
{
    //优先队列中的排序规则与sort相反

    priority_queue<Student,vector<Student>,great> q;//自定义数据类型的处理
    q.push(Student("张三",99));
    q.push(Student("李四",100));
    q.push(Student("王五",66));
    cout<<q.top().name<<" "<<q.top().grade<<endl;
}

/*int main()
{
    test01();
    return 0;
}*/
