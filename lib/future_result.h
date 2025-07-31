#pragma once

#include "task_base.h"
#include <memory>

template <typename T> 
class FutureResult {
public:
  FutureResult(std::shared_ptr<TaskBase> ptr) : ptr_(ptr) {}

  std::shared_ptr<TaskBase> GetVal() { return ptr_; }

private:
  std::shared_ptr<TaskBase> ptr_;
};