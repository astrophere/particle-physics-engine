#include <gtest/gtest.h>
#include "../include/vector3d.h"

TEST(Vector3D_unit_test, DefaultConstructor) {
    PPE::Vector3D a;

    EXPECT_FLOAT_EQ(a.getX(), 0.0);
    EXPECT_FLOAT_EQ(a.getY(), 0.0);
    EXPECT_FLOAT_EQ(a.getZ(), 0.0);
}

TEST(Vector3D_unit_test, ExplicitConstructor1) {
    PPE::Vector3D a(1, 2.3, -4.5);

    EXPECT_FLOAT_EQ(a.getX(), 1.0);
    EXPECT_FLOAT_EQ(a.getY(), 2.3);
    EXPECT_FLOAT_EQ(a.getZ(), -4.5);
}

TEST(Vector3D_unit_test, ExplicitConstructor2) {
    PPE::Vector3D a;
    PPE::Vector3D b(a);

    EXPECT_FLOAT_EQ(a.getX(), 0.0);
    EXPECT_FLOAT_EQ(a.getY(), 0.0);
    EXPECT_FLOAT_EQ(a.getZ(), 0.0);

    EXPECT_FLOAT_EQ(b.getX(), 0.0);
    EXPECT_FLOAT_EQ(b.getY(), 0.0);
    EXPECT_FLOAT_EQ(b.getZ(), 0.0);

    PPE::Vector3D c(1.0, 2.3, -4.5);
    PPE::Vector3D d(c);

    EXPECT_FLOAT_EQ(c.getX(), 1.0);
    EXPECT_FLOAT_EQ(c.getY(), 2.3);
    EXPECT_FLOAT_EQ(c.getZ(), -4.5);

    EXPECT_FLOAT_EQ(d.getX(), 1.0);
    EXPECT_FLOAT_EQ(d.getY(), 2.3);
    EXPECT_FLOAT_EQ(d.getZ(), -4.5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}