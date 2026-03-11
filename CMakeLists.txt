cmake_minimum_required(VERSION 3.28)

project(vidar VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)

add_library(vidar
    src/utils.cpp
)

target_include_directories(vidar
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(vidar
    PUBLIC
        cxx_std_20
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(vidar PRIVATE
        -Wall
        -Wextra
        -Wshadow
        -Wnon-virtual-dtor
        -pedantic
    )
endif()

enable_testing()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(vidar_tests
    tests/test_utils.cpp
)

target_link_libraries(vidar_tests
    PRIVATE
        vidar
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(vidar_tests)
