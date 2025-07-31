#pragma once

#include "future_result.h"
#include "task_class_method.h"
#include "task_one_arg.h"
#include "task_two_args.h"
#include "task_zero_arg.h"
#include <vector>

class TTaskScheduler {
public:
  TTaskScheduler() = default;

  template <typename Func> 
  size_t add(Func func) {
    std::shared_ptr<TaskBase> task =
        std::make_shared<TaskZeroArg<Func>>(tasks_.size(), func);
    tasks_.push_back(task);

    return task->GetId();
  }

  template <typename Func, typename T> 
  size_t add(Func func, T value) {
    std::shared_ptr<TaskBase> task =
        std::make_shared<TaskOneArg<Func, T>>(tasks_.size(), func, value);
    tasks_.push_back(task);

    return task->GetId();
  }

  template <typename Func, typename T, typename U>
  size_t add(Func func, T value1, U value2) {
    std::shared_ptr<TaskBase> task = std::make_shared<TaskTwoArgs<Func, T, U>>(
        tasks_.size(), func, value1, value2);
    tasks_.push_back(task);

    return task->GetId();
  }

  template <typename Func, typename Obj, typename T, typename U>
  size_t add(Func (Obj::*method)(T) const, const Obj &obj, const U &value) {
    std::shared_ptr<TaskBase> task =
        std::make_shared<TaskClassMethod<Func, Obj, T, U>>(tasks_.size(),
                                                           method, obj, value);
    tasks_.push_back(task);

    return task->GetId();
  }

  template <typename T> 
  FutureResult<T> getFutureResult(size_t id) {
    if (id >= tasks_.size()) {
      throw std::out_of_range("there no task with this id");
    }

    return FutureResult<T>(tasks_[id]);
  }

  void executeAll() {
    for (std::shared_ptr<TaskBase> task : tasks_) {
      task->Invoke();
    }
  }

  template <typename T> 
  T getResult(size_t id) {
    return tasks_[id]->GetResult().Get<T>();
  }

private:
  std::vector<std::shared_ptr<TaskBase>> tasks_;
};
