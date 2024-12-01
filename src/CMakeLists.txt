cmake_minimum_required(VERSION 3.25)

set(PACKAGE_NAME wcpp)
project(${PACKAGE_NAME} VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  cxxopts
  GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
  GIT_TAG 3bf268481da8208d171d8908e6491459de3651d7 # v3.2.0
)
FetchContent_MakeAvailable(cxxopts)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
add_executable(${PACKAGE_NAME} main.cc)
target_link_libraries(${PACKAGE_NAME} PRIVATE cxxopts)
