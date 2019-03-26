#pragma once

#include <cstdint>

class CPcMemoryInfoCollector {
public:
    CPcMemoryInfoCollector();
    ~CPcMemoryInfoCollector();

    void findAmountOfAllAvailableMemory();
    void findMaxSizeOfSingleBlockOnHeap();
    void collectAndPrintData();

private:
    static constexpr uint64_t MIN_TEST_VAL = 15000000000;
    static constexpr  uint64_t MAX_TEST_VAL = 100000000000;

    uint64_t amountOfAllAvailableMemory;
    uint64_t maxSizeOfSingleBlock;

};

