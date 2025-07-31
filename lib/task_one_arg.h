#pragma once

#include "task_base.h"

template <typename Func, typename T> 
class TaskOneArg : public TaskBase {
public:
  TaskOneArg(size_t id, Func func, T arg)
      : TaskBase(id), func_(func), arg_(arg) {}

  void Invoke() override {
    if (!result_.HasValue()) {
      result_ = func_(arg_.GetValue());
    }
  }

private:
  Func func_;
  Argument<T> arg_;
};