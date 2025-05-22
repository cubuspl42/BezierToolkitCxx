#ifndef CUBICBEZIERCURVE_H
#define CUBICBEZIERCURVE_H
#include "LineSegment.h"
#include "QuadraticBezierCurve.h"
#include "Range.h"
#include "Vector2.h"
#include "Vector4.h"

#include <utility>

class CubicBezierCurve {
  public:
    CubicBezierCurve(const Vector2 &p0, const Vector2 &p1, const Vector2 &p2,
                     const Vector2 &p3)
        : point0_(p0), point1_(p1), point2_(p2), point3_(p3) {}

    CubicBezierCurve(const CubicBezierCurve &) = default;
    CubicBezierCurve &operator=(const CubicBezierCurve &) = default;

    [[nodiscard]] const Vector2 &point0() const { return point0_; }
    [[nodiscard]] const Vector2 &point1() const { return point1_; }
    [[nodiscard]] const Vector2 &point2() const { return point2_; }
    [[nodiscard]] const Vector2 &point3() const { return point3_; }

    [[nodiscard]] Vector4 getXVector() const {
        return Vector4(point0_.x(), point1_.x(), point2_.x(), point3_.x());
    }

    [[nodiscard]] Vector4 getYVector() const {
        return Vector4(point0_.y(), point1_.y(), point2_.y(), point3_.y());
    }

    [[nodiscard]] LineSegment getSegment0() const {
        return LineSegment(point0_, point1_);
    }

    [[nodiscard]] LineSegment getSegment1() const {
        return LineSegment(point1_, point2_);
    }

    [[nodiscard]] LineSegment getSegment2() const {
        return LineSegment(point2_, point3_);
    }

    [[nodiscard]] Vector2 evaluate(double t) const;

    [[nodiscard]] QuadraticBezierCurve linearlyInterpolate(double t) const;

    [[nodiscard]] std::pair<CubicBezierCurve, CubicBezierCurve>
    splitAt(double t) const;

    [[nodiscard]] CubicBezierCurve trim(Range range) const;

    [[nodiscard]] QuadraticBezierCurve lower() const;

    [[nodiscard]] double calculateTotalArcLengthNaively() const;

    [[nodiscard]] double calculateTotalArcLength() const;

    [[nodiscard]] double calculateArcLengthUpToNaively(double t) const;

    [[nodiscard]] double calculateArcLengthUpTo(double t) const;

  private:
    Vector2 point0_, point1_, point2_, point3_;
};

#endif // CUBICBEZIERCURVE_H
