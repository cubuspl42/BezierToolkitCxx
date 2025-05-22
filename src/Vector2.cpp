#include "Vector2.h"

#include <cmath>

Vector2 Vector2::operator+(const Vector2 &other) const {
    return {x() + other.x(), y() + other.y()};
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return {x() - other.x(), y() - other.y()};
}

Vector2 Vector2::operator*(const double scalar) const {
    return {x() * scalar, y() * scalar};
}

Vector2 Vector2::operator/(const double scalar) const {
    return {x() / scalar, y() / scalar};
}

double Vector2::dot(const Vector2 &other) const {
    return x() * other.x() + y() * other.y();
}

double Vector2::cross(const Vector2 &other) const {
    return x() * other.y() - y() * other.x();
}

double Vector2::magnitudeSquared() const { return x() * x() + y() * y(); }

double Vector2::magnitude() const { return std::sqrt(magnitudeSquared()); }

Vector2 operator*(const double scalar, const Vector2 &v) {
    return {v.x() * scalar, v.y() * scalar};
}
