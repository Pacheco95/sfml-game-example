# Conan Example

This repository contains a
CMake/C++ [PhysX](https://gameworksdocs.nvidia.com/PhysX/4.1/documentation/physxguide/Index.html) "Hello World" code
base using the [Conan](https://conan.io/) package manager.
It has some predefined configurations for the JetBrains **CLion** IDE and can be used as a skeleton for new projects.

The [PreLoad.cmake](PreLoad.cmake) contains CMake commands to automatize the Conan dependencies installation.

# Getting the project up and running

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

# Notes

- The `cmake_minimum_required` was set to `(VERSION 3.0)` but fell free to adjust it to your needs.
- Improvement Pull Requests are welcomed.
- This project was inspired on this awesome
  video: [Developing C/C++ Projects with CLion IDE and Conan C/C++ Package Manager](https://www.youtube.com/watch?v=qpOul18bXes) (
  old but gold)
