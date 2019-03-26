#pragma once

#include <cstdint>

class CPcMemoryInfoCollector {
public:
    CPcMemoryInfoCollector();
    ~CPcMemoryInfoCollector();

    void findAmountOfAllAvailableMemory();
    void findMaxSizeOfSingleBlockOnHeap();
    void calculateMetricTime();
    void collectAndPrintData();

private:
    uint64_t amountOfAllAvailableMemory;
    uint64_t maxSizeOfSingleBlock;

};

