#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(OneTypeTest, OneTypeWithVar) {
    float a = 1;
    float b = 2;

    TTaskScheduler scheduler;

    auto id1 = scheduler.add([](float a, float b) {return  a + b;}, a, b);

    scheduler.executeAll();

    ASSERT_THAT(scheduler.getResult<float>(id1), 3);
}

TEST(OneTypeTest, OneTypeNoVar) {
    TTaskScheduler scheduler;

    auto id1 = scheduler.add([](float a, float b) {return a + b;}, 1, 2);

    scheduler.executeAll();

    ASSERT_THAT(scheduler.getResult<float>(id1), 3);
}