#include "util.h"
#include <random>

::std::vector<uintptr_t> example_addrs()
{
    static ::std::vector<uintptr_t> result = []{
        constexpr uintptr_t heap_start = 0x00007fff80000000;
        constexpr uintptr_t heap_end = 0x00007fffffffffff;

        // Seed the random number generator
        std::random_device rd;
        std::mt19937_64 gen(rd());
        
        // Generate a random address within the heap range
        std::uniform_int_distribution<uintptr_t> distribution(heap_start, heap_end);

        ::std::vector<uintptr_t> addrs;
        for (size_t i{}; i < 100000; ++i)
        {
            addrs.emplace_back(distribution(gen));   
        }
        return addrs;
    }();

    return result;
}

