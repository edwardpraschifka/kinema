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