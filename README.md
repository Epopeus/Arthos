# Arthos

A World of Warcraft complete server infrastructure.<br/>
Currently, Arthos is a solo project built on MacOS.

## Build

```
brew install cmake
brew install conan
cmake src
```

###Goals

- fast
- simple
- bug-free (unit tests)
- readable, maintanable, modulable (SOLID)

###Required tools
- [Homebrew](https://brew.sh/) for OSX package management
- [CMake](https://cmake.org/) for building
- [Conan](https://www.conan.io/) for dependency management

###Libs (automatically handled by Conan)
- [Boost](http://www.boost.org/) for many useful libs, like I/O
- [Boost.DI](http://boost-experimental.github.io/di/) for [dependency injection](https://en.wikipedia.org/wiki/Dependency_injection)
- [Google Test](https://github.com/google/googletest) for [unit testing](https://en.wikipedia.org/wiki/Unit_testing) (used with a [TDD](https://en.wikipedia.org/wiki/Test-driven_development) approach)
