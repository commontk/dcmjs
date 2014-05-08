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
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake" ${CMAKE_MODULE_PATH})
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

#------------------------------------------------------------------------------
# Options
#------------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-warn-absolute-paths")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-warn-absolute-paths")

# Emscripten toolchain options
set(EMSCRIPTEN_TOOLCHAIN_OPTIONS
  -DCMAKE_MODULE_PATH:PATH=${EMSCRIPTEN_ROOT_PATH}/cmake/Modules
  -DCMAKE_TOOLCHAIN_FILE:FILEPATH=${EMSCRIPTEN_ROOT_PATH}/cmake/Platform/Emscripten.cmake
  -DCMAKE_CXX_COMPILER:FILEPATH=${EMSCRIPTEN_ROOT_PATH}/em++
  -DCMAKE_CXX_FLAGS:STRING=${CMAKE_CXX_FLAGS}
  -DCMAKE_C_COMPILER:FILEPATH=${EMSCRIPTEN_ROOT_PATH}/emcc
  -DCMAKE_C_FLAGS:STRING=${CMAKE_C_FLAGS}
  -DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}
  )

#------------------------------------------------------------------------------
# Configure and build dcmjs
#------------------------------------------------------------------------------
set(${PROJECT_NAME}_SUPERBUILD ON)
set(${PROJECT_NAME}_DEPENDENCIES DCMTK)
ExternalProject_Include_Dependencies(${PROJECT_NAME} DEPENDS_VAR ${PROJECT_NAME}_DEPENDENCIES)

