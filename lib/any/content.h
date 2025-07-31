#pragma once

#include "content_base.h"

template <typename T> 
class Content : public ContentBase {
public:
  Content(const T &content) : content_(content) {}

  ContentBase *clone() override { return new Content<T>(content_); }

  T GetContent(){
    return content_;
  }

private:
  T content_;
};
