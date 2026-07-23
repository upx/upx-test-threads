#
# SPDX TODO
# Copyright (C) Markus Franz Xaver Johannes Oberhumer
#

# CMake version check; using a somewhat current CMake version is highly recommended
file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/.acx_cmake_config_done.txt")
if(DEFINED UPX_CONFIG_CMAKE_MINIMUM_REQUIRED_VERSION)
    cmake_minimum_required(VERSION "${UPX_CONFIG_CMAKE_MINIMUM_REQUIRED_VERSION}" FATAL_ERROR)
elseif(NOT ${CMAKE_VERSION} VERSION_LESS "3.10")
    cmake_minimum_required(VERSION "3.10" FATAL_ERROR)
else()
    cmake_minimum_required(VERSION "3.5" FATAL_ERROR)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/upx/misc/cmake/functions.cmake")
    include("${CMAKE_CURRENT_SOURCE_DIR}/vendor/upx/misc/cmake/functions.cmake")
else()
    include("${CMAKE_CURRENT_SOURCE_DIR}/../../misc/cmake/functions.cmake")
endif()
upx_print_env_var(CC CXX CPPFLAGS CFLAGS CXXFLAGS)

#***********************************************************************
# options
#***********************************************************************

# none

#***********************************************************************
# init
#***********************************************************************

upx_disallow_in_source_build()

# internal UPX settings; useful for CI jobs
upx_cache_bool_vars(OFF
    UPX_CONFIG_CMAKE_DISABLE_TEST UPX_CONFIG_CMAKE_DISABLE_INSTALL
    #UPX_CONFIG_CMAKE_DISABLE_PRINT_INFO UPX_CONFIG_CMAKE_DISABLE_PLATFORM_CHECK
    #UPX_CONFIG_DISABLE_C_STANDARD UPX_CONFIG_DISABLE_CXX_STANDARD
    UPX_CONFIG_DISABLE_SAVE_TEMPS
    #UPX_CONFIG_DISABLE_SHARED_LIBS
    #UPX_CONFIG_SET_INSTALL_RPATH
)

# CMake init
upx_set_default_build_type(Release) # default is CMAKE_BUILD_TYPE=Release
project(acx VERSION "0.0.1" LANGUAGES C CXX)
upx_apply_build_type()
upx_set_global_vars()
#upx_check_working_build_rpath(UPX_CONFIG_HAVE_WORKING_BUILD_RPATH)

if(DEFINED UPX_CONFIG_CMAKE_EXECUTABLE_SUFFIX)
    set(CMAKE_EXECUTABLE_SUFFIX "${UPX_CONFIG_CMAKE_EXECUTABLE_SUFFIX}")
endif()
if(NOT UPX_CONFIG_CMAKE_DISABLE_INSTALL AND CMAKE_INSTALL_PREFIX)
    include(GNUInstallDirs)
endif()

#***********************************************************************
# common compilation flags
#***********************************************************************

include(CheckCCompilerFlag)

# enable strict warnings and -Werror
if(MSVC OR MSVC_FRONTEND)
    add_definitions(-W4)
    add_definitions(-wd5105 -WX)
elseif(GNU_FRONTEND)
    add_definitions(-Wall -Wextra -Wcast-align -Wcast-qual -Wpointer-arith -Wshadow -Wvla -Wwrite-strings)
    add_definitions(-Werror)
    #add_definitions(-fno-strict-overflow -DNO_STRICT_OVERFLOW)
    check_c_compiler_flag("-save-temps=obj" HAVE_CFLAG_SAVE_TEMPS_OBJ)
    if(NOT UPX_CONFIG_DISABLE_SAVE_TEMPS AND HAVE_CFLAG_SAVE_TEMPS_OBJ)
        add_definitions(-save-temps=obj) # since clang-3.7 & gcc-4.5
    endif()
endif()

#***********************************************************************
# targets
#***********************************************************************

add_executable(naked_c test/naked_c.c)
add_executable(naked_x test/naked_x.cpp)
add_executable(simple_c test/simple_c.c)
add_executable(simple_x test/simple_x.cpp)
upx_sanitize_target(naked_c naked_x)
upx_sanitize_target(simple_c simple_x)

#***********************************************************************
# test
#***********************************************************************

if(NOT UPX_CONFIG_CMAKE_DISABLE_TEST)
if(NOT CMAKE_CROSSCOMPILING OR CMAKE_CROSSCOMPILING_EMULATOR)

include(CTest)
add_test(NAME naked_c COMMAND naked_c)
add_test(NAME naked_x COMMAND naked_x)
add_test(NAME simple_c COMMAND simple_c)
add_test(NAME simple_x COMMAND simple_x)
set_tests_properties(naked_c PROPERTIES COST 2003)
set_tests_properties(naked_x PROPERTIES COST 2002)
set_tests_properties(simple_c PROPERTIES COST 2001)
set_tests_properties(simple_x PROPERTIES COST 2000)

endif() # CMAKE_CROSSCOMPILING
endif() # UPX_CONFIG_CMAKE_DISABLE_TEST

#***********************************************************************
# install
#***********************************************************************

if(NOT UPX_CONFIG_CMAKE_DISABLE_INSTALL)
if(CMAKE_INSTALL_PREFIX AND DEFINED CMAKE_INSTALL_BINDIR AND DEFINED CMAKE_INSTALL_LIBDIR)

install(TARGETS naked_c naked_x simple_c simple_x DESTINATION "${CMAKE_INSTALL_BINDIR}/acx")

endif()
endif() # UPX_CONFIG_CMAKE_DISABLE_INSTALL

#***********************************************************************
# finish
#***********************************************************************

# UPX options
upx_maybe_unused_var(UPX_CONFIG_DISABLE_GITREV)
#upx_maybe_unused_var(UPX_CONFIG_DISABLE_SANITIZE)
upx_maybe_unused_var(UPX_CONFIG_DISABLE_SELF_PACK_TEST)

# pass UPX extra compile options; see CMakeLists.txt
upx_maybe_unused_var(UPX_CONFIG_EXTRA_COMPILE_OPTIONS_BZIP2)
upx_maybe_unused_var(UPX_CONFIG_EXTRA_COMPILE_OPTIONS_UCL)
upx_maybe_unused_var(UPX_CONFIG_EXTRA_COMPILE_OPTIONS_UPX)
upx_maybe_unused_var(UPX_CONFIG_EXTRA_COMPILE_OPTIONS_ZLIB)
upx_maybe_unused_var(UPX_CONFIG_EXTRA_COMPILE_OPTIONS_ZSTD)

# internal options that may get set
upx_maybe_unused_var(UPX_CONFIG_DISABLE_BZIP2 UPX_CONFIG_DISABLE_ZSTD)

# UPX official build settings
upx_maybe_unused_var(TC_EXE TC_NAME)
upx_maybe_unused_var(UPX_CONFIG_OFFICIAL_BUILD UPX_CONFIG_WITH_NRV)

upx_maybe_unused_var(LZO_CONFIG_CMAKE_EXECUTABLE_SUFFIX)
upx_maybe_unused_var(LZO_CONFIG_DISABLE_SHARED_LIBS)
upx_maybe_unused_var(LZO_CONFIG_HAVE_WORKING_BUILD_RPATH)

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/.acx_cmake_config_done.txt" "")

# vim:set ft=cmake ts=4 sw=4 tw=0 et:
