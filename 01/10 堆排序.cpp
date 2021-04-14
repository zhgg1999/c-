//
// Created by 周昊 on 2021/3/15.
//
#include<iostream>
#include <algorithm>
using namespace std;
#define max 100
int heap[max];

//向下调整,O(log2N)
void downAdjust(int left,int right)
{
    int i = left;int j;
    for(j = 2*i;j<=right;j*=2)
    {
        if(heap[j]<heap[j+1]&&j+1<=right)//保证j+1不越界
            j++;
        if(heap[j]>heap[i])
        {
            swap(heap[i],heap[j]);
            i = j;//保持i为待调整节点，继续向下比较
        }
        else
            break;
    }
}
//建堆时间为O(n)
void createHeap(int len)
{
    for(int i =len/2;i>0;i--)
    {
        downAdjust(i,len);
    }
}

void deleteHeap(int len)
{
    heap[1] = heap[len--];
    downAdjust(1,len);
}


void upAdjust(int left,int right)
{
    int i = right;int j;
    for( j = i/2;j>=left;j/=2)
    {
        if(heap[i]>heap[j])
        {
            swap(heap[i],heap[j]);
            i = j;
        }
        else
            break;

    }
}
void insertHeap(int len,int x)
{
    heap[++len] = x;
    upAdjust(1,len);
}

void HeapSort(int len)
{
    createHeap(len);
    for(int i = len;i>1;i--)
    {
        swap(heap[1],heap[i]);
        downAdjust(1,i-1);
    }
}

/*int main()
{
    heap[1] = 85;
    heap[2] = 55 ;
    heap[3] = 82;
    heap[4] = 57;
    heap[5] = 68;
    heap[6] = 92;
    heap[7] = 99;
    createHeap(7);
    deleteHeap(7);
    insertHeap(6,100);
    HeapSort(7);
    for(int i =1;i<=7;i++)
    {
        cout<<heap[i]<<" ";
    }


    return 0;
}*/
