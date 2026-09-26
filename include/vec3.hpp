#include <cmath>

class Vec3 {
    public:
        float x{0};
        float y{0};
        float z{0};

        Vec3();
        Vec3(float X, float Y, float Z);

        Vec3 operator+(const Vec3& other) const;
        Vec3 operator-(const Vec3& other) const;
        bool operator==(const Vec3& other) const;
        bool operator!=(const Vec3& other) const;
        Vec3 operator*(const float k) const;
        friend Vec3 operator*(const float k, const Vec3& v);
        Vec3 operator-() const;
        float operator[](const std::size_t i) const;
        float& operator[](const std::size_t i);
        
        float dot(const Vec3& other) const;
        Vec3 cross(const Vec3& other) const;
        float length() const;
        float length_sq() const;
        Vec3 normalize() const;
};

inline Vec3::Vec3(float X, float Y, float Z): x(X), y(Y), z(Z) {};

inline Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

inline Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

inline bool Vec3::operator==(const Vec3& other) const {
    return (x == other.x && y == other.y && z == other.z);
}

inline bool Vec3::operator!=(const Vec3& other) const {
    return (x != other.x || y != other.y || z != other.z);
}

inline Vec3 Vec3::operator*(const float k) const {
    return Vec3(k * x, k * y, k * z);
}

inline Vec3 operator*(const float k, const Vec3& v) {
    return Vec3(k * v.x, k * v.y, k * v.z);
}

inline Vec3 Vec3::operator-() const {
    return Vec3(-1 * x, -1 * y, -1 * z);
}

inline float Vec3::operator[](const std::size_t i) const {
    if (i > 2) throw std::invalid_argument("Index cannot exceed 2");
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
}

inline float& Vec3::operator[](const std::size_t i) {
    if (i > 2) throw std::invalid_argument("Index cannot exceed 2");
    if (i == 0) return x;
    if (i == 1) return y;
    return z;
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
    if (len == 0) {throw std::runtime_error("Divide by zero");}
    return Vec3(x/len, y/len, z/len);
}