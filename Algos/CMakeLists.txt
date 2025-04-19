cmake_minimum_required(VERSION 3.12)
project(MyTestProject)

# Set C++ standard (recommended)
set(CMAKE_CXX_STANDARD 17)

# Tell CMake where to find GTest/GMock (since you installed it in C:/googletest)
set(GTEST_ROOT "C:/googletest")
set(GMOCK_ROOT "C:/googletest")

# Find GTest and GMock packages
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

# Your executable (e.g., for unit tests)
add_executable(runTests
    test/main_test.cpp
    # Add other test files...
)

# Link GTest & GMock to your executable
target_link_libraries(runTests
    GTest::GTest
    GMock::GMock
    # Add other dependencies...
)