#include "CubicBezierCurve.h"

#include <iostream>

#include <benchmark/benchmark.h>

const auto loopCubicBezierCurve =
    CubicBezierCurve(Vector2(530.4940814557458, 241.67258884541297),
                     Vector2(961.5421048139829, 329.8998894073666),
                     Vector2(236.94848087916398, 6.644895194057426),
                     Vector2(476.141458980871, 199.36056001431643)

    );

static void
BM_CubicBezierCurve_calculateTotalArcLength(benchmark::State &state) {
    for (const auto _ : state) {
        (void)loopCubicBezierCurve.calculateTotalArcLength();
    }
}

BENCHMARK(BM_CubicBezierCurve_calculateTotalArcLength);

static void
BM_CubicBezierCurve_calculateTotalArcLengthNaively(benchmark::State &state) {
    for (const auto _ : state) {
        (void)loopCubicBezierCurve.calculateTotalArcLengthNaively();
    }
}

BENCHMARK(BM_CubicBezierCurve_calculateTotalArcLengthNaively);

const auto quadraticBezierBinomial = QuadraticBezierCurve(
    Vector2(0.0, 0.0), Vector2(100.0, 200.0), Vector2(200.0, 0.0));

static void
BM_QuadraticBezierCurve_calculateTotalArcLength(benchmark::State &state) {
    for (const auto _ : state) {
        (void)quadraticBezierBinomial.calculateTotalArcLength();
    }
}

BENCHMARK(BM_QuadraticBezierCurve_calculateTotalArcLength);

static void BM_QuadraticBezierCurve_calculateTotalArcLengthNaively(
    benchmark::State &state) {
    for (const auto _ : state) {
        (void)quadraticBezierBinomial.calculateTotalArcLengthNaively();
    }
}

BENCHMARK(BM_QuadraticBezierCurve_calculateTotalArcLengthNaively);

BENCHMARK_MAIN();
