//
// Copyright (C) 2018 macrozhang. All rights reserved.
// Date：2018-08-02
//

#include "testshell.h"


#include <vector>

namespace util {

namespace test {

namespace {
struct Test {
  const char* base_;
  const char* name_;
  void (*func_)();
  
  Test(const char* base, const char* name, void (*func)()) 
    : base_(base), name_(name), func_(func) { }
};
std::vector<Test>* tests;

}

bool RegisterTest(const char* base, const char* name, void (*func)()) {
  if (tests == nullptr) {
    tests = new std::vector<Test>;
  }

  Test t(base, name, func);
  tests->push_back(t);
  return true;
}

int RunAllTests() {
  int passed = 0;

  if (tests != nullptr) {
    for (size_t i = 0; i < tests->size(); i++) {
      const Test& t = (*tests)[i];
      fprintf(stderr, "==== Test %s.%s\n", t.base_, t.name_);
      (*t.func_)();
      passed++;
    }
  }

  fprintf(stderr, "==== PASSED %d tests\n", passed);
  return 0;
}


} // namespace test

} // namespace util
