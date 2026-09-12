#include "../include/memory_tracker.h"

int main()
{
    int* first = new int(10);
    int* second = new int(20);

    MemoryTracker::recordAllocation(first);
    MemoryTracker::recordAllocation(second);

    delete first;
    MemoryTracker::recordDeallocation(first);

    MemoryTracker::report();

    delete second;
    MemoryTracker::recordDeallocation(second);

    MemoryTracker::report();

    return 0;
}
