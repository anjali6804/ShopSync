#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include <cstddef>
#include <unordered_set>

class MemoryTracker
{
private:
    static std::size_t allocations;
    static std::size_t deallocations;

    static std::unordered_set<void*> activeAllocations;

public:
    static void recordAllocation(void* address);
    static void recordDeallocation(void* address);
    static void report();
};

#endif