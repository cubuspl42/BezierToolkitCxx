#include "Vector3.h"

Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(x() + other.x(), y() + other.y(), z() + other.z());
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(x() - other.x(), y() - other.y(), z() - other.z());
}

Vector3 Vector3::operator*(const double scalar) const {
    return Vector3(x() * scalar, y() * scalar, z() * scalar);
}

Vector3 Vector3::operator/(const double scalar) const {
    return Vector3(x() / scalar, y() / scalar, z() / scalar);
}

double Vector3::dot(const Vector3 &other) const {
    return x() * other.x() + y() * other.y() + z() * other.z();
}

Vector3 Vector3::cross(const Vector3 &other) const {
    return Vector3(y() * other.z() - z() * other.y(),
                   z() * other.x() - x() * other.z(),
                   x() * other.y() - y() * other.x());
}

Vector3 operator*(const double scalar, const Vector3 &v) {
    return Vector3(v.x() * scalar, v.y() * scalar, v.z() * scalar);
}
