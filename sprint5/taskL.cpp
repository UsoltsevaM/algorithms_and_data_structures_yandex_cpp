﻿#include <vector>
#include <cassert>
#include "solution.h"

#include <algorithm>

int siftDown(std::vector<int>& heap, int idx)
{
    int leftIdx = 2 * idx;
    int rightIdx = 2 * idx + 1;

    if (leftIdx >= heap.size())
        return idx;

    int maxIdx = -1;
    if (rightIdx < heap.size() && heap[rightIdx] > heap[leftIdx])
        maxIdx = rightIdx;
    else
        maxIdx = leftIdx;

    if (heap[idx] < heap[maxIdx])
    {
        std::swap(heap[idx], heap[maxIdx]);
        return siftDown(heap, maxIdx);
    }

    return idx;
}

void test()
{
    std::vector<int> sample = { -1, 12, 1, 8, 3, 4, 7 };
    assert(siftDown(sample, 2) == 5);
}
