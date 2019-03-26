#include "PcMemoryInfoCollector.h"
#include <iostream>
#include <vector>


CPcMemoryInfoCollector::CPcMemoryInfoCollector() :
    amountOfAllAvailableMemory(0),
    maxSizeOfSingleBlock(0) {}


CPcMemoryInfoCollector::~CPcMemoryInfoCollector() {}


void CPcMemoryInfoCollector::findAmountOfAllAvailableMemory() {

    constexpr uint64_t MAX_NUM_OF_BYTES = 100000000000;
    char** memory_vector = new char*[0xffff];

    for (uint64_t i = 0; i < MAX_NUM_OF_BYTES; ++i) {

        try {
            memory_vector[i] = new(char);
        }
        catch (...) {
            std::cout << "Exception: ";
            return;
        }

        amountOfAllAvailableMemory = i;
    }

}


void CPcMemoryInfoCollector::findMaxSizeOfSingleBlockOnHeap() {
    char* p = nullptr;
    constexpr uint64_t TEST_VAL = 15000000000;
    uint64_t cntr = TEST_VAL;

    try {

        for (; cntr < 150000000000; cntr+=100000) {
            p = new char[cntr];

            p[cntr-1] = 34;

            std::cout << p[cntr-1];

            delete[] p;
        }

    }
    catch (...)
    {
        std::cout << "Exception: ";
        maxSizeOfSingleBlock = cntr;
    }
}

void CPcMemoryInfoCollector::calculateMetricTime() {

}

void CPcMemoryInfoCollector::collectAndPrintData() {
    //findAmountOfAllAvailableMemory();
    findMaxSizeOfSingleBlockOnHeap();

    std::cout << "Total amount: ~" << amountOfAllAvailableMemory << "\n"
        << "Max size of single block: " << maxSizeOfSingleBlock << "\n";
}
