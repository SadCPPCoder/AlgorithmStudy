/***************************************
Description: Array辅助工具函数
Author: ZhangBob
Date: 2019.04.04
****************************************/
#include <functional> // for bind
#include <iostream>
#include <random> // for random data

using std::cout;
using std::endl;

template<typename T>
void Exchange(T array[], int indexA, int indexB)
{
	T temp = array[indexB];
	array[indexB] = array[indexA];
	array[indexA] = temp;
}

template<typename T>
bool LessThan(T &a, T &b)
{
	return a<b;
}

template<typename T>
void ShowArray(T array[], int size)
{
	for(int i=0; i<size; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template<typename T>
void RandomArray(T array[], int size, int start, int end)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(start, end);
    auto get_random = std::bind(distribution, generator);

    for(int i=0; i<size; ++i)
    {
        array[i] = static_cast<T>(get_random());
    }
}