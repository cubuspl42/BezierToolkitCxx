#include "CubicBezierCurve.h"

#include "LinSpace.h"
#include "Vector4.h"

#include <numeric>

static auto loweringVector0 = Vector4(0.95, 0.15, -0.15, 0.05);
static auto loweringVector1 = Vector4(-0.25, 0.75, 0.75, -0.25);
static auto loweringVector2 = Vector4(0.05, -0.15, 0.15, 0.95);

Vector2 CubicBezierCurve::evaluate(const double t) const {
    const double u = 1.0 - t;

    const double t2 = t * t;
    const double u2 = u * u;
    const double u3 = u2 * u;
    const double t3 = t2 * t;

    return point0() * u3 + point1() * (3 * u2 * t) + point2() * (3 * u * t2) +
           point3() * t3;
}

QuadraticBezierCurve
CubicBezierCurve::linearlyInterpolate(const double t) const {
    const auto point0 = getSegment0().evaluate(t);
    const auto point1 = getSegment1().evaluate(t);
    const auto point2 = getSegment2().evaluate(t);

    return QuadraticBezierCurve(point0, point1, point2);
}

std::pair<CubicBezierCurve, CubicBezierCurve>
CubicBezierCurve::splitAt(const double t) const {
    const auto quadraticCurve = linearlyInterpolate(t);
    const auto lineSegment = quadraticCurve.linearlyInterpolate(t);
    const auto midPoint = lineSegment.evaluate(t);

    return std::make_pair(CubicBezierCurve(point0(), quadraticCurve.point0(),
                                           lineSegment.point0, midPoint),
                          CubicBezierCurve(midPoint, lineSegment.point1,
                                           quadraticCurve.point2(), point3()));
}

CubicBezierCurve CubicBezierCurve::trim(const Range range) const {
    const auto x2 = Range(range.x0, 1.0).normalize(range.x1);

    const auto [_1, partiallyTrimmedCurve] = splitAt(range.x0);
    const auto [trimmedCurve, _2] = partiallyTrimmedCurve.splitAt(x2);

    return trimmedCurve;
}

QuadraticBezierCurve CubicBezierCurve::lower() const {
    const Vector4 xVector = getXVector();
    const Vector4 yVector = getYVector();

    const auto loweredPoint0 =
        Vector2(loweringVector0.dot(xVector), loweringVector0.dot(yVector));

    const auto loweredPoint1 =
        Vector2(loweringVector1.dot(xVector), loweringVector1.dot(yVector));

    const auto loweredPoint2 =
        Vector2(loweringVector2.dot(xVector), loweringVector2.dot(yVector));

    return QuadraticBezierCurve(loweredPoint0, loweredPoint1, loweredPoint2);
}

double CubicBezierCurve::calculateTotalArcLengthNaively() const {
    return calculateArcLengthUpToNaively(1.0);
}

double CubicBezierCurve::calculateTotalArcLength() const {
    return calculateArcLengthUpTo(1.0);
}

double CubicBezierCurve::calculateArcLengthUpToNaively(const double t) const {
    static constexpr int segmentCount = 32;
    const auto linSpace = LinSpace(0.0, t, segmentCount);

    auto mutablePreviousPoint = evaluate(0.0);
    auto mutableTotalLength = 0.0;

    for (auto i = 1; i <= segmentCount; ++i) {
        const auto startPoint = mutablePreviousPoint;

        const auto endT = linSpace.getSample(i);
        const auto endPoint = evaluate(endT);

        mutableTotalLength += (endPoint - startPoint).magnitude();

        mutablePreviousPoint = endPoint;
    }

    return mutableTotalLength;
}

double CubicBezierCurve::calculateArcLengthUpTo(const double t) const {
    static constexpr int segmentCount = 9;
    const auto linSpace = LinSpace(0.0, t, segmentCount);

    auto mutablePreviousT = 0.0;
    auto mutableTotalLength = 0.0;

    for (auto i = 1; i <= segmentCount; ++i) {
        const auto startT = mutablePreviousT;
        const auto endT = linSpace.getSample(i);

        const auto trimmedCurve = trim(Range(startT, endT));
        const auto loweredCurve = trimmedCurve.lower();

        mutableTotalLength += loweredCurve.calculateTotalArcLength();

        mutablePreviousT = endT;
    }

    return mutableTotalLength;
}
