#ifndef RANGE_H
#define RANGE_H

class Range {
  public:
    const double x0;
    const double x1;

    Range(const double x0, const double x1) : x0(x0), x1(x1) {}

    [[nodiscard]] double normalize(const double x) const {
        return (x - x0) / (x1 - x0);
    }
};

#endif // RANGE_H
