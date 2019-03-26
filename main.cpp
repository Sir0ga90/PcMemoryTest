#include "PcMemoryInfoCollector.h"


int main()
{
    CPcMemoryInfoCollector memory_info_collector{};

    memory_info_collector.collectAndPrintData();
    return 0;
}