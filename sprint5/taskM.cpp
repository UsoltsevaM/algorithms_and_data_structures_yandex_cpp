﻿#include <cassert>
#include "solution.h"

#include <vector>
#include <algorithm>

int siftUp(std::vector<int>& heap, int idx)
{
    if (idx == 1)
        return idx;

    int parentIdx = idx / 2;
    if (heap[idx] > heap[parentIdx])
    {
        std::swap(heap[idx], heap[parentIdx]);
        return siftUp(heap, parentIdx);
    }

    return idx;
}

void test()
{
    std::vector<int> sample = { -1, 12, 6, 8, 3, 15, 7 };
    assert(siftUp(sample, 5) == 1);
}
