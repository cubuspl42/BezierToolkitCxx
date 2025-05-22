#include "LineSegment.h"

Vector2 LineSegment::evaluate(const double t) const {
    // Linear interpolation: (1-t) * P0 + t * P1
    return point0 * (1.0 - t) + point1 * t;
}
