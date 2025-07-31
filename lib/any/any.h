#pragma once

#include "content.h"

class Any {
public:
  Any() = default;

  ~Any() { delete ptr_; }

  Any(const Any &other) : ptr_(other.ptr_->clone()) {}

  template <typename T> 
  Any &operator=(const T &other) {
    delete ptr_;
    ptr_ = new Content<T>(other);
    return *this;
  }

  template <typename T> 
  T Get() {
    return static_cast<Content<T> *>(ptr_)->GetContent();
  }

  bool HasValue() { return ptr_ != nullptr; }

private:
  ContentBase *ptr_ = nullptr;
};
