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

project(dcmjs)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

find_package(DCMTK CONFIG REQUIRED)
include_directories(${DCMTK_INCLUDE_DIRS})

# dcmjs_app_config.h
#set(_content )
#foreach(appname ${DCMTK_APPLICATIONS})
#  set(_content "${_content}\n\#define DCMJS_APP_${appname}")
#endforeach()
#file(WRITE "${CMAKE_BINARY_DIR}/CMakeFiles/dcmjs_app_config.h" "${_content}")
#configure_file(
#  ${CMAKE_BINARY_DIR}/CMakeFiles/dcmjs_app_config.h
#  ${CMAKE_BINARY_DIR}/src/dcmjs_app_config.h
#  )

# DCMJS_APP_INCLUDE
set(_content )
foreach(appname ${DCMTK_APPLICATIONS})
  set(_content "${_content}
\#include <dcmtk/config/${appname}_app.h>"
)
endforeach()
set(DCMJS_APP_INCLUDE ${_content})

# DCMJS_DISPLAY_LIST_IMPL
set(_content )
foreach(appname ${DCMTK_APPLICATIONS})
  set(_content "${_content}
  std::cout << \"${appname}\" << std::endl\;"
)
endforeach()
set(DCMJS_DISPLAY_LIST_IMPL ${_content})

# DCMJS_MAIN_IMPL
set(_content )
foreach(appname ${DCMTK_APPLICATIONS})
  set(_content "${_content}
  else if (strcmp(app_name, \"${appname}\") == 0)
    {
    return ${appname}_main(app_argc, app_argv);
    }"
)
endforeach()
set(DCMJS_MAIN_IMPL ${_content})

# Configure main.cpp
configure_file(
  dcmjs.cpp.in
  ${CMAKE_BINARY_DIR}/src/dcmjs.cpp
  )

# Build dcmjs
add_executable(${PROJECT_NAME} ${CMAKE_BINARY_DIR}/src/dcmjs.cpp)
target_link_libraries(${PROJECT_NAME} ${DCMTK_APPLICATIONS})

if(DCMJS_PREJS_SCRIPT)
  em_link_pre_js(${PROJECT_NAME} ${DCMJS_PREJS_SCRIPT})
endif()
if(DCMJS_POSTJS_SCRIPT)
  em_link_post_js(${PROJECT_NAME} ${DCMJS_POSTJS_SCRIPT})
endif()

# Compress .js
find_program(GZIP_EXECUTABLE gzip)
if(GZIP_EXECUTABLE)
  add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bak
      COMMAND ${GZIP_EXECUTABLE} -f $<TARGET_FILE:${PROJECT_NAME}>
      COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bak $<TARGET_FILE:${PROJECT_NAME}>
    COMMENT "Gzip'ing ${PROJECT_NAME}.js"
    )
endif()

# Configure CLI
file(
  COPY ${CMAKE_SOURCE_DIR}/javascripts/dcmjs-cli
  DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  )

