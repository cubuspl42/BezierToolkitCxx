#include "Vector4.h"

Vector4 Vector4::operator+(const Vector4 &other) const {
    return {x() + other.x(), y() + other.y(), z() + other.z(), w() + other.w()};
}

Vector4 Vector4::operator-(const Vector4 &other) const {
    return {x() - other.x(), y() - other.y(), z() - other.z(), w() - other.w()};
}

Vector4 Vector4::operator*(const double scalar) const {
    return {x() * scalar, y() * scalar, z() * scalar, w() * scalar};
}

Vector4 Vector4::operator/(const double scalar) const {
    return {x() / scalar, y() / scalar, z() / scalar, w() / scalar};
}

double Vector4::dot(const Vector4 &other) const {
    return x() * other.x() + y() * other.y() + z() * other.z() +
           w() * other.w();
}

Vector4 operator*(const double scalar, const Vector4 &v) {
    return {v.x() * scalar, v.y() * scalar, v.z() * scalar, v.w() * scalar};
}
