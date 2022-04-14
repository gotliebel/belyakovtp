//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

TEST(LeapTestCase, IsLeap) {
  ASSERT_THROW(IsLeap(-10), std::invalid_argument);
  EXPECT_EQ(0, IsLeap(2021));
  EXPECT_EQ(1, IsLeap(2020));
  EXPECT_EQ(0, IsLeap(2021));
  EXPECT_EQ(0, IsLeap(1700));
  EXPECT_EQ(1, IsLeap(2000));
}

TEST(LeapTestCase, GetMonthsDays) {
  ASSERT_THROW(GetMonthDays(2000, 0), std::invalid_argument);
  ASSERT_THROW(GetMonthDays(2000, 15), std::invalid_argument);
  EXPECT_EQ(29, GetMonthDays(2020, 2));
  EXPECT_EQ(28, GetMonthDays(2021, 2));
  EXPECT_EQ(30, GetMonthDays(100, 4));
  EXPECT_EQ(31, GetMonthDays(100, 5));
  EXPECT_EQ(30, GetMonthDays(100, 6));
  EXPECT_EQ(31, GetMonthDays(5, 1));
  EXPECT_EQ(30, GetMonthDays(5, 9));
  EXPECT_EQ(30, GetMonthDays(5, 11));
  EXPECT_EQ(31, GetMonthDays(5, 3));
  EXPECT_EQ(31, GetMonthDays(5, 7));
  EXPECT_EQ(31, GetMonthDays(5, 8));
  EXPECT_EQ(31, GetMonthDays(5, 10));
  EXPECT_EQ(31, GetMonthDays(5, 12));
}


