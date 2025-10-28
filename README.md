# learnAICoding

A modern C++ project demonstrating best practices with CMake build system.

## Features

- Clean project structure with separate directories for source, headers, and tests
- CMake build configuration
- Example implementation of a simple string utility library
- Ready for GitHub and CI/CD integration

## Project Structure

```
learnAICoding/
├── src/           # Source files (.cpp)
├── include/       # Header files (.h/.hpp)
├── tests/         # Test files
├── build/         # Build output (git-ignored)
├── CMakeLists.txt # CMake configuration
└── README.md      # This file
```

## Building

```bash
cd build
cmake ..
make
```

## Running

```bash
./build/learnAICoding
```

## Requirements

- C++17 or later
- CMake 3.10 or later
- A C++ compiler (GCC, Clang, or MSVC)

## License

MIT License
