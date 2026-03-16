#include <gtest/gtest.h>

#include <vidar/utils.hpp>

TEST(VidarUpdateTest, UpdatesAndReturnsTrueWhenValueChanges) {
    namespace vu = vidar::utils;
    int value = 10;

    const bool changed = vu::update(value, 42);

    EXPECT_TRUE(changed);
    EXPECT_EQ(value, 42);

    const bool changedAgain = vu::update(value, 42);
    EXPECT_FALSE(changedAgain);
    EXPECT_EQ(value, 42);
}
