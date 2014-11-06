###########################################################################
#
#  Library:   CTK
#
#  Copyright (c) Kitware Inc.
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0.txt
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#
###########################################################################

cmake_minimum_required(VERSION 2.8.12)

project(dcmjs NONE)

#-----------------------------------------------------------------------------
# Superbuild
#------------------------------------------------------------------------------
set(${PROJECT_NAME}_CMAKE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
set(CMAKE_MODULE_PATH "${${PROJECT_NAME}_CMAKE_DIR}" ${CMAKE_MODULE_PATH})
set(EXTERNAL_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CMake/Externals)
set(EXTERNAL_PROJECT_FILE_PREFIX "External_")
include(ExternalProject)
include(ExternalProjectDependency)

#------------------------------------------------------------------------------
# Options
#------------------------------------------------------------------------------
option(${CMAKE_PROJECT_NAME}_USE_GIT_PROTOCOL "If behind a firewall turn this off to use https instead." ON)
set(git_protocol "git")
if(NOT ${CMAKE_PROJECT_NAME}_USE_GIT_PROTOCOL)
  set(git_protocol "https")
endif()

# If not found by above search, locate using the EMSCRIPTEN environment variable.
if ("${EMSCRIPTEN_ROOT_PATH}" STREQUAL "")
  set(EMSCRIPTEN_ROOT_PATH "$ENV{EMSCRIPTEN}")
endif()

# Abort if not found. 
if ("${EMSCRIPTEN_ROOT_PATH}" STREQUAL "")
  message(FATAL_ERROR "Could not locate the Emscripten compiler toolchain directory! Either set the EMSCRIPTEN environment variable, or pass -DEMSCRIPTEN_ROOT_PATH=xxx to CMake to explicitly specify the location of the compiler!")
endif()

# Check version
set(EMSCRIPTEN_REQUIRED_VERSION 1.21.4)
if(EXISTS ${EMSCRIPTEN_ROOT_PATH}/emscripten-version.txt)
  file(READ ${EMSCRIPTEN_ROOT_PATH}/emscripten-version.txt EMSCRIPTEN_VERSION)
  string(STRIP ${EMSCRIPTEN_VERSION} EMSCRIPTEN_VERSION)
  message(STATUS "Found Emscripten ${EMSCRIPTEN_VERSION}")
  if(EMSCRIPTEN_VERSION VERSION_LESS ${EMSCRIPTEN_REQUIRED_VERSION})
    message(FATAL_ERROR "Emscripten >= ${EMSCRIPTEN_REQUIRED_VERSION} is required.")
  endif()
endif()

#------------------------------------------------------------------------------
# Options
#------------------------------------------------------------------------------
set(CMAKE_C_COMPILER "${EMSCRIPTEN_ROOT_PATH}/emcc")
set(CMAKE_CXX_COMPILER "${EMSCRIPTEN_ROOT_PATH}/em++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-warn-absolute-paths -s ALLOW_MEMORY_GROWTH=1 -s ASSERTIONS=1 --memory-init-file 0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-warn-absolute-paths -s ALLOW_MEMORY_GROWTH=1 -s ASSERTIONS=1 --memory-init-file 0")

# Emscripten toolchain options
set(EMSCRIPTEN_TOOLCHAIN_OPTIONS
  -DCMAKE_MODULE_PATH:PATH=${EMSCRIPTEN_ROOT_PATH}/cmake/Modules
  -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${EMSCRIPTEN_ROOT_PATH}/cmake/Modules/Platform/Emscripten.cmake
  -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER}
  -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
  -DCMAKE_C_COMPILER:FILEPATH=${CMAKE_C_COMPILER}
  -DCMAKE_C_FLAGS:STRING=${CMAKE_C_FLAGS}
  -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
  )

#------------------------------------------------------------------------------
# Configure and build dcmjs
#------------------------------------------------------------------------------
option(${PROJECT_NAME}_SUPERBUILD "Build ${PROJECT_NAME} and the projects it depends on." ON)
mark_as_advanced(${PROJECT_NAME}_SUPERBUILD)
if(${PROJECT_NAME}_SUPERBUILD)
  set(${PROJECT_NAME}_DEPENDENCIES DCMTK)
  ExternalProject_Include_Dependencies(${PROJECT_NAME} DEPENDS_VAR ${PROJECT_NAME}_DEPENDENCIES)
  ExternalProject_Add(${PROJECT_NAME}
    ${${PROJECT_NAME}_EP_ARGS}
    DOWNLOAD_COMMAND ""
    INSTALL_COMMAND ""
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
    BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/dcmjs-build
    CMAKE_CACHE_ARGS
      ${EMSCRIPTEN_TOOLCHAIN_OPTIONS}
      -D${PROJECT_NAME}_SUPERBUILD:BOOL=OFF
      -D${PROJECT_NAME}_SUPERBUILD_BINARY_DIR:PATH=${${PROJECT_NAME}_BINARY_DIR}
      -DDCMJS_PREJS_SCRIPT:FILEPATH=${CMAKE_SOURCE_DIR}/javascripts/pre.js
    DEPENDS
      ${${PROJECT_NAME}_DEPENDENCIES}
    )
  return()
endif()

#------------------------------------------------------------------------------
# Configure and build dcmjs_wrapper
#------------------------------------------------------------------------------

add_subdirectory(src)

