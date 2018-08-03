//
// Copyright (C) 2018 macrozhang. All rights reserved.
// Date：2018-08-01
//

#ifndef UTIL_TESTSHELL_H_
#define UTIL_TESTSHELL_H_

#include <sstream>

namespace util {

namespace test {

class Tester {
 private:
  bool        ok_;
  const char* file_;
  int         line_;
  std::stringstream ss_;

 public:
  Tester(const char* file, int line)
    : ok_(true), file_(file), line_(line) { }

  ~Tester() {
    if (!ok_) {
      fprintf(stderr, "%s:%d:%s\n", file_, line_, ss_.str().c_str());
      exit(1);
    }
  }

  Tester& Is(bool c, const char* msg) {
    if (!c) {
      ss_ << " Assertion failure " << msg;
      ok_ = false;
    }
    return *this;
  }

#define BINARY_COMPARE(name, op)                      \
  template<typename X, typename Y>                    \
  Tester& name(const X& x, const Y& y) {              \
    if (!(x op y)) {                                  \
      ss_ << " failed: " << x << (" " #op " ") << y;  \
      ok_ = false;                                    \
    }                                                 \
    return *this;                                     \
  }

  BINARY_COMPARE(IsEq, ==)
  BINARY_COMPARE(IsNe, !=)
  BINARY_COMPARE(IsGe, >=)
  BINARY_COMPARE(IsGt, >)
  BINARY_COMPARE(IsLe, <=)
  BINARY_COMPARE(IsLt, <)
#undef BINARY_COMPARE

};
#define _TESTER ::util::test::Tester(__FILE__, __LINE__)
#define ASSERT_TRUE(c)  _TESTER.Is((c), #c)
#define ASSERT_EQ(x, y) _TESTER.IsEq((x), (y))
#define ASSERT_NE(x, y) _TESTER.IsNe((x), (y))
#define ASSERT_GE(x, y) _TESTER.IsGe((x), (y))
#define ASSERT_GT(x, y) _TESTER.IsGt((x), (y))
#define ASSERT_LE(x, y) _TESTER.IsLe((x), (y))
#define ASSERT_LT(x, y) _TESTER.IsLt((x), (y))

#define _TCONCAT(a, b) a##b
#define TCONCAT(a, b) _TCONCAT(a, b)

#define TEST(base, name)                                                     \
class TCONCAT(_Test_, name) : public base {                                  \
 public:                                                                     \
  void _Run();                                                               \
  static void _RunIt() {                                                     \
    TCONCAT(_Test_, name) t;                                                 \
    t._Run();                                                                \
  }                                                                          \
};                                                                           \
bool TCONCAT(_Test_ignored_, name) =                                         \
  ::util::test::RegisterTest(#base, #name, &TCONCAT(_Test_, name)::_RunIt);  \
void TCONCAT(_Test_, name)::_Run()


bool RegisterTest(const char* base, const char* name, void (*func)());

int RunAllTests();

} // namespace test

} // namespace util

#endif // UTIL_TESTSHELL_H_

