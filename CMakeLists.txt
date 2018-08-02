

cmake_minimum_required(VERSION 3.7)
project(util VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(UTIL_BUILD_TESTS "Build util's unit tests" ON)

add_library(util "")

target_sources(util
  PRIVATE
    "${PROJECT_SOURCE_DIR}/slice.h"
    "${PROJECT_SOURCE_DIR}/status.h"
    "${PROJECT_SOURCE_DIR}/status.cc"
    "${PROJECT_SOURCE_DIR}/testshell.h"
    "${PROJECT_SOURCE_DIR}/testshell.cc"
)

if (UTIL_BUILD_TESTS)
  enable_testing()

  function(util_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    
    add_executable("${test_target_name}" "")
    
    target_sources("${test_target_name}"
      PRIVATE
        # "${PROJECT_SOURCE_DIR}/util/testshell.cc"
        # "${PROJECT_SOURCE_DIR}/util/testshell.h"

        "${test_file}"
    )

    target_link_libraries("${test_target_name}" util)

    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
  endfunction(util_test)

  util_test("${PROJECT_SOURCE_DIR}/status_test.cc")

  # set(BUILD_GTEST ON)
  # set(BUILD_GMOCK OFF)
  # set(BUILD_SHARED_LIBS OFF)
  # mark_as_advanced(BUILD_GTEST)
  # add_subdirectory(thirdparty/googletest)

endif (UTIL_BUILD_TESTS)

