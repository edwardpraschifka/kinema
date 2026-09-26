#include <cmath>
#include <gtest/gtest.h>
#include "../include/vec3.hpp"

TEST(Vec3, TestConstructor) {

  Vec3 point{1,2,3};

  EXPECT_EQ(point.x, 1);
  EXPECT_EQ(point.y, 2);
  EXPECT_EQ(point.z, 3);
}

TEST(Vec3, TestAddition) {

  Vec3 u{1,2,3};
  Vec3 v{4,5,6};
  Vec3 sum = u + v;

  EXPECT_EQ(sum.x, 5);
  EXPECT_EQ(sum.y, 7);
  EXPECT_EQ(sum.z, 9);
}

TEST(Vec3, TestSubtraction) {

  Vec3 u{1,2,3};
  Vec3 v{4,5,6};
  Vec3 diff = u - v;

  EXPECT_EQ(diff.x, -3);
  EXPECT_EQ(diff.y, -3);
  EXPECT_EQ(diff.z, -3);
}

TEST(Vec3, TestMultiply) {

  Vec3 u{1,2,3};
  float k{3.5};
  Vec3 res = u.multiply(k);

  EXPECT_FLOAT_EQ(res.x, 3.5);
  EXPECT_FLOAT_EQ(res.y, 7);
  EXPECT_FLOAT_EQ(res.z, 10.5);
}

TEST(Vec3, TestDot) {

  Vec3 u{1,2,3};
  Vec3 v{4,5,6};

  EXPECT_FLOAT_EQ(u.dot(v), 32);
}

TEST(Vec3, TestCross) {

  Vec3 u{1,2,3};
  Vec3 v{4,5,6};
  Vec3 res = u.cross(v);

  EXPECT_EQ(res.x, -3);
  EXPECT_EQ(res.y, 6);
  EXPECT_EQ(res.z, -3);
}

TEST(Vec3, TestLength) {
  Vec3 u{1,2,3};
  EXPECT_FLOAT_EQ(u.length(), std::sqrt(14));
}

TEST(Vec3, TestLengthSq) {
  Vec3 u{1,2,3};
  EXPECT_FLOAT_EQ(u.length_sq(), 14);
}

TEST(Vec3, TestNormalize) {
  Vec3 u{1,2,3};
  Vec3 normalized{u.normalize()};

  EXPECT_FLOAT_EQ(normalized.x, 1/std::sqrt(14));
  EXPECT_FLOAT_EQ(normalized.y, 2/std::sqrt(14));
  EXPECT_FLOAT_EQ(normalized.z, 3/std::sqrt(14));
}

TEST(Vec3, TestNormalizeZeroVector) {
  Vec3 u{0,0,0};
  EXPECT_THROW(u.normalize(), std::runtime_error);
}

TEST(Vec3, TestNegate) {
  Vec3 u{1,2,3};
  Vec3 negated{u.negate()};

  EXPECT_FLOAT_EQ(negated.x, -1);
  EXPECT_FLOAT_EQ(negated.y, -2);
  EXPECT_FLOAT_EQ(negated.z, -3);
}