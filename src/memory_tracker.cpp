#include "../include/memory_tracker.h"

#include <iostream>

std::size_t MemoryTracker::allocations = 0;
std::size_t MemoryTracker::deallocations = 0;

void MemoryTracker::recordAllocation()
{
    allocations++;
}

void MemoryTracker::recordDeallocation()
{
    deallocations++;
}

void MemoryTracker::report()
{
    std::cout << "\n========== MEMORY REPORT ==========\n";
    std::cout << "Allocations   : " << allocations << '\n';
    std::cout << "Deallocations : " << deallocations << '\n';

    if (allocations == deallocations)
    {
        std::cout << "Memory status : No potential leaks detected.\n";
    }
    else
    {
        std::cout << "Memory status : Potential memory leak detected.\n";
        std::cout << "Unreleased allocations : "
                  << allocations - deallocations << '\n';
    }
}