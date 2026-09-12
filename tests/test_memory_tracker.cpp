#include "../include/memory_tracker.h"

int main()
{
    MemoryTracker::recordAllocation();
    MemoryTracker::recordAllocation();

    MemoryTracker::recordDeallocation();

    MemoryTracker::report();

    return 0;
}
