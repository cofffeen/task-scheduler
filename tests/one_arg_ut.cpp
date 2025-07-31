#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(OneArgTest, OneArg) {
  TTaskScheduler scheduler;

  auto id1 = scheduler.add([](int a) { return a * a; }, 2);
  auto id2 = scheduler.add([](int a) { return a * 3; },
                           scheduler.getFutureResult<int>(id1));

  scheduler.executeAll();

  ASSERT_THAT(scheduler.getResult<int>(id2), 12);
}