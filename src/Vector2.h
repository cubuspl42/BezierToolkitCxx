#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 {
  public:
    Vector2(const double x, const double y) : x_(x), y_(y) {}

    Vector2(const Vector2 &) = default;
    Vector2 &operator=(const Vector2 &) = default;

    [[nodiscard]] double x() const { return x_; }
    [[nodiscard]] double y() const { return y_; }

    [[nodiscard]] Vector2 operator+(const Vector2 &other) const;
    [[nodiscard]] Vector2 operator-(const Vector2 &other) const;

    [[nodiscard]] Vector2 operator*(double scalar) const;
    [[nodiscard]] Vector2 operator/(double scalar) const;

    [[nodiscard]] double dot(const Vector2 &other) const;
    [[nodiscard]] double cross(const Vector2 &other) const;

    [[nodiscard]] double magnitudeSquared() const;
    [[nodiscard]] double magnitude() const;

  private:
    double x_, y_;
};

Vector2 operator*(double scalar, const Vector2 &v);

#endif // VECTOR2_H
