

cmake_minimum_required(VERSION 3.9)
project(util VERSION 1.0 LANGUAGES C CXX)

# set(CMAKE_C_STANDARD 11)

# set(CMAKE_CXX_STANDARD C++11)

option(UTIL_BUILD_TESTS "Build util's unit tests" ON)

if (UTIL_BUILD_TESTS)
  enable_testing()

  set(BUILD_GTEST ON)
  set(BUILD_GMOCK OFF)
  set(BUILD_SHARED_LIBS OFF)
  
  mark_as_advanced(BUILD_GTEST)

  add_subdirectory(thirdparty/googletest)

endif (UTIL_BUILD_TESTS)

