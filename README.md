# Conan Example

This repository contains a C++ game built with [SFML](https://www.sfml-dev.org/) and [Box2D](https://box2d.org/).
The dependencies are managed by [Conan](https://conan.io/) and the project uses `CMake` as build tool.
It has some predefined configurations for the JetBrains **CLion** IDE and can be used as a skeleton for new projects.

The [PreLoad.cmake](PreLoad.cmake) contains CMake commands to automatize the Conan dependencies installation.

# Getting the project up and running

To run this project you need to have `CMake` and `conan` installed. You can install conan with `pip`:

```shell
pip install conan
```

## With CLion IDE

All you need to do is to clone the repository

```shell
git clone git@github.com:Pacheco95/conan-project-example.git
```

and open it in CLion and let it sync the CMake project.

```shell
clion conan-project-example
```

It will generate directories like `cmake-build-*` based on the preconfigured build profiles.
It will also autogenerate the Debug/Run profiles for you. Just hit the `Run` button and things will happen.

## Without IDE

```shell
git clone git@github.com:Pacheco95/conan-project-example.git
cd conan-project-example
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
make # build app and tests at the bin directory
```

# Running tests in docker

```shell
cd conan-project-example
docker build -t bouncing_ball .
docker run --rm bouncing_ball:latest
```

# Notes

- The `cmake_minimum_required` was set to `(VERSION 3.0)` but fell free to adjust it to your needs.
- Improvement Pull Requests are welcomed.
- This project was inspired on this awesome
  video: [Developing C/C++ Projects with CLion IDE and Conan C/C++ Package Manager](https://www.youtube.com/watch?v=qpOul18bXes)
  (old but gold)
