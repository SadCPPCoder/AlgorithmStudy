/***************************************
Description: 计时器辅助工具函数
Author: ZhangBob
Date: 2019.04.08
****************************************/

#include <chrono>
#include "TimeCounter.hpp"

void TimeCounter::Start()
{
    mTimeStart = high_resolution_clock::now();
}

void TimeCounter::Stop()
{
    mTimeStop = high_resolution_clock::now();
}

double TimeCounter::Count()
{
    // return the time count in seconds
    return duration_cast<duration<double>>(mTimeStop - mTimeStart).count();
}