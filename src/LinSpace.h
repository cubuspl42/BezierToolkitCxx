#ifndef LINSPACE_H
#define LINSPACE_H
#include "Range.h"

#include <iterator>

class LinSpace {
  public:
    const double x0;
    const double x1;
    const int segmentCount;

    LinSpace(const double x0, const double x1, const int segmentCount)
        : x0(x0), x1(x1), segmentCount(segmentCount) {}

    [[nodiscard]] double getSample(const int i) const {
        return x0 + (x1 - x0) * i / segmentCount;
    }
};

#endif // LINSPACE_H
