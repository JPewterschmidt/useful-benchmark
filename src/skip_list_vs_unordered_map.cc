#include "benchmark/benchmark.h"
#include "toolpex/skip_list.h"
#include <unordered_map>
#include <map>

static ::std::vector<void*> example_addrs()
{
    static ::std::vector<void*> result = []{
        constexpr uintptr_t heap_start = 0x00007fff80000000;
        constexpr uintptr_t heap_end = 0x00007fffffffffff;

        // Seed the random number generator
        std::random_device rd;
        std::mt19937_64 gen(rd());
        
        // Generate a random address within the heap range
        std::uniform_int_distribution<uintptr_t> distribution(heap_start, heap_end);

        ::std::vector<void*> addrs;
        for (size_t i{}; i < 100000; ++i)
        {
            addrs.emplace_back((void*)distribution(gen));   
        }
        return addrs;
    }();

    return result;
}

static void BM_unordered_map__INSERT(benchmark::State& state)
{
    ::std::unordered_map<const void*, int> m;
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (const auto* item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_unordered_map__INSERT);

static void BM_unordered_map__FIND(benchmark::State& state)
{
    ::std::unordered_map<const void*, int> m;
    const auto address_vec = example_addrs();
    for (const auto* item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (const auto* item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_unordered_map__FIND);

static void BM_skip_list32__INSERT(benchmark::State& state)
{
    toolpex::skip_list<const void*, int> m{32};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (const auto* item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_skip_list32__INSERT);

static void BM_skip_list32__FIND(benchmark::State& state)
{
    toolpex::skip_list<const void*, int> m{32};
    const auto address_vec = example_addrs();
    for (const auto* item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (const auto* item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_skip_list32__FIND);

static void BM_skip_list26__INSERT(benchmark::State& state)
{
    toolpex::skip_list<const void*, int> m{26};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (const auto* item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_skip_list26__INSERT);

static void BM_skip_list26__FIND(benchmark::State& state)
{
    toolpex::skip_list<const void*, int> m{26};
    const auto address_vec = example_addrs();
    for (const auto* item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (const auto* item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_skip_list26__FIND);

static void BM_skip_list16__INSERT(benchmark::State& state)
{
    toolpex::skip_list<const void*, int> m{16};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (const auto* item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_skip_list16__INSERT);

static void BM_skip_list16__FIND(benchmark::State& state)
{
    toolpex::skip_list<const void*, int> m{16};
    const auto address_vec = example_addrs();
    for (const auto* item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (const auto* item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_skip_list16__FIND);

static void BM_map__INSERT(benchmark::State& state)
{
    ::std::map<const void*, int> m{};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (const auto* item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_map__INSERT);

static void BM_map__FIND(benchmark::State& state)
{
    ::std::map<const void*, int> m{};
    const auto address_vec = example_addrs();
    for (const auto* item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (const auto* item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_map__FIND);

