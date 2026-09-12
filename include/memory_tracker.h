#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include <cstddef>

class MemoryTracker
{
private:
    static std::size_t allocations;
    static std::size_t deallocations;

public:
    static void recordAllocation();
    static void recordDeallocation();
    static void report();
};

#endif