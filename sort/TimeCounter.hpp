/***************************************
Description: 计时器辅助工具函数
Author: ZhangBob
Date: 2019.04.08
****************************************/

#include <chrono>

using namespace std::chrono;

class TimeCounter
{
private:
    high_resolution_clock::time_point mTimeStart;
    high_resolution_clock::time_point mTimeStop;

public:
    TimeCounter(){};

    void Start();

    void Stop();

    double Count();
};