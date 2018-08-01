//
// Copyright (C) 2018 macrozhang. All rights reserved.
// Date：2018-08-01
//

#ifndef UTIL_TESTSHELL_H_
#define UTIL_TESTSHELL_H_

namespace util {

namespace test {

#define CONCAT(a, b) _CONCAT(a, b)
#define _CONCAT(a, b) a##b

#define TEST(base, name)                                                    \
class CONCAT(_Test_, name) : public base {                                  \
 public:                                                                    \
  void _Run();                                                              \
  static void _RunIt() {                                                    \
    CONCAT(_Test_, name) t;                                                 \
    t._Run();                                                               \
  }                                                                         \
};                                                                          \
bool CONCAT(_Test_ignored_, name) =                                         \
  ::util::test::RegisterTest(#base, #name, &CONCAT(_Test_, name)::_RunIt);  \
void CONCAT(_Test_, name)::_Run()


bool RegisterTest(const char* base, const char* name, void (*func)());

} // namespace test

} // namespace util

#endif // UTIL_TESTSHELL_H_

