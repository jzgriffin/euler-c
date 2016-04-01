# Project Euler in C
# Copyright (c) Jeremiah Griffin 2016
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

# Target CMake 3.2 at the oldest
cmake_minimum_required(VERSION 3.2)

# Configure the project
project(Euler LANGUAGES C)

# Find packages
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")
find_package(GMP REQUIRED)

# Determine the platform
if(WIN32)
    set(PLATFORM win32)
elseif(APPLE)
    set(PLATFORM macx)
else()
    set(PLATFORM posix)
endif()

# Build the list of solutions
if("${SOLUTIONS}" STREQUAL "")
    set(SOLUTIONS
        001
        002
        003
        004
        005
        006
        007
        008
        009
        010
        011
        012
        013
        014
        015
        016
        017
        018
        019
        020
        021
        022
        067
        CACHE STRING "Solutions to build"
        FORCE
    )
endif()
set(SOLUTION_SOURCES)
set(SOLUTIONS_FILE_IN Euler/solutions.c.in)
set(SOLUTIONS_FILE ${PROJECT_BINARY_DIR}/solutions.c)
list(LENGTH SOLUTIONS SOLUTION_COUNT)
configure_file(
    ${SOLUTIONS_FILE_IN}
    ${SOLUTIONS_FILE}
)
foreach(NUMBER ${SOLUTIONS})
    list(APPEND SOLUTION_SOURCES Euler/solution${NUMBER}.c)
    file(APPEND ${SOLUTIONS_FILE}
        "extern eu_solution_t eu_solution${NUMBER};\n")
endforeach()
file(APPEND ${SOLUTIONS_FILE}
    "const eu_solution_t *const eu_solutions[] = {\n")
foreach(NUMBER ${SOLUTIONS})
    file(APPEND ${SOLUTIONS_FILE}
        "    &eu_solution${NUMBER},\n")
endforeach()
file(APPEND ${SOLUTIONS_FILE}
    "};\n")

# Add the executable and its dependencies
add_executable(Euler
    Euler/main.c
    Euler/solution.h
    Euler/timer.h
    Euler/timer.${PLATFORM}.c
    ${SOLUTIONS_FILE}
    ${SOLUTION_SOURCES}
)
target_include_directories(Euler
    PRIVATE ${PROJECT_SOURCE_DIR}/euler
)
target_link_libraries(Euler
    PRIVATE GMP::GMP
)
