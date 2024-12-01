#!/usr/bin/env bash
set -euo pipefail

function cmake_build() {
    cmake -S src -B build -DCMAKE_BUILD_TYPE="${BUILD_TYPE:-Release}"
    cmake --build build
}

function show_usage() {
    echo "Usage: $0 [-b | -d | -r <filepath>]"
    echo "    -b  Release build"
    echo "    -d  Debug build"
    echo "    -r  Build the project and run it with a given path"
}

if [[ $# -eq 0 ]]; then
    show_usage
    exit 1
fi

while getopts ":bdr:h" opt; do
    case $opt in
    b)
        BUILD_TYPE=Release
        BUILD=1
        ;;
    d)
        BUILD_TYPE=Debug
        BUILD=1
        ;;
    r)
        RUN=1
        ;;
    h)
        show_usage
        exit 0
        ;;
    :)
        echo "Option -$OPTARG requires an argument." >&2
        exit 1
        ;;
    \?)
        echo "Invalid option: -$OPTARG" >&2
        exit 1
        ;;
    esac
done
shift "$((OPTIND - 1))"

if [[ "${BUILD:-0}" -eq 1 && "${RUN:-0}" -eq 1 ]]; then
    echo "Error: Options -b, -d and -r are mutually exclusive" >&2
    exit 1
fi

if [[ "${BUILD:-0}" -eq 1 ]]; then cmake_build; fi
if [[ "${RUN:-0}" -eq 1 ]]; then
    if [[ ! -f "./build/wcpp" ]]; then cmake_build; fi
    ./build/wcpp "${1:-./test.txt}"
fi
