/********************************************
Description: 选择排序例子
Author: ZhangBob
Date: 2019.04.04
********************************************/

#include "ArrayUtils.hpp"

int main()
{
	char data[] = {'Z','h','a','n','g','B','o','b'};

	ShowArray<char>(data, sizeof(data));
	// select the min data and put into the front sort list
	int min = 0;
	for(int i=0; i<sizeof(data); ++i)
	{
		// update minium index
		min = i;
		for(int j=i+1; j<sizeof(data); ++j)
		{
			if(LessThan<char>(data[j], data[min]))
			{
				// update minium index
		        min = j;
			}
		}
		Exchange<char>(data, i, min);

		ShowArray<char>(data, sizeof(data));
	}
}