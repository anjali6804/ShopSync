#include "../include/memory_tracker.h"

#include <iostream>

std::size_t MemoryTracker::allocations = 0;
std::size_t MemoryTracker::deallocations = 0;

std::unordered_set<void*> MemoryTracker::activeAllocations;

void MemoryTracker::recordAllocation(void* address)
{
    if (address == nullptr)
    {
        return;
    }

    auto result = activeAllocations.insert(address);

    if (result.second)
    {
        allocations++;
    }
}

void MemoryTracker::recordDeallocation(void* address)
{
    if (address == nullptr)
    {
        return;
    }

    if (activeAllocations.erase(address) > 0)
    {
        deallocations++;
    }
}

void MemoryTracker::report()
{
    std::cout << "\n========== MEMORY REPORT ==========\n";
    std::cout << "Allocations   : " << allocations << '\n';
    std::cout << "Deallocations : " << deallocations << '\n';
    std::cout << "Active blocks : " << activeAllocations.size() << '\n';

    if (activeAllocations.empty())
    {
        std::cout << "Memory status : No potential leaks detected.\n";
    }
    else
    {
        std::cout << "Memory status : Potential memory leaks detected.\n";
        std::cout << "Leaked blocks :\n";

        for (void* address : activeAllocations)
        {
            std::cout << "  " << address << '\n';
        }
    }
}