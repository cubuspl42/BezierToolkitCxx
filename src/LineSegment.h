#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "Vector2.h"

class LineSegment {
  public:
    const Vector2 point0;
    const Vector2 point1;

    LineSegment(const Vector2 &p0, const Vector2 &p1)
        : point0(p0), point1(p1) {}

    [[nodiscard]] Vector2 evaluate(double t) const;
};

#endif // LINESEGMENT_H
