#include "PcMemoryInfoCollector.h"
#include <iostream>
#include <vector>


CPcMemoryInfoCollector::CPcMemoryInfoCollector() :
    amountOfAllAvailableMemory(0),
    maxSizeOfSingleBlock(0) {}


CPcMemoryInfoCollector::~CPcMemoryInfoCollector() {}


void CPcMemoryInfoCollector::findAmountOfAllAvailableMemory() {
    volatile char* p = nullptr;
    uint64_t cntr = MIN_TEST_VAL;

    try
    {
        for(; cntr < MAX_TEST_VAL; ++cntr)
        {
            p = new char;
        }
    }
    catch (std::exception& e)
    {
        amountOfAllAvailableMemory = cntr;
        delete p;
    }
}


void CPcMemoryInfoCollector::findMaxSizeOfSingleBlockOnHeap() {
    volatile char* p = nullptr;
    uint64_t cntr = MIN_TEST_VAL;

    try {

        for (; cntr < MAX_TEST_VAL; cntr+=10000000) {
            p = new (char[cntr]);

            std::cout << p[cntr-1];

            delete[] p;
        }

    }
    catch (std::exception& e)
    {
        maxSizeOfSingleBlock = cntr;
    }
}

void CPcMemoryInfoCollector::collectAndPrintData() {
    findAmountOfAllAvailableMemory();
    findMaxSizeOfSingleBlockOnHeap();

    std::cout << "Total amount: ~" << amountOfAllAvailableMemory << "\n"
        << "Max size of single block: " << maxSizeOfSingleBlock << "\n";
}
