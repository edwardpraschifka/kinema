cmake_minimum_required(VERSION 3.14)
project(its-probably-fine-engine)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/283c17563fe7a1111cd7f581aa5d541e8baeff2f.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

option(ENABLE_ASAN "Build with AddressSanitizer" ON)

enable_testing()

add_executable(tests tests/vec3_test.cpp)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

if (ENABLE_ASAN)
  target_compile_options(tests PUBLIC -fsanitize=address -g)
  target_link_options(tests PUBLIC -fsanitize=address)
endif()