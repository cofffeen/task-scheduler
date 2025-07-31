#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

TEST(ZeroArgTest, ZeroArg) {
  TTaskScheduler scheduler;

  auto id1 = scheduler.add([]() { return 0; });

  scheduler.executeAll();

  ASSERT_THAT(scheduler.getResult<int>(id1), 0);
}

TEST(ZeroArgTest, ZeroArgContainer) {
  TTaskScheduler scheduler;

  auto id1 = scheduler.add([]() {
    std::vector<int> v(5);
    for (int i = 0; i < v.size(); ++i) {
      v[i] = i;
    }
    return v;
  });

  scheduler.executeAll();

  ASSERT_THAT(scheduler.getResult<std::vector<int>>(id1),
              ::testing::ElementsAre(0, 1, 2, 3, 4));
}