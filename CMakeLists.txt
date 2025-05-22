cmake_minimum_required(VERSION 3.31)

# Set the project name and version
project(HelloWorld VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all source files
set(SOURCES
    src/CubicBezierCurve.cpp
    src/LineSegment.cpp
    src/LinSpace.cpp
    src/main.cpp
    src/math.cpp
    src/QuadraticBezierCurve.cpp
    src/Range.cpp
    src/Vector2.cpp
    src/Vector3.cpp
    src/Vector4.cpp
)

# Collect all header files (optional, for IDEs)
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

# Find the benchmark package
find_package(benchmark CONFIG REQUIRED)

# Add the executable
add_executable(bezier_toolkit_benchmark ${SOURCES} ${HEADERS})

# Link the benchmark library
target_link_libraries(bezier_toolkit_benchmark PRIVATE benchmark::benchmark benchmark::benchmark_main)
