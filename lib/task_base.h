#pragma once

#include "argument.h"
#include "any/any.h"
#include <cstddef>

class TaskBase {
public:
  TaskBase() = default;

  TaskBase(size_t id) : id_(id) {}

  size_t GetId() { return id_; }

  Any GetResult() {
    Invoke();
    return result_;
  }

  virtual void Invoke() = 0;

protected:
  size_t id_;
  Any result_;
};
