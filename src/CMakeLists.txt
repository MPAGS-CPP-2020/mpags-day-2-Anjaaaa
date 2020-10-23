# - Set CMake requirements when declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. This can also be done by removing the 'set' 
#   command and running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set the C++ standard directly
# set(CMAKE_CXX_STANDARD 14)
# This gives the output:
# [ 50%] Building CXX object CMakeFiles/mpags-cipher.dir/mpags-cipher.cpp.o
# /usr/bin/c++    -Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic \
# -std=gnu++14 -o CMakeFiles/mpags-cipher.dir/mpags-cipher.cpp.o \
# -c /workspaces/test-setup/mpags-day-2-Anjaaaa/src/mpags-cipher.cpp

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/TransformChar.hpp
)

target_include_directories(mpags-cipher
    PRIVATE ../src/MPAGSCipher
)

# - Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")


set(CMAKE_CXX_EXTENSIONS OFF)
target_compile_features(
    mpags-cipher PRIVATE cxx_auto_type
    # the two flags cxx_range_for cxx_uniform_initialization
    # are not needed for me to see the output lines
    # [ 50%] Building CXX object CMakeFiles/mpags-cipher.dir/mpags-cipher.cpp.o
    # /usr/bin/c++    -std=gnu++11 -o CMakeFiles/mpags-cipher.dir/mpags-cipher.cpp.o \
    # -c /workspaces/test-setup/mpags-day-2-Anjaaaa/src/mpags-cipher.cpp
)