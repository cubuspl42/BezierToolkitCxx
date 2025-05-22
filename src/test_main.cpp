#include "CubicBezierCurve.h"
#include "Vector2.h"

#include <gtest/gtest.h>

constexpr double loopTolerance = 0.25;

// A quite stretched loop, a "difficult" curve
const auto loopCubicBezierCurve =
    CubicBezierCurve(Vector2(233.92449010844575, 500.813035986871),
                     Vector2(863.426829231712, 303.18800785949134),
                     Vector2(470.8281371401481, 66.10460001139108),
                     Vector2(618.8718876196799, 463.88943518670203)

    );

constexpr int highSegmentCount = 10000;

TEST(CubicBezierCurveTests, calculateTotalArcLength_loop) {
    EXPECT_NEAR(
        loopCubicBezierCurve.calculateTotalArcLength(),
        loopCubicBezierCurve.calculateTotalArcLengthNaively(highSegmentCount),
        loopTolerance);
}

TEST(CubicBezierCurveTests, calculateTotalArcLengthNaively_loop) {
    EXPECT_NEAR(
        loopCubicBezierCurve.calculateTotalArcLengthNaively(),
        loopCubicBezierCurve.calculateTotalArcLengthNaively(highSegmentCount),
        loopTolerance);
}

constexpr double safeTolerance = 0.01;

// A basic, safe curve, an "easy" curve
const auto safeCubicBezierCurve =
    CubicBezierCurve(Vector2(233.92449010844575, 500.813035986871),
                     Vector2(342.6857845397117, 427.3674998486913),
                     Vector2(464.10040951107476, 363.7106139583648),
                     Vector2(618.8718876196799, 463.88943518670203)

    );

TEST(CubicBezierCurveTests, calculateTotalArcLength_safe) {
    EXPECT_NEAR(
        safeCubicBezierCurve.calculateTotalArcLength(),
        safeCubicBezierCurve.calculateTotalArcLengthNaively(highSegmentCount),
        safeTolerance);
}

TEST(CubicBezierCurveTests, calculateTotalArcLengthNaively_safe) {
    EXPECT_NEAR(
        safeCubicBezierCurve.calculateTotalArcLengthNaively(),
        safeCubicBezierCurve.calculateTotalArcLengthNaively(highSegmentCount),
        safeTolerance);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
