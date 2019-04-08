/******************************
Description: 归并排序实现
Author: ZhangBob
Date: 2019.04.05
*****************************/

#include "ArrayUtils.hpp"

class MergeSortUtil
{
private:
    char *m_pData;
    int m_Size;
    char *m_pTempData;

private:
    void Merge(int lo, int mid, int hi);
    void Sort(int lo, int hi);

public:
    MergeSortUtil(char *data, int size);
    ~MergeSortUtil();
    void Sort();
};

MergeSortUtil::MergeSortUtil(char *data, int size)
:m_pData(data), m_Size(size), m_pTempData(NULL)
{
    // create temp array.
    m_pTempData = new char[m_Size];
}

MergeSortUtil::~MergeSortUtil()
{
    if(NULL != m_pTempData)
    {
        delete [] m_pTempData;
        m_pTempData = NULL;
    }
}

void MergeSortUtil::Merge(int lo, int mid, int hi)
{
    if(NULL == m_pTempData)
    {
        return;
    }

    // merge data[lo...mid] and data[mid+1...hi]
    int i = lo, j = mid + 1;

    // make a temporary array
    for(int k=lo; k<= hi; ++k)
    {
        m_pTempData[k] = m_pData[k];
    }

    // merge temp array back to data array
    for(int k=lo; k<=hi; ++k)
    {
        if(i > mid)
        {
            m_pData[k] = m_pTempData[j++];
        }
        else if(j > hi)
        {
            m_pData[k] = m_pTempData[i++];
        }
        else if(LessThan<char>(m_pTempData[j], m_pTempData[i]))
        {
            m_pData[k] = m_pTempData[j++];
        }
        else
        {
            m_pData[k] = m_pTempData[i++];
        }
    }
}

void MergeSortUtil::Sort(int lo, int hi)
{
    if(NULL == m_pTempData)
    {
        return;
    }

    if(hi<=lo)
        return;

    int mid = lo+(hi-lo)/2;

    Sort(lo, mid);
    Sort(mid+1, hi);

    Merge(lo, mid, hi);

    ShowArray<char>(m_pData, m_Size);
}

void MergeSortUtil::Sort()
{
    Sort(0, m_Size-1);
}

int main()
{
    char data[] = {'Z','h','a','n','g','B','o','b'};

    ShowArray<char>(data, sizeof(data));

    // create merge sort utils
    MergeSortUtil sortUtil(&data[0], sizeof(data));

    sortUtil.Sort();
}