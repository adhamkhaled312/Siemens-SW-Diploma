#include <benchmark/benchmark.h>
#include <./lib/print.hpp>

static void BM_printSum(benchmark::State& state) {
  for (auto _ : state)
    printSum(int(state.range(0)),int(state.range(0)));
}
BENCHMARK(BM_printSum)->RangeMultiplier(2)->Range(2<<15, 2<<25);


BENCHMARK_MAIN();