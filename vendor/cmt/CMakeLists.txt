#
# SPDX TODO
# Copyright (C) Markus Franz Xaver Johannes Oberhumer
#

# CMake version check; using a somewhat current CMake version is highly recommended
file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/.cmt_cmake_config_done.txt")
if(DEFINED UPX_CONFIG_CMAKE_MINIMUM_REQUIRED_VERSION)
    cmake_minimum_required(VERSION "${UPX_CONFIG_CMAKE_MINIMUM_REQUIRED_VERSION}" FATAL_ERROR)
elseif(NOT ${CMAKE_VERSION} VERSION_LESS "3.10")
    cmake_minimum_required(VERSION "3.10" FATAL_ERROR)
else()
    cmake_minimum_required(VERSION "3.5" FATAL_ERROR)
endif()

#***********************************************************************
# options
#***********************************************************************

option(CMT_CONFIG_ENABLE_STATIC "Build static library." ON)
option(CMT_CONFIG_ENABLE_SHARED "Build shared library." ON) # IMPORTANT: change to OFF in official release

#***********************************************************************
# init
#***********************************************************************

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/upx/misc/cmake/functions.cmake")
    include("${CMAKE_CURRENT_SOURCE_DIR}/vendor/upx/misc/cmake/functions.cmake")
else()
    include("${CMAKE_CURRENT_SOURCE_DIR}/../../misc/cmake/functions.cmake")
endif()

upx_disallow_in_source_build()

# internal UPX settings; useful for CI jobs
upx_cache_bool_vars(OFF
    UPX_CONFIG_CMAKE_DISABLE_TEST UPX_CONFIG_CMAKE_DISABLE_INSTALL
    #UPX_CONFIG_CMAKE_DISABLE_PRINT_INFO UPX_CONFIG_CMAKE_DISABLE_PLATFORM_CHECK
    #UPX_CONFIG_DISABLE_C_STANDARD UPX_CONFIG_DISABLE_CXX_STANDARD
    UPX_CONFIG_DISABLE_SHARED_LIBS
    UPX_CONFIG_SET_INSTALL_RPATH
)
upx_print_env_var(CC CXX)

# CMake init
upx_set_default_build_type(Release) # default is CMAKE_BUILD_TYPE=Release
project(cmt VERSION "0.0.1" LANGUAGES C CXX)
upx_apply_build_type()
upx_set_global_vars()
upx_check_working_build_rpath(UPX_CONFIG_HAVE_WORKING_BUILD_RPATH)

if(DEFINED UPX_CONFIG_CMAKE_EXECUTABLE_SUFFIX)
    set(CMAKE_EXECUTABLE_SUFFIX "${UPX_CONFIG_CMAKE_EXECUTABLE_SUFFIX}")
endif()
if(NOT UPX_CONFIG_CMAKE_DISABLE_INSTALL AND CMAKE_INSTALL_PREFIX)
    include(GNUInstallDirs)
endif()

set(ENABLE_STATIC "${CMT_CONFIG_ENABLE_STATIC}")
set(ENABLE_SHARED "${CMT_CONFIG_ENABLE_SHARED}")
if(UPX_CONFIG_DISABLE_SHARED_LIBS) # allow override from CI jobs
   set(ENABLE_SHARED OFF)
endif()
if(NOT ENABLE_STATIC AND NOT ENABLE_SHARED)
    set(ENABLE_STATIC ON)
endif()

#***********************************************************************
# common compilation flags
#***********************************************************************

#include(CheckCCompilerFlag)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# enable strict warnings and -Werror
if(MSVC OR MSVC_FRONTEND)
    add_definitions(-W4)
    add_definitions(-wd5105 -WX)
elseif(GNU_FRONTEND)
    add_definitions(-Wall -Wextra -Wcast-align -Wcast-qual -Wmissing-declarations -Wpointer-arith -Wshadow -Wvla -Wwrite-strings)
    add_definitions(-Werror)
    #add_definitions(-fno-strict-overflow -DNO_STRICT_OVERFLOW)
endif()

#***********************************************************************
# library targets
#***********************************************************************

file(GLOB cmt_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*")
list(SORT cmt_SOURCES)

set(cmt_COMPILE_TARGETS )
if(ENABLE_STATIC)
    add_library(cmt_static_lib STATIC ${cmt_SOURCES})
    list(APPEND cmt_COMPILE_TARGETS cmt_static_lib)
    set_target_properties(cmt_static_lib PROPERTIES LINKER_LANGUAGE C)
    set_target_properties(cmt_static_lib PROPERTIES OUTPUT_NAME cmt999)
endif()
if(ENABLE_SHARED)
    add_library(cmt_shared_lib SHARED ${cmt_SOURCES})
    list(APPEND cmt_COMPILE_TARGETS cmt_shared_lib)
    set_target_properties(cmt_shared_lib PROPERTIES LINKER_LANGUAGE C)
    set_target_properties(cmt_shared_lib PROPERTIES OUTPUT_NAME cmt999)
    if(ENABLE_STATIC AND (MSVC OR MSVC_FRONTEND OR MSVC_SIMULATE))
        # avoid name clash between static cmt.lib and DLL import-lib cmt.lib
        set_target_properties(cmt_shared_lib PROPERTIES ARCHIVE_OUTPUT_NAME cmt999_dllimport)
        set_target_properties(cmt_shared_lib PROPERTIES PDB_NAME cmt999_dllimport)
    endif()
    set_target_properties(cmt_shared_lib PROPERTIES SOVERSION 9 VERSION 9.0.0) # ABI version is 9.0.0 !
    set_target_properties(cmt_shared_lib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

#***********************************************************************
# examples targets
#***********************************************************************

if(ENABLE_STATIC)
    add_executable(cmt_test_1_static cmt_test_1.c)
    add_executable(cmt_test_2_static examples/cmt_test_2.c)
    foreach(t IN ITEMS cmt_test_1_static cmt_test_2_static)
        target_link_libraries(${t} cmt_static_lib)
        set_target_properties(${t} PROPERTIES LINKER_LANGUAGE C)
        upx_sanitize_target(${t})
    endforeach()
endif()

if(ENABLE_SHARED)
    add_executable(cmt_test_1_shared cmt_test_1.c)
    add_executable(cmt_test_2_shared examples/cmt_test_2.c)
    foreach(t IN ITEMS cmt_test_1_shared cmt_test_2_shared)
        target_link_libraries(${t} cmt_shared_lib)
        set_target_properties(${t} PROPERTIES LINKER_LANGUAGE C)
        if(UPX_CONFIG_SET_INSTALL_RPATH AND DEFINED CMAKE_INSTALL_FULL_LIBDIR)
            set_target_properties(${t} PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_FULL_LIBDIR}")
        endif()
        upx_sanitize_target(${t})
    endforeach()
endif()

#***********************************************************************
# target compilation flags
#***********************************************************************

foreach(t ${cmt_COMPILE_TARGETS})
    if(MSVC OR MSVC_FRONTEND)
        target_compile_options(${t} PRIVATE -EHa- -EHs- -GR-)
    else()
        target_compile_options(${t} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -fno-rtti>)
    endif()
    upx_sanitize_target(${t})
    add_custom_command(TARGET ${t} POST_BUILD COMMAND "${CMAKE_COMMAND}" -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/XTesting/$<CONFIG>")
endforeach()

#***********************************************************************
# test
#***********************************************************************

if(NOT UPX_CONFIG_CMAKE_DISABLE_TEST)
if(NOT CMAKE_CROSSCOMPILING OR CMAKE_CROSSCOMPILING_EMULATOR)

include(CTest)

# make sure that the tests work when run from an arbitrary WORKING_DIRECTORY
set(wd "${CMAKE_CURRENT_BINARY_DIR}/XTesting/$<CONFIG>")

if(ENABLE_STATIC)
    foreach(t IN ITEMS cmt_test_1_static cmt_test_2_static)
        add_test(NAME ${t} WORKING_DIRECTORY "${wd}" COMMAND ${t})
    endforeach()
endif()
if(ENABLE_SHARED AND UPX_CONFIG_HAVE_WORKING_BUILD_RPATH)
    foreach(t IN ITEMS cmt_test_1_shared cmt_test_2_shared)
        add_test(NAME ${t} WORKING_DIRECTORY "${wd}" COMMAND ${t})
    endforeach()
endif()

endif() # CMAKE_CROSSCOMPILING
endif() # UPX_CONFIG_CMAKE_DISABLE_TEST

#***********************************************************************
# install
#***********************************************************************

if(NOT UPX_CONFIG_CMAKE_DISABLE_INSTALL)
if(CMAKE_INSTALL_PREFIX AND DEFINED CMAKE_INSTALL_BINDIR AND DEFINED CMAKE_INSTALL_LIBDIR)

install(FILES include/cmt/cmt.h include/cmt/cmt_no_exceptions.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/cmt")

if(ENABLE_STATIC)
    install(TARGETS cmt_static_lib ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
    install(TARGETS cmt_test_1_static DESTINATION "${CMAKE_INSTALL_BINDIR}")
    install(TARGETS cmt_test_2_static DESTINATION "${CMAKE_INSTALL_LIBEXECDIR}/cmt/examples")
endif()
if(ENABLE_SHARED)
    install(TARGETS cmt_shared_lib
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    )
    install(TARGETS cmt_test_1_shared DESTINATION "${CMAKE_INSTALL_BINDIR}")
    install(TARGETS cmt_test_2_shared DESTINATION "${CMAKE_INSTALL_LIBEXECDIR}/cmt/examples")
endif()

endif() # CMAKE_INSTALL_PREFIX
endif() # UPX_CONFIG_CMAKE_DISABLE_INSTALL

#***********************************************************************
# finish
#***********************************************************************

message(STATUS "CMT_CONFIG_ENABLE_STATIC = ${ENABLE_STATIC}")
message(STATUS "CMT_CONFIG_ENABLE_SHARED = ${ENABLE_SHARED}")
message(STATUS "UPX_CONFIG_HAVE_WORKING_BUILD_RPATH = ${UPX_CONFIG_HAVE_WORKING_BUILD_RPATH}")

upx_platform_check_c_cxx_mismatch()

# UPX options
upx_maybe_unused_var(UPX_CONFIG_DISABLE_GITREV)
#upx_maybe_unused_var(UPX_CONFIG_DISABLE_SANITIZE)
upx_maybe_unused_var(UPX_CONFIG_DISABLE_SELF_PACK_TEST)

# internal options that may get set
upx_maybe_unused_var(UPX_CONFIG_DISABLE_SAVE_TEMPS)
upx_maybe_unused_var(UPX_CONFIG_DISABLE_BZIP2 UPX_CONFIG_DISABLE_ZSTD)

# UPX official build settings
upx_maybe_unused_var(TC_EXE TC_NAME)
upx_maybe_unused_var(UPX_CONFIG_OFFICIAL_BUILD UPX_CONFIG_WITH_NRV)

upx_maybe_unused_var(LZO_CONFIG_CMAKE_EXECUTABLE_SUFFIX)
upx_maybe_unused_var(LZO_CONFIG_DISABLE_SHARED_LIBS)
upx_maybe_unused_var(LZO_CONFIG_HAVE_WORKING_BUILD_RPATH)

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/.cmt_cmake_config_done.txt" "")

# vim:set ft=cmake ts=4 sw=4 tw=0 et:
