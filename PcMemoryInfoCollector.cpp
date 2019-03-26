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

    try {

        for (int i = 100000; i < 1000000000; i+=10) {
            p = new char[i];

            delete[] p;
        }

    }
    catch (...)
    {
        std::cout << "Exception: ";
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
