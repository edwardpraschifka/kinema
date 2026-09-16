#include <gtest/gtest.h>
#include "../include/vec3.hpp"

TEST(Vec3, TestConstructor) {

  Vec3 point{1,2,3};

  EXPECT_EQ(point.x, 1);
  EXPECT_EQ(point.y, 2);
  EXPECT_EQ(point.z, 3);
}