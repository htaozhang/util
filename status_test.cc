//
// Copyright (C) 2018 macrozhang. All rights reserved.
// Date：2018-08-02
//

#include "status.h"
#include "testshell.h"

#include <utility>

namespace util {

TEST(Status, MoveConstructor) {
  {
    Status ok = Status::OK();
    ASSERT_TRUE(ok.ok());
  }
}

}

int main(int argc, char** argv) {
  return util::test::RunAllTests();
}

