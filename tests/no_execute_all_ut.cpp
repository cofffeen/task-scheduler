#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(NoExecuteAllTest, NoExecuteAll) {
  TTaskScheduler scheduler;

  bool id1_done = false;
  bool id2_done = false;
  bool id3_done = false;

  auto id1 = scheduler.add(
      [&id1_done](int a) {
        id1_done = true;
        return a;
      },
      0);

  auto id2 = scheduler.add(
      [&id2_done](int a) {
        id2_done = true;
        return a;
      },
      0);

  auto id3 = scheduler.add(
      [&id3_done](int a) {
        id3_done = true;
        return a;
      },
      scheduler.getFutureResult<int>(id1));

  scheduler.getResult<int>(id3);

  ASSERT_TRUE(id1_done);
  ASSERT_FALSE(id2_done);
  ASSERT_TRUE(id3_done);
}