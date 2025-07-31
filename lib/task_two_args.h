#pragma once

#include "task_base.h"

template <typename Func, typename T, typename U>
class TaskTwoArgs : public TaskBase {
public:
  TaskTwoArgs(size_t id, const Func& func, T arg1, U arg2)
      : TaskBase(id), func_(func), arg1_(arg1), arg2_(arg2) {}

  void Invoke() override {
    if (!result_.HasValue()) {
      result_ = func_(arg1_.GetValue(), arg2_.GetValue());
    }
  }

private:
  Func func_;
  Argument<T> arg1_;
  Argument<U> arg2_;
};
