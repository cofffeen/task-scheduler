#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ExceptionTest, Exception) {
  TTaskScheduler scheduler;

  ASSERT_THROW(scheduler.getFutureResult<float>(1), std::out_of_range);
}