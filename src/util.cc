#include "util.h"
#include <random>
#include <iostream>

::std::vector<uintptr_t> example_addrs(size_t data_scale)
{
    static ::std::vector<uintptr_t> result = [=]{
        constexpr uintptr_t heap_start = 0x00007fff80000000;
        constexpr uintptr_t heap_end = 0x00007fffffffffff;

        // Seed the random number generator
        std::random_device rd;
        std::mt19937_64 gen(rd());
        
        // Generate a random address within the heap range
        std::uniform_int_distribution<uintptr_t> distribution(heap_start, heap_end);

        ::std::vector<uintptr_t> addrs;
        for (size_t i{}; i < data_scale; ++i)
        {
            addrs.emplace_back(distribution(gen));   
        }
        ::std::cout << "example_addrs: data_scale = " << data_scale << ::std::endl;
        return addrs;
    }();

    return result;
}

