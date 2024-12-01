# WCPP

WCPP is a C++ version of the original `wc` tool, providing functionality to count lines, words, and characters in a given text file.

## Features

- Count lines, words, and characters in a text file
- Options to select the type of count (lines, words, chars)

## Requirements

- CMake 3.25 or higher
- A C++20 compatible compiler (e.g., g++, clang++)

## Dependencies

- [cxxopts](https://github.com/jarro2783/cxxopts) library (used for parsing command line arguments)

## Building the Project

1. Clone the repository:

   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```

1. Build the project

   1. Script Method

      Use the provided `tool.sh` script to build the project:

      - For a release build:

        ```bash
        ./tool.sh -b
        ```

      - For a debug build:

        ```bash
        ./tool.sh -d
        ```

   1. Manual Method

      In the project root:

      ```bash
      cmake -S src -B build
      cmake --build build [--clean-first]
      ```

1. [Optional] Install the executable

   1. **Manual Installation:**

   After building the project, copy the `wcpp` executable to a directory in your `$PATH`:

   ```bash
   cp ./build/wcpp /usr/local/bin/
   ```

   Ensure `/usr/local/bin` is part of your `$PATH`, or choose another directory that is.

   2. **Automated Installation:**

   Use CMake's install feature to install the executable:

   ```bash
   cmake --install build --prefix /usr/local
   ```

   This will automatically place the executable in the appropriate directory under `/usr/local`.

## Usage

Run the program with the desired options:

```bash
./build/wcpp -[l|w|c] <filepath>
```

- `-l` option to count lines
- `-w` option to count words
- `-c` option to count characters

For help and usage information, run:

```bash
./build/wcpp [-h]
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
