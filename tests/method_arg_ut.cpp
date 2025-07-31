#include <scheduler.h>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

struct AddNumber {
    float add(float a) const {
        return a + number;
    }

    float number = 3;
};

TEST(MethodArgTest, OneTypeWithVar) {
    AddNumber add;

    TTaskScheduler scheduler;

    auto id1 = scheduler.add(&AddNumber::add, add, 0); 

    scheduler.executeAll();

    ASSERT_THAT(scheduler.getResult<float>(id1), 3);
}