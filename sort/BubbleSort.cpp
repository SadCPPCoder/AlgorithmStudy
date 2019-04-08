/******************************
Description: 冒泡排序实现
Author: ZhangBob
Date: 2019.04.04
*****************************/

#include "ArrayUtils.hpp"

int main()
{
	char data[] = {'Z','h','a','n','g','B','o','b'};

	ShowArray<char>(data, sizeof(data));

	for(int i=0; i<sizeof(data); ++i)
	{
		for(int j=0; j<sizeof(data)-i-1; ++j)
		{
			if(LessThan<char>(data[j+1], data[j]))
			{
				Exchange<char>(data, j, j+1);
			}
		}
		ShowArray<char>(data, sizeof(data));
	}
}