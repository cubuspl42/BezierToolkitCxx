#ifndef VECTOR4_H
#define VECTOR4_H

class Vector4 {
  public:
    Vector4(const double x, const double y, const double z, const double w)
        : x_(x), y_(y), z_(z), w_(w) {}

    Vector4(const Vector4 &) = default;
    Vector4 &operator=(const Vector4 &) = default;

    [[nodiscard]] double x() const { return x_; }
    [[nodiscard]] double y() const { return y_; }
    [[nodiscard]] double z() const { return z_; }
    [[nodiscard]] double w() const { return w_; }

    [[nodiscard]] Vector4 operator+(const Vector4 &other) const;
    [[nodiscard]] Vector4 operator-(const Vector4 &other) const;

    [[nodiscard]] Vector4 operator*(double scalar) const;
    [[nodiscard]] Vector4 operator/(double scalar) const;

    [[nodiscard]] double dot(const Vector4 &other) const;

  private:
    double x_, y_, z_, w_;
};

Vector4 operator*(double scalar, const Vector4 &v);

#endif // VECTOR4_H
