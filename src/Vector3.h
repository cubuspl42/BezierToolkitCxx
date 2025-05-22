#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 {
  public:
    Vector3(const double x, const double y, const double z)
        : x_(x), y_(y), z_(z) {}

    Vector3(const Vector3 &) = default;
    Vector3 &operator=(const Vector3 &) = default;

    [[nodiscard]] double x() const { return x_; }
    [[nodiscard]] double y() const { return y_; }
    [[nodiscard]] double z() const { return z_; }

    [[nodiscard]] Vector3 operator+(const Vector3 &other) const;
    [[nodiscard]] Vector3 operator-(const Vector3 &other) const;

    [[nodiscard]] Vector3 operator*(double scalar) const;
    [[nodiscard]] Vector3 operator/(double scalar) const;

    [[nodiscard]] double dot(const Vector3 &other) const;
    [[nodiscard]] Vector3 cross(const Vector3 &other) const;

  private:
    double x_, y_, z_;
};

Vector3 operator*(double scalar, const Vector3 &v);

#endif // VECTOR3_H
