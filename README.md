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

The program implements three different string-matching algorithms for searching a pattern in a text: the naive algorithm, string-matching with a finite automaton and the Knuth-Morris-Pratt algorithm.

The program reads as input:
- a text filename;
- a pattern;
- the name of one of the three algorithms (naive, automaton, kmp);
- an output filename.

```sh
$ ./stringmatching text_filename pattern algorithm output_filename
```

It reads the text file and searches for pattern matches in it with the algorithm given as input.
It prints in the output file:
- the running time;
- the total number of times the pattern is found in the text;
- a list of all shifts at which the pattern is found in the text.

**Note**: the automaton algorithm works with the finite alphabet of the first 255 ASCII characters.

The script `stringmatching.sh` is useful for comparing running times of the different algorithms on the same search.

### Example

In the `examples` directory you can find a sample input text file applied to genetics and some output files of different pattern searches in the text.

## License

The code is released under a MIT license. See the file [LICENSE.md](https://github.com/ElisaLegnani/StringMatching/blob/master/LICENSE.md).
