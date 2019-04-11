/**********************************************
description: 基于对排序的有限队列
author: ZhangBob
date: 2019.04.11
**********************************************/

#include <iostream>
#include "ArrayUtils.hpp"

void swim(int arr[], int k)
{
    int k2 = 0==k? 0 : k/2;
    while( k > 1 && arr[k2] < arr[k] )
    {
        Exchange<int>(arr, k2, k);
        k = k2;
        k2 = k/2;
    }
}

void sink(int arr[], int &tail, int k)
{
    int j = 0;
    while( 2*k <= tail )
    {
        j = 2*k;
        if(j<tail && arr[j] < arr[j+1])
        {
            ++j;
        }
        if(!LessThan<int>(arr[k], arr[j])) break;

        Exchange<int>(arr, k, j);
        k = j;
    }
}

void insert(int arr[], int &tail, int val)
{
    arr[++tail] = val;
    swim(arr, tail);
}

int deleteMax(int arr[], int &tail)
{
    int max = arr[1];

    Exchange<int>(arr, 1, tail--);

    arr[tail+1] = 0;

    sink(arr, tail, 1);

    return max;
}

int main()
{
    int data_len = 100;
    int data[data_len];
    int tail = 0;

    RandomArray<int>(data, data_len, 0, data_len*2);

    ShowArray<int>(data, data_len);

    int heap[data_len+1];

    for(int i=0; i<data_len; ++i)
    {
        insert(heap, tail, data[i]);
    }

    for( int i=0; i<data_len; ++i)
    {
        cout << deleteMax(heap, tail) << " ";
    }
    cout << endl;
}