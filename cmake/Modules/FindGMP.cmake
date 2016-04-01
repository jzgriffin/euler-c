#.rst:
# FindGMP
# -------
#
# Finds the GMP library
#
# This will define the following variables::
#
#   GMP_FOUND - True if the system has the GMP library
#   GMP_VERSION - The version of the GMP library which was found
#
# and the following imported targets::
#
#   GMP::GMP - The GMP library

#=============================================================================
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
#=============================================================================

# Attempt to find GMP using pkg-config
find_package(PkgConfig)
pkg_check_modules(PC_GMP QUIET GMP)

# Find the headers for GMP
find_path(GMP_INCLUDE_DIR
    NAMES gmp.h
    PATHS ${PC_GMP_INCLUDE_DIRS}
)

# Find the libraries for GMP
find_library(GMP_LIBRARY
    NAMES gmp
    PATHS ${PC_GMP_LIBRARY_DIRS}
)

# Determine the GMP version
set(GMP_VERSION ${PC_GMP_VERSION})
if (NOT ${GMP_VERSION})
    file(STRINGS "${GMP_INCLUDE_DIR}/gmp.h" GMP_VERSION_PARTS
        REGEX "^define[ \t]+__GNU_MP_VERSION(_MINOR|_PATCHLEVEL)?[ \t]+[0-9]+$")
    string(REGEX REPLACE "__GNU_MP_VERSION[ \t]+([0-9]+)" "\\1"
        GMP_VERSION_MAJOR ${GMP_VERSION_PARTS})
    string(REGEX REPLACE "__GNU_MP_VERSION_MINOR[ \t]+([0-9]+)" "\\1"
        GMP_VERSION_MINOR ${GMP_VERSION_PARTS})
    string(REGEX REPLACE "__GNU_MP_VERSION_PATCHLEVEL[ \t]+([0-9]+)" "\\1"
        GMP_VERSION_PATCH ${GMP_VERSION_PARTS})
    set(GMP_VERSION "${GMP_VERSION_MAJOR}.${GMP_VERSION_MINOR}.${GMP_VERSION_PATCH}")
endif()

# Handle the package arguments
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP
    FOUND_VAR GMP_FOUND
    REQUIRED_VARS
        GMP_LIBRARY
        GMP_INCLUDE_DIR
    VERSION_VAR GMP_VERSION
)

# Define public variables
if(GMP_FOUND)
    set(GMP_LIBRARIES ${GMP_LIBRARY})
    set(GMP_INCLUDE_DIRS ${GMP_INCLUDE_DIR})
    set(GMP_DEFINITIONS ${PC_GMP_CFLAGS_OTHER})
endif()

# Define imported targets
if(GMP_FOUND AND NOT TARGET GMP::GMP)
    add_library(GMP::GMP UNKNOWN IMPORTED)
    set_target_properties(GMP::GMP PROPERTIES
        IMPORTED_LOCATION "${GMP_LIBRARY}"
        INTERFACE_COMPILE_OPTIONS "${GMP_DEFINITIONS}"
        INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
    )
endif()

# Mark internal variables as advanced
mark_as_advanced(
    GMP_INCLUDE_DIR
    GMP_LIBRARY
)
