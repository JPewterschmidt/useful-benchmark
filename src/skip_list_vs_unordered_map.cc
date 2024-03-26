#include "benchmark/benchmark.h"
#include "toolpex/skip_list.h"
#include "util.h"
#include <unordered_map>
#include <map>

static void BM_unordered_map__INSERT(benchmark::State& state)
{
    ::std::unordered_map<uintptr_t, int> m;
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (uintptr_t item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_unordered_map__INSERT);

static void BM_unordered_map__FIND(benchmark::State& state)
{
    ::std::unordered_map<uintptr_t, int> m;
    const auto address_vec = example_addrs();
    for (uintptr_t item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (uintptr_t item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_unordered_map__FIND);

static void BM_skip_list32__INSERT(benchmark::State& state)
{
    toolpex::skip_list<uintptr_t, int> m{32};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (uintptr_t item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_skip_list32__INSERT);

static void BM_skip_list32__FIND(benchmark::State& state)
{
    toolpex::skip_list<uintptr_t, int> m{32};
    const auto address_vec = example_addrs();
    for (uintptr_t item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (uintptr_t item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_skip_list32__FIND);

static void BM_skip_list26__INSERT(benchmark::State& state)
{
    toolpex::skip_list<uintptr_t, int> m{26};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (uintptr_t item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_skip_list26__INSERT);

static void BM_skip_list26__FIND(benchmark::State& state)
{
    toolpex::skip_list<uintptr_t, int> m{26};
    const auto address_vec = example_addrs();
    for (uintptr_t item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (uintptr_t item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_skip_list26__FIND);

static void BM_skip_list16__INSERT(benchmark::State& state)
{
    toolpex::skip_list<uintptr_t, int> m{16};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (uintptr_t item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_skip_list16__INSERT);

static void BM_skip_list16__FIND(benchmark::State& state)
{
    toolpex::skip_list<uintptr_t, int> m{16};
    const auto address_vec = example_addrs();
    for (uintptr_t item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (uintptr_t item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_skip_list16__FIND);

static void BM_map__INSERT(benchmark::State& state)
{
    ::std::map<uintptr_t, int> m{};
    const auto address_vec = example_addrs();
    for (auto _ : state)
    {
        for (uintptr_t item : address_vec)
            m[item] = 0;
    }
}
BENCHMARK(BM_map__INSERT);

static void BM_map__FIND(benchmark::State& state)
{
    ::std::map<uintptr_t, int> m{};
    const auto address_vec = example_addrs();
    for (uintptr_t item : address_vec)
        m[item] = 0;
    for (auto _ : state)
    {
        int v{};
        for (uintptr_t item : address_vec)
        {
            v = m[item];
            benchmark::DoNotOptimize(v);
        }
    }
}
BENCHMARK(BM_map__FIND);

