/******************************
Description: 希尔排序实现
Author: ZhangBob
Date: 2019.04.04
*****************************/

#include "ArrayUtils.hpp"

int main()
{
	char data[] = {'Z','h','a','n','g','B','o','b'};

	ShowArray<char>(data, sizeof(data));

    // Here we use the shell list h = (3^k-1)/2
    // Find the max h
    int h =1;
    while(h < sizeof(data)/3)
    {
        h = 3*h + 1;
    }

    // decrease h from h[max] to 1
    while(h>=1)
    {
        // list every h sorted array
        for(int i=h; i<sizeof(data); ++i)
        {
            // compare every item of each h sorted list
            for(int j=i; j>=h; j-=h)
            {
                if(LessThan<char>(data[j], data[j-h]))
                {
                    Exchange<char>(data, j, j-h);
                }
            }
        }
        ShowArray<char>(data, sizeof(data));
        h /= 3;
    }
}