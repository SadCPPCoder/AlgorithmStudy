/***************************************
Description: 快速排序实现
Author: ZhangBob
Date: 2019.04.08
****************************************/

#include <string>

#include "ArrayUtils.hpp"
#include "TimeCounter.hpp"

int partition(int array[], int lo, int hi)
{
    int indexLeft = lo;
    int indexRight = hi+1; // this add 1 is improtant

    // set the value of index lo as the compare value
    int compareVal = array[lo];

    while(true)
    {
        // find the first value's index which the value is bigger than compareVal
        while(compareVal >= array[++indexLeft])
        {
            if(hi == indexLeft)
                break;
        }

        // find the first value's index which the value is littler than compareVal
        while(compareVal <= array[--indexRight])
        {
            if(lo == indexRight)
            {
                break;
            }
        }

        if( indexLeft >= indexRight )
        {
            break;
        }

        // exchange the two value of the indexs.
        Exchange<int>(array, indexLeft, indexRight);
    }

    // when quit the loop, the indexRight is pointted to the one littler than compareVal
    // and the left part is the value all littler than compareVal
    // so, move the compare value to indexRight
    Exchange<int>(array, lo, indexRight);

    return indexRight;
}

void QuickSort(int array[], int lo, int hi)
{
    if(hi <= lo)
        return;

    int compareFinalIndex = partition(array, lo, hi);

    QuickSort(array, lo, compareFinalIndex - 1); // sort array[lo...compareFinalIndex-1]
    QuickSort(array, compareFinalIndex + 1, hi); // sort array[compareFinalIndex + 1...hi]
}

int main(int argc, char **argv)
{
    if(1 >= argc)
    {
        cout << "Should input a integer parameter!\n";
        return -1;
    }

    std::string strNum(argv[1]);

    const int length = std::stoi(strNum);

    if(0 >= length)
    {
        cout << "Invalid input, should input integer!\n";
        return -1;
    }

    int data[length];

    RandomArray<int>(data, length, 0, 2*length);

    ShowArray<int>(data, length);

    TimeCounter timer;
    timer.Start();

    QuickSort(data, 0, length-1);

    timer.Stop();

    ShowArray<int>(data, length);

    cout << "Test array sortted by QuickSort finished!\n"
         << "Size: " << length << endl
         << "Time Cost: " << std::fixed << timer.Count() << " seconds" << endl;
}