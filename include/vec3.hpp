class Vec3 {
    public:
        float x{0};
        float y{0};
        float z{0};

        Vec3(float X, float Y, float Z);
        Vec3 operator+(const Vec3& other) const;
        Vec3 operator-(const Vec3& other) const;
};

inline Vec3::Vec3(float X, float Y, float Z): x(X), y(Y), z(Z) {};

inline Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

inline Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}