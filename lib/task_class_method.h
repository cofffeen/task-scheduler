#pragma once

#include "task_base.h"

template <typename Func, typename Obj, typename T, typename U>
class TaskClassMethod : public TaskBase {
public:
  using Method = Func (Obj::*)(T) const;

  TaskClassMethod(size_t id, Method method, const Obj &obj, const U &arg)
      : TaskBase(id), method_(method), obj_(obj), arg_(arg) {}

  void Invoke() override {
    if (!result_.HasValue()) {
      result_ = (obj_.*method_)(arg_.GetValue());
    }
  }

private:
  Method method_;
  Obj obj_;
  Argument<U> arg_;
};
