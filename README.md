# BezierToolkitCxx

## Building & running on macOS

```shell
vcpkg install benchmark
vcpkg install gtest
cmake -Bbuild -H. -DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=arm64-osx -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/test_main
./build/benchmark_main
```

## Code style

- Prefer immutable data structures
- Use `const` on passed-by-value arguments
