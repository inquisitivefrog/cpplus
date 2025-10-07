#include <gtest/gtest.h>
#include "square.h"

// Define a test fixture
class SquareTest : public ::testing::Test {
protected:
    // Setup before each test
    void SetUp() override {}
    // Teardown after each test
    void TearDown() override {}
};

// Test case
TEST_F(SquareTest, PositiveNumbers) {
    EXPECT_EQ(square(2), 4);
    EXPECT_EQ(square(3), 9);
    EXPECT_EQ(square(0), 0);
}

TEST_F(SquareTest, NegativeNumbers) {
    EXPECT_EQ(square(-2), 4);
    EXPECT_EQ(square(-3), 9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
