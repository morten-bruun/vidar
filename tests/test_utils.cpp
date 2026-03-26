#include <gtest/gtest.h>

#include <vidar/utils.hpp>
#include <string>

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

TEST(VidarInClosedIntervalTest, TestClosedInterval) {
    namespace vu = vidar::utils;

    EXPECT_TRUE(vu::in_interval(5, 1, 10));
    EXPECT_TRUE(vu::in_interval(1, 1, 10));
    EXPECT_TRUE(vu::in_interval(10, 1, 10));
    EXPECT_FALSE(vu::in_interval(0, 1, 10));
    EXPECT_FALSE(vu::in_interval(11, 1, 10));

    const std::string lower = "aaa";
    const std::string upper = "zzz";
    EXPECT_TRUE(vu::in_interval(std::string("abc"), lower, upper));
    EXPECT_TRUE(vu::in_interval(std::string("aaa"), lower, upper));
    EXPECT_TRUE(vu::in_interval(std::string("zzz"), lower, upper));
    EXPECT_FALSE(vu::in_interval(std::string("aaa"), std::string("bbb"), std::string("ccc")));
}

TEST(VidarInHalfOpenIntervalTest, TestHalfOpenInterval) {
    namespace vu = vidar::utils;

    EXPECT_TRUE(vu::in_interval_open(5, 1, 10));
    EXPECT_TRUE(vu::in_interval_open(1, 1, 10));
    EXPECT_FALSE(vu::in_interval_open(10, 1, 10));
    EXPECT_FALSE(vu::in_interval_open(0, 1, 10));
    EXPECT_FALSE(vu::in_interval_open(11, 1, 10));
}
