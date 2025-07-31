#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FutureResultTest, FutureResult) {
  TTaskScheduler scheduler;

  auto id1 = scheduler.add([](float a, float b) { return a + b; }, 1, 2);
  auto id2 = scheduler.add([](float a, float b) { return a + b; }, 3,
                           scheduler.getFutureResult<float>(id1));

  scheduler.executeAll();

  ASSERT_THAT(scheduler.getResult<float>(id2), 6);
}