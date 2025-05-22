cmake_minimum_required(VERSION 3.31)

# Set the project name and version
project(HelloWorld VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
        src/CubicBezierCurve.cpp
        src/LineSegment.cpp
        src/LinSpace.cpp
        src/math.cpp
        src/QuadraticBezierCurve.cpp
        src/Range.cpp
        src/Vector2.cpp
        src/Vector3.cpp
        src/Vector4.cpp
)

set(HEADERS
        src/CubicBezierCurve.h
        src/LineSegment.h
        src/LinSpace.h
        src/math.h
        src/QuadraticBezierCurve.h
        src/Range.h
        src/Vector2.h
        src/Vector3.h
        src/Vector4.h
)

enable_testing()

add_test(NAME MyTests COMMAND MyTests)


# Find the benchmark package
find_package(benchmark CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

add_executable(benchmark_main src/benchmark_main.cpp ${SOURCES} ${HEADERS})
add_executable(test_main src/test_main.cpp ${SOURCES} ${HEADERS})

target_link_libraries(benchmark_main PRIVATE benchmark::benchmark benchmark::benchmark_main)
target_link_libraries(test_main PRIVATE GTest::gtest GTest::gtest_main)
