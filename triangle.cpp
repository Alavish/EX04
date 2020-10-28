#include <gtest/gtest.h>

#include <iostream>
using namespace std;
// Enum type
enum type {Equilateral, Isosceles, Scalene, Right, Obtuse, notTriangle};

/// Checks if triangle is a triangle at all
bool isTriangle(int a, int b, int c) {
    return (!((a <= 0 || b <= 0 || c <= 0) || ( a + b <= c || c + b <= a || c + a <= b)));
}

//If it is a triangle goes through these conditons 
int triangleType(int a, int b, int c) {
    if (!isTriangle(a, b, c)) {
        return notTriangle;
    }
    if (a == b && b == c) {
        return Equilateral;
    }
    if (a == b || b == c || a == c) {
        return Isosceles;
    }
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
        return Right;
    }
    return Scalene;
}


// Not traignle function
TEST(isValid, notTriangle) {
    EXPECT_FALSE(isTriangle(30, 4, 1));
    EXPECT_FALSE(isTriangle(0, 0, 1));
    EXPECT_FALSE(isTriangle(-3, 4, 1));
    EXPECT_FALSE(isTriangle(0, 0, 0));
    EXPECT_FALSE(isTriangle(3, 4, 0));
   

    
}

// Real triangle tests
TEST(isValid, validTriangle) {
    EXPECT_TRUE(isTriangle(5, 4, 5));
    EXPECT_TRUE(isTriangle(3, 4, 5));
    EXPECT_TRUE(isTriangle(5, 5, 5));
}

// Equilateral tests
TEST(type, equilateralTriangle) {
    EXPECT_EQ(triangleType(9, 9, 9), Equilateral) << "Equilateral";
}
// Right Triangle tests
TEST(type, RightTriangle) {
    EXPECT_EQ(triangleType(3, 5, 4), Right) << "Right";
    EXPECT_EQ(triangleType(3, 4, 5), Right) << "Right";
    EXPECT_EQ(triangleType(5, 4, 3), Right) << "Right";
}

// Isosceles Triangle tests
TEST(type, IsoscelesTriangle) {
    EXPECT_EQ(triangleType(4, 5, 5), Isosceles) << "Isosceles";
    EXPECT_EQ(triangleType(2, 3, 3), Isosceles) << "Isosceles";
}

// main
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
