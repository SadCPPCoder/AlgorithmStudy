/***************************************
Description: 计时器辅助工具函数测试
Author: ZhangBob
Date: 2019.04.08
****************************************/

#include "ArrayUtils.hpp"
#include "TimeCounter.hpp"

int main()
{
    const int length = 10000;
    int data[length];

    TimeCounter timer;

    timer.Start();
    RandomArray<int>(data, length, 0, 2*length);

    ShowArray<int>(data, length);
    timer.Stop();

    std::cout << "Generate random array which size is " << length << ", time cost: " << timer.Count() << " seconds.\n";
}