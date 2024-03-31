cmake_minimum_required(VERSION 3.5)

project(matrix)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/mtlc
)


set(MATRIX_SOURCE_TESTS
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/user_class.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/user_class.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/constructors.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/element_access.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/comparator.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/modifiers.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/arithmetics.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/functions.cc
)

SET(MATRIX_COVERAGE_LIBS "" CACHE STRING "")
SET(MATRIX_COVERAGE_FLAGS "" CACHE STRING "")
SET(MATRIX_WARNING_FLAGS "-Wall -Werror -Wextra" CACHE STRING "")
SET(MATRIX_STANDART_FLAGS "-std=c++17" CACHE STRING "")
SET(MATRIX_CXX_COMILER "/bin/g++" CACHE STRING "")

SET(MATRIX_FLAGS "${MATRIX_COVERAGE_FLAGS} ${MATRIX_WARNING_FLAGS} ${MATRIX_STANDART_FLAGS}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MATRIX_FLAGS}")
# SET(CMAKE_CXX_COMPILER "${MATRIX_CXX_COMPILER}")

add_executable(matrix_tests ${MATRIX_SOURCE_TESTS})

target_link_libraries(
  matrix_tests
  gtest
  ${MATRIX_COVERAGE_LIBS}
)
