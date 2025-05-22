#include "QuadraticBezierCurve.h"

#include "LinSpace.h"
#include "math.h"

Vector2 QuadraticBezierCurve::evaluate(const double t) const {
    const double u = 1.0 - t;

    return point0() * (u * u) + point1() * (2 * u * t) + point2() * (t * t);
}

LineSegment QuadraticBezierCurve::linearlyInterpolate(const double t) const {
    const auto point0 = getSegment0().evaluate(t);
    const auto point1 = getSegment1().evaluate(t);

    return {point0, point1};
}

double QuadraticBezierCurve::calculateTotalArcLengthNaively() const {
    return calculateArcLengthUpToNaively(1.0);
}

double QuadraticBezierCurve::calculateTotalArcLength() const {
    const auto b = point1() - point0();
    const auto f = point2() - point1();
    const auto a = f - b;

    const auto aMSq = a.magnitudeSquared(); // |A|^2
    const auto aM = std::sqrt(aMSq);        // |A|
    const auto aMCb = aMSq * aM;            // |A|^3

    const auto bM = b.magnitude();
    const auto fM = f.magnitude();

    const auto ab = a.dot(b);
    const auto af = a.dot(f);

    const auto expr1 = (fM * af - bM * ab) / aMSq;
    const auto expr2 = sq(f.cross(b)) / aMCb;
    const auto expr3 = std::log((aM * fM + af) / (aM * bM + ab));

    return expr1 + expr2 * expr3;
}

double
QuadraticBezierCurve::calculateArcLengthUpToNaively(const double t) const {
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

double QuadraticBezierCurve::calculateArcLengthUpTo(const double t) const {
    const auto b = point1() - point0();
    const auto f = point2() - point1();
    const auto a = f - b;

    const auto aMSq = a.magnitudeSquared(); // |A|^2
    const auto aM = std::sqrt(aMSq);        // |A|

    const auto d = a.dot(b) / aMSq;
    const auto k = b.magnitudeSquared() / aMSq - sq(d);

    const auto u = t + d;

    const auto sqrtUk = std::sqrt(sq(t) + k);
    const auto sqrtDk = std::sqrt(sq(d) + k);

    const auto expr1 = k * std::log((u + sqrtUk) / (d + sqrtDk));
    const auto expr2 = u * sqrtUk - d * sqrtDk;

    return aM * (expr1 + expr2);
}
