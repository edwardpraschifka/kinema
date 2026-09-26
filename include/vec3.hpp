#include <cmath>

class Vec3 {
    public:
        float x{0};
        float y{0};
        float z{0};

        Vec3(float X, float Y, float Z);

        Vec3 operator+(const Vec3& other) const;
        Vec3 operator-(const Vec3& other) const;

        Vec3 multiply(const float k) const;
        float dot(const Vec3& other) const;
        Vec3 cross(const Vec3& other) const;
        float length() const;
        float length_sq() const;
        Vec3 normalize() const;
        Vec3 negate() const;
};

inline Vec3::Vec3(float X, float Y, float Z): x(X), y(Y), z(Z) {};

inline Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

inline Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

inline Vec3 Vec3::multiply(const float k) const {
    return Vec3(k * x, k * y, k * z);
}

inline float Vec3::dot(const Vec3& other) const {
    return (x*other.x) + (y*other.y) + (z*other.z);
}

inline Vec3 Vec3::cross(const Vec3& other) const {
    return Vec3(y*other.z - z*other.y,
                z*other.x - x*other.z,
                x*other.y - y*other.x);
}

inline float Vec3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

inline float Vec3::length_sq() const {
    return x*x + y*y + z*z;
}

inline Vec3 Vec3::normalize() const {
    float len = length();
    return Vec3(x/len, y/len, z/len);
}

inline Vec3 Vec3::negate() const {
    return Vec3(-1 * x, -1 * y, -1 * z);
}