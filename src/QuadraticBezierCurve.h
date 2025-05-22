#ifndef QUADRATICBEZIERCURVE_H
#define QUADRATICBEZIERCURVE_H
#include "LineSegment.h"
#include "Vector2.h"

class QuadraticBezierCurve {
  public:
    QuadraticBezierCurve(const Vector2 &p0, const Vector2 &p1,
                         const Vector2 &p2)
        : point0_(p0), point1_(p1), point2_(p2) {}

    QuadraticBezierCurve(const QuadraticBezierCurve &) = default;
    QuadraticBezierCurve &operator=(const QuadraticBezierCurve &) = default;

    [[nodiscard]] const Vector2 &point0() const { return point0_; }
    [[nodiscard]] const Vector2 &point1() const { return point1_; }
    [[nodiscard]] const Vector2 &point2() const { return point2_; }

    [[nodiscard]] LineSegment getSegment0() const {
        return LineSegment(point0_, point1_);
    }

    [[nodiscard]] LineSegment getSegment1() const {
        return LineSegment(point1_, point2_);
    }

    [[nodiscard]] Vector2 evaluate(double t) const;

    [[nodiscard]] LineSegment linearlyInterpolate(double t) const;

    [[nodiscard]] double calculateTotalArcLengthNaively() const;

    [[nodiscard]] double calculateTotalArcLength() const;

    [[nodiscard]] double calculateArcLengthUpToNaively(double t) const;

    [[nodiscard]] double calculateArcLengthUpTo(double t) const;

  private:
    Vector2 point0_, point1_, point2_;
};

#endif // QUADRATICBEZIERCURVE_H
