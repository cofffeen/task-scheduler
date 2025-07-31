#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(DifferentTypesTest, DifferentTypes) {
  TTaskScheduler scheduler;

  auto id1 =
      scheduler.add([](std::string a, char b) { return a + b; }, "aaa", 'b');

  scheduler.executeAll();

  ASSERT_THAT(scheduler.getResult<std::string>(id1), "aaab");
}