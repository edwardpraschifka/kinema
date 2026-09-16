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