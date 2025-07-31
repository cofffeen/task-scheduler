#pragma once

#include "task_base.h"

template <typename Func> 
class TaskZeroArg : public TaskBase {
public:
  TaskZeroArg(size_t id, Func func) : TaskBase(id), func_(func) {}

  void Invoke() override {
    if (!result_.HasValue()) {
      result_ = func_();
    }
  }

private:
  Func func_;
};
