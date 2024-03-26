#include "benchmark/benchmark.h"
#include "util.h"
#include <unordered_map>

struct wang_hash
{
public:
    size_t operator()(size_t key) const noexcept
    {
        key = (~key) + (key << 21); // key = (key << 21) - key - 1;
        key = key ^ (key >> 24);
        key = (key + (key << 3)) + (key << 8); // key * 265
        key = key ^ (key >> 14);
        key = (key + (key << 2)) + (key << 4); // key * 21
        key = key ^ (key >> 28);
        key = key + (key << 31);
        return key;
    }
};

struct murmur_hash3
{
public:
    size_t operator()(size_t key) const noexcept
    {
        constexpr uint64_t c1 = 0xff51afd7ed558ccd;
        constexpr uint64_t c2 = 0xc4ceb9fe1a85ec53;
        constexpr int r1 = 27;
        constexpr int r2 = 31;
        constexpr int r3 = 33;
        constexpr int m = 5;
        constexpr uint64_t seed = 0; // You can change the seed value if needed

        uint64_t h1 = seed;
        uint64_t k1 = key;
        k1 *= c1;
        k1 = (k1 << r1) | (k1 >> (64 - r1));
        k1 *= c2;

        h1 ^= k1;
        h1 = (h1 << r2) | (h1 >> (64 - r2));
        h1 = h1 * m + c1; // Adjusted from `n` to `c1`
        h1 ^= (h1 >> r3);
        h1 = h1 * c1;
        h1 ^= (h1 >> r2);
        h1 = h1 * c2;
        h1 ^= (h1 >> r1);

        return h1;
    }
};

void BM_unordered_map_for_addr__DEFAULT_IO(benchmark::State& state)
{
    ::std::unordered_map<uintptr_t, int> m;
    auto vec = example_addrs();
    for (auto _ : state)
    {
        int x;
        for (auto item : vec)
            m[item] = 0;

        for (auto item : vec)
        {
            x = m[item];
            benchmark::DoNotOptimize(x);
        }
    }
}
BENCHMARK(BM_unordered_map_for_addr__DEFAULT_IO);

void BM_unordered_map_for_addr__WANG_IO(benchmark::State& state)
{
    ::std::unordered_map<uintptr_t, int, wang_hash> m;
    auto vec = example_addrs();
    for (auto _ : state)
    {
        int x;
        for (auto item : vec)
            m[item] = 0;

        for (auto item : vec)
        {
            x = m[item];
            benchmark::DoNotOptimize(x);
        }
    }
}
BENCHMARK(BM_unordered_map_for_addr__WANG_IO);

void BM_unordered_map_for_addr__MURMUR_IO(benchmark::State& state)
{
    ::std::unordered_map<uintptr_t, int, murmur_hash3> m;
    auto vec = example_addrs();
    for (auto _ : state)
    {
        int x;
        for (auto item : vec)
            m[item] = 0;

        for (auto item : vec)
        {
            x = m[item];
            benchmark::DoNotOptimize(x);
        }
    }
}
BENCHMARK(BM_unordered_map_for_addr__MURMUR_IO);
