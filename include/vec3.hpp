class Vec3 {
    public:
        float x{0};
        float y{0};
        float z{0};

        Vec3(float X, float Y, float Z);
};

inline Vec3::Vec3(float X, float Y, float Z): x(X), y(Y), z(Z) {};