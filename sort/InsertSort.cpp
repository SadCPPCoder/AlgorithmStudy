/******************************
Description: 插入排序实现
Author: ZhangBob
Date: 2019.04.04
*****************************/

#include "ArrayUtils.hpp"

int main()
{
	char data[] = {'Z','h','a','n','g','B','o','b'};
	// char data[] = {'Z','H','A','N','G'};

	ShowArray<char>(data, sizeof(data));

	for(int i=1; i<sizeof(data); ++i)
	{
		for(int j=i; j>0; --j)
		{
			if(LessThan<char>(data[j], data[j-1]))
			{
				Exchange<char>(data, j,j-1);
			}
			else
			{
				break;
			}
		}
		ShowArray<char>(data, sizeof(data));
	}

}