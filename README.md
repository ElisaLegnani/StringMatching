# String-matching algorithms

A simple program implementing different string-matching algorithms written in C++. It is developed for the course *Data structures and algorithms for physics of data* (University of Milan, AY2020-2021).

## Installation

### Dependencies

You need to install:
- C++ Compiler (C++17 or higher);
- [Cmake](https://cmake.org/) (version 3.12 or higher).

### Download and build

Clone this repository in your directory with the commands: 
```sh
$ git clone https://github.com/ElisaLegnani/StringMatching.git
$ cd StringMatching
```

Compile:

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
```

Executables files can be found in the `build` directory.

For testing, run in the `build` directory:

```sh
$ ctest
```

## Usage

```sh
$ ./stringmatching textfile pattern algorithm
```

### Examples

Coming soon!

## License

The code is released under a MIT license. See the file [LICENSE.md](https://github.com/ElisaLegnani/StringMatching/blob/master/LICENSE.md).