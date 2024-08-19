#
# CMakeLists.txt --- a "CMake" file for building LZO
#
# This file is part of the LZO data compression library.
#   http://www.oberhumer.com/opensource/lzo/
#
# Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer
# All Rights Reserved.
#

#
# simple usage example (Unix):
#     mkdir -p build && cd build && cmake .. && make
#
# simple usage example (Windows MSVC):
#     md build
#     cd build
#     cmake .. -G "NMake Makefiles"
#     nmake
#
# another usage example (Unix):
#     mkdir -p build/release-i686
#     cd       build/release-i686
#     cmake ../.. -DENABLE_STATIC=0 -DENABLE_SHARED=1 \
#         -DCMAKE_C_COMPILER=gcc -DCMAKE_C_FLAGS="-m32 -march=i686" \
#         -DCMAKE_INSTALL_PREFIX=/opt/local/prefix-i686
#     make VERBOSE=1
#     make install
#
# see http://www.cmake.org/ for more info
#

# TODO: check if LINKER_LANGUAGE actually works
# TODO: LINKER_LANGUAGE propagate?
#
# TODO: enable Werror? better not, need code cleanup first

file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/.lzo_cmake_config_done.txt")
# we need cmake-3.3 in any case for $<COMPILE_LANGUAGE>
# and we need 3.4.3 for WINDOWS_EXPORT_ALL_SYMBOLS
# => just require 3.5
cmake_minimum_required(VERSION "3.5" FATAL_ERROR)

#***********************************************************************
# options
#***********************************************************************

# configuration options
option(ENABLE_STATIC "Build static LZO library." ON)
option(ENABLE_SHARED "Build shared LZO library." ON) # IMPORTANT: change to OFF in official release

#***********************************************************************
# init
#***********************************************************************

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/upx/misc/cmake/functions.cmake")
    include("${CMAKE_CURRENT_SOURCE_DIR}/vendor/upx/misc/cmake/functions.cmake")
else()
    include("${CMAKE_CURRENT_SOURCE_DIR}/../../misc/cmake/functions.cmake")
endif()

# Disallow in-source build. Note that you will still have to manually
# clean up a few files if you accidentally try an in-source build.
upx_disallow_in_source_build()

# global settings
if(${CMAKE_VERSION} VERSION_GREATER "3.14.99" AND NOT DEFINED CMAKE_MSVC_RUNTIME_LIBRARY)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
    cmake_policy(SET CMP0091 NEW)
endif()
# global CMake settings that default to ON
upx_cache_bool_vars(ON
    CMAKE_C_STANDARD_REQUIRED CMAKE_CXX_STANDARD_REQUIRED
    CMAKE_EXPORT_COMPILE_COMMANDS CMAKE_REQUIRED_QUIET
)
# internal LZO settings; useful for CI jobs
upx_cache_bool_vars(OFF
    LZO_CONFIG_CMAKE_DISABLE_TEST LZO_CONFIG_CMAKE_DISABLE_INSTALL
    LZO_CONFIG_CMAKE_DISABLE_PRINT_INFO LZO_CONFIG_CMAKE_DISABLE_PLATFORM_CHECK
    #LZO_CONFIG_DISABLE_C_STANDARD LZO_CONFIG_DISABLE_CXX_STANDARD
    LZO_CONFIG_DISABLE_SAVE_TEMPS LZO_CONFIG_DISABLE_SHARED_LIBS
    LZO_CONFIG_SET_INSTALL_RPATH
)
upx_print_env_var(CC CXX)

# CMake init
upx_set_default_build_type(Release) # default is CMAKE_BUILD_TYPE=Release
project(lzo VERSION 2.10)
upx_apply_build_type()
upx_set_global_vars()
upx_check_working_build_rpath(LZO_CONFIG_HAVE_WORKING_BUILD_RPATH)

if(DEFINED LZO_CONFIG_CMAKE_EXECUTABLE_SUFFIX)
    set(CMAKE_EXECUTABLE_SUFFIX "${LZO_CONFIG_CMAKE_EXECUTABLE_SUFFIX}")
endif()
if(NOT LZO_CONFIG_CMAKE_DISABLE_INSTALL AND CMAKE_INSTALL_PREFIX)
    include(GNUInstallDirs)
    if(NOT DEFINED CMAKE_INSTALL_PKGCONFIGDIR)
        set(CMAKE_INSTALL_PKGCONFIGDIR "${CMAKE_INSTALL_LIBDIR}/pkgconfig" CACHE PATH "")
    endif()
endif()

if(LZO_CONFIG_DISABLE_SHARED_LIBS) # allow override from CI jobs
   set(ENABLE_SHARED OFF)
endif()
if(NOT ENABLE_STATIC AND NOT ENABLE_SHARED)
    set(ENABLE_STATIC ON)
endif()

#***********************************************************************
# targets
#***********************************************************************

file(GLOB lzo_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")
list(SORT lzo_SOURCES)

# LZO library
set(lzo_COMPILE_TARGETS )
if(ENABLE_STATIC)
    add_library(lzo_static_lib STATIC ${lzo_SOURCES})
    list(APPEND lzo_COMPILE_TARGETS lzo_static_lib)
    set_target_properties(lzo_static_lib PROPERTIES LINKER_LANGUAGE C)
    set_target_properties(lzo_static_lib PROPERTIES OUTPUT_NAME lzo2)
endif()
if(ENABLE_SHARED)
    add_library(lzo_shared_lib SHARED ${lzo_SOURCES})
    list(APPEND lzo_COMPILE_TARGETS lzo_shared_lib)
    set_target_properties(lzo_shared_lib PROPERTIES LINKER_LANGUAGE C)
    set_target_properties(lzo_shared_lib PROPERTIES OUTPUT_NAME lzo2)
    if(ENABLE_STATIC AND (MSVC OR MSVC_FRONTEND OR MSVC_SIMULATE))
        # avoid name clash between static lzo2.lib and DLL import-lib lzo2.lib
        set_target_properties(lzo_shared_lib PROPERTIES ARCHIVE_OUTPUT_NAME lzo2_dllimport)
        set_target_properties(lzo_shared_lib PROPERTIES PDB_NAME lzo2_dllimport)
    endif()
    set_target_properties(lzo_shared_lib PROPERTIES SOVERSION 2 VERSION 2.0.0) # ABI version is 2.0.0 !
    set_target_properties(lzo_shared_lib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# tests & examples
macro(lzo_add_executable t)
    add_executable(${t} ${ARGN})
    if(ENABLE_STATIC)
        target_link_libraries(${t} lzo_static_lib)
    else()
        target_link_libraries(${t} lzo_shared_lib)
        if(LZO_CONFIG_SET_INSTALL_RPATH AND DEFINED CMAKE_INSTALL_FULL_LIBDIR)
            set_target_properties(${t} PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_FULL_LIBDIR}")
        endif()
    endif()
    set_target_properties(${t} PROPERTIES LINKER_LANGUAGE C)
    ####upx_sanitize_target(${t})
endmacro()
# main test driver
lzo_add_executable(lzotest  lzotest/lzotest.c)
# examples
lzo_add_executable(dict     examples/dict.c)
lzo_add_executable(lzopack  examples/lzopack.c)
lzo_add_executable(overlap  examples/overlap.c)
lzo_add_executable(precomp  examples/precomp.c)
lzo_add_executable(precomp2 examples/precomp2.c)
lzo_add_executable(simple   examples/simple.c)
# some boring internal test programs
if(0)
    lzo_add_executable(align    tests/align.c)
    lzo_add_executable(chksum   tests/chksum.c)
    lzo_add_executable(promote  tests/promote.c)
    lzo_add_executable(sizes    tests/sizes.c)
endif()

# miniLZO
add_executable(testmini minilzo/testmini.c minilzo/minilzo.c)
target_include_directories(testmini PRIVATE "include/lzo") # needed for "lzoconf.h"

#***********************************************************************
# compilation flags
# this section currently mostly matches the Autoconf version
#***********************************************************************

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

include(CheckCCompilerFlag)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckLibraryExists)
include(CheckSymbolExists)
include(CheckTypeSize)
include(TestBigEndian)

# this is currently needed because zig Debug defaults to sanitize
# TODO later: fix source code
check_c_compiler_flag("-fno-sanitize=all" NO_SANITIZE_ALL)
#check_c_compiler_flag("-fno-sanitize=alignment" NO_SANITIZE_ALIGNMENT)
if(0)
    set(UPX_CONFIG_SANITIZE_FLAGS_DEBUG -fsanitize=undefined -fsanitize-undefined-trap-on-error -fstack-protector-all)
    if(NO_SANITIZE_ALIGNMENT)
        list(APPEND UPX_CONFIG_SANITIZE_FLAGS_DEBUG -fno-sanitize=alignment)
    elseif(NO_SANITIZE_ALL)
        list(APPEND UPX_CONFIG_SANITIZE_FLAGS_DEBUG -fno-sanitize=all)
    endif()
else()
    if(NO_SANITIZE_ALL)
        add_definitions(-fno-sanitize=all)
    endif()
endif()

if(MSVC OR MSVC_FRONTEND OR WIN32 OR MINGW OR CYGWIN)
    # disable silly warnings about using "deprecated" POSIX functions like fopen()
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_WARNINGS)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_SCL_SECURE_NO_DEPRECATE)
    add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-D__USE_MINGW_ANSI_STDIO)
endif()

# Checks for header files
macro(mfx_check_include_file f var)
    check_include_file("${f}" "mfx_${var}")
    if(NOT ",${mfx_${var}}," STREQUAL ",,")
        add_definitions(-D${var}=1)
        set(mfx_${var} 1)
    else()
        set(mfx_${var} 0)
    endif()
endmacro()
# mfx_ACC_CHECK_HEADERS
set(l assert.h ctype.h dirent.h errno.h fcntl.h float.h limits.h malloc.h memory.h setjmp.h signal.h stdarg.h stddef.h stdint.h stdio.h stdlib.h string.h strings.h time.h unistd.h utime.h sys/mman.h sys/resource.h sys/stat.h sys/time.h sys/types.h sys/wait.h)
foreach(f ${l})
    string(TOUPPER "${f}" var)
    string(REGEX REPLACE "[^0-9A-Z_]" "_" var "${var}")
    mfx_check_include_file("${f}" "HAVE_${var}")
endforeach()

# Checks for typedefs and structures
macro(mfx_check_type_size type var)
    check_type_size("${type}" "mfx_${var}")
    if("${mfx_${var}}" MATCHES "^[1-9][0-9]*$")
        add_definitions(-D${var}=${mfx_${var}})
    else()
        set(mfx_${var} 0)
    endif()
endmacro()
# mfx_ACC_CHECK_SIZEOF + mfx_CHECK_SIZEOF
set(l short int long "long long" __int16 __int32 __int64 "void *" size_t ptrdiff_t intmax_t uintmax_t intptr_t uintptr_t float double "long double" dev_t fpos_t mode_t off_t ssize_t time_t)
foreach(f ${l})
    string(TOUPPER "${f}" var)
    string(REGEX REPLACE " \\*" "_P" var "${var}")
    string(REGEX REPLACE "[^0-9A-Z_]" "_" var "${var}")
    mfx_check_type_size("${f}" "SIZEOF_${var}")
endforeach()

# Checks for library functions
macro(mfx_check_function_exists func var)
    check_function_exists("${func}" "mfx_${var}")
    if(NOT ",${mfx_${var}}," STREQUAL ",,")
        add_definitions(-D${var}=1)
        set(mfx_${var} 1)
    else()
        set(mfx_${var} 0)
    endif()
endmacro()
# mfx_ACC_CHECK_FUNCS
set(l access alloca atexit atoi atol chmod chown clock_getcpuclockid clock_getres clock_gettime ctime difftime fstat getenv getpagesize getrusage gettimeofday gmtime isatty localtime longjmp lstat memcmp memcpy memmove memset mkdir mktime mmap mprotect munmap qsort raise rmdir setjmp signal snprintf strcasecmp strchr strdup strerror strftime stricmp strncasecmp strnicmp strrchr strstr time umask utime vsnprintf)
foreach(f ${l})
    string(TOUPPER "${f}" var)
    string(REGEX REPLACE "[^0-9A-Z_]" "_" var "${var}")
    mfx_check_function_exists("${f}" "HAVE_${var}")
endforeach()

# mfx_LZO_CHECK_ENDIAN
TEST_BIG_ENDIAN(big_endian)
if ("${big_endian}" MATCHES "^1$")
    add_definitions(-DLZO_ABI_BIG_ENDIAN=1)
elseif ("${big_endian}" MATCHES "^0$")
    add_definitions(-DLZO_ABI_LITTLE_ENDIAN=1)
else()
    message(FATAL_ERROR "ERROR: TEST_BIG_ENDIAN failed with result '${big_endian}'.")
endif()

# LZO_HAVE_CONFIG_H
add_definitions(-DLZO_CFG_NO_CONFIG_HEADER=1)

# warnings
foreach(t ${lzo_COMPILE_TARGETS})
    if(MSVC OR MSVC_FRONTEND)
        target_compile_options(${t} PRIVATE -W4)
        target_compile_options(${t} PRIVATE -EHa- -EHs- -GR-)
    else()
        target_compile_options(${t} PRIVATE -Wall -Wextra -Wcast-qual)
        target_compile_options(${t} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -fno-rtti>)
    endif()
    ####upx_sanitize_target(${t})
endforeach()

#***********************************************************************
# test
#***********************************************************************

if(NOT LZO_CONFIG_CMAKE_DISABLE_TEST)
if(NOT CMAKE_CROSSCOMPILING OR CMAKE_CROSSCOMPILING_EMULATOR)

include(CTest)
if(ENABLE_STATIC OR LZO_CONFIG_HAVE_WORKING_BUILD_RPATH)
add_test(NAME simple     COMMAND simple)
add_test(NAME testmini   COMMAND testmini)
add_test(NAME lzotest-01 COMMAND lzotest -mlzo   -n2  -q "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
add_test(NAME lzotest-02 COMMAND lzotest -mavail -n10 -q "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
add_test(NAME lzotest-03 COMMAND lzotest -mall   -n10 -q "${CMAKE_CURRENT_SOURCE_DIR}/include/lzo/lzodefs.h")
endif()

endif() # CMAKE_CROSSCOMPILING
endif() # LZO_CONFIG_CMAKE_DISABLE_TEST

#***********************************************************************
# install
#***********************************************************************

if(NOT LZO_CONFIG_CMAKE_DISABLE_INSTALL)
if(CMAKE_INSTALL_PREFIX AND DEFINED CMAKE_INSTALL_BINDIR AND DEFINED CMAKE_INSTALL_LIBDIR)

set(f AUTHORS COPYING NEWS THANKS doc/LZO.FAQ doc/LZO.TXT doc/LZOAPI.TXT)
install(FILES ${f} DESTINATION "${CMAKE_INSTALL_DOCDIR}")

set(f include/lzo/lzo1.h include/lzo/lzo1a.h include/lzo/lzo1b.h
    include/lzo/lzo1c.h include/lzo/lzo1f.h include/lzo/lzo1x.h
    include/lzo/lzo1y.h include/lzo/lzo1z.h include/lzo/lzo2a.h
    include/lzo/lzo_asm.h include/lzo/lzoconf.h include/lzo/lzodefs.h
    include/lzo/lzoutil.h
)
install(FILES ${f} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lzo")

if(ENABLE_STATIC)
    install(TARGETS lzo_static_lib ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
endif()
if(ENABLE_SHARED)
    install(TARGETS lzo_shared_lib
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    )
endif()

if(NOT DEFINED INSTALL_EXAMPLES AND (ENABLE_STATIC OR LZO_CONFIG_SET_INSTALL_RPATH))
    set(INSTALL_EXAMPLES ON)
endif()
if(INSTALL_EXAMPLES)
    install(TARGETS lzopack lzotest simple testmini DESTINATION "${CMAKE_INSTALL_LIBEXECDIR}/lzo/examples")
endif()

configure_file(lzo2.pc.cmakein lzo2.pc @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/lzo2.pc" DESTINATION "${CMAKE_INSTALL_PKGCONFIGDIR}")

endif() # CMAKE_INSTALL_PREFIX
endif() # LZO_CONFIG_CMAKE_DISABLE_INSTALL

#***********************************************************************
# finish
#***********************************************************************

message(STATUS "LZO_CONFIG_ENABLE_STATIC = ${ENABLE_STATIC}")
message(STATUS "LZO_CONFIG_ENABLE_SHARED = ${ENABLE_SHARED}")
message(STATUS "LZO_CONFIG_HAVE_WORKING_BUILD_RPATH = ${LZO_CONFIG_HAVE_WORKING_BUILD_RPATH}")

# finally print some info about the build-type
if(CMAKE_CONFIGURATION_TYPES)
message(STATUS "CMAKE_CONFIGURATION_TYPES = ${CMAKE_CONFIGURATION_TYPES}")
endif()
if(CMAKE_BUILD_TYPE)
message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
endif()

# extra sanity checks to detect incompatible C vs CXX settings
if(NOT LZO_CONFIG_CMAKE_DISABLE_PLATFORM_CHECK)
    upx_platform_check_c_cxx_mismatch()
endif()

upx_cmake_include_hook(9_finish)
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/.lzo_cmake_config_done.txt" "")

# vim:set ft=cmake ts=4 sw=4 tw=0 et:
