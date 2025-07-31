#pragma once

#include "future_result.h"

template <typename T> class FutureResult;

template <typename T> 
class Argument {
public:
  Argument(T value) : value_(value) {}

  T GetValue() { return value_; }

private:
  T value_;
};

template <typename T> 
class Argument<FutureResult<T>> {
public:
  Argument(FutureResult<T> value) : value_(value) {}

  T GetValue() { return value_.GetVal()->GetResult().template Get<T>(); }

private:
  FutureResult<T> value_;
};
