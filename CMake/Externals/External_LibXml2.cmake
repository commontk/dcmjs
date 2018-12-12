
set(proj LibXml2)

# Set dependency list
set(${proj}_DEPENDENCIES "")

# Include dependent projects if any
ExternalProject_Include_Dependencies(${proj} PROJECT_VAR proj DEPENDS_VAR ${proj}_DEPENDENCIES)

if(${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})
  message(FATAL_ERROR "Enabling ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj} is not supported !")
endif()

# Sanity checks
if(DEFINED LIBXML2_INCLUDE_DIR AND NOT EXISTS ${LIBXML2_INCLUDE_DIR})
  message(FATAL_ERROR "LIBXML2_INCLUDE_DIR variable is defined but corresponds to non-existing directory")
endif()
if(DEFINED LIBXML2_LIBRARIES AND NOT EXISTS ${LIBXML2_LIBRARIES})
  message(FATAL_ERROR "LIBXML2_LIBRARIES variable is defined but corresponds to non-existing file")
endif()

if((NOT DEFINED LIBXML2_INCLUDE_DIR OR NOT DEFINED LIBXML2_LIBRARIES) AND NOT ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})

  set(EP_SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj})
  set(EP_BINARY_DIR ${CMAKE_BINARY_DIR}/${proj}-build)

  ExternalProject_Add(${proj}
    ${${proj}_EP_ARGS}
    URL "ftp://xmlsoft.org/libxml2/libxml2-2.9.8.tar.gz"
    URL_MD5 "b786e353e2aa1b872d70d5d1ca0c740d"
    DOWNLOAD_DIR ${DOWNLOAD_CACHE_DIR}
    DOWNLOAD_NO_PROGRESS 1
    SOURCE_DIR ${EP_SOURCE_DIR}
    BINARY_DIR ${EP_BINARY_DIR}
    PATCH_COMMAND
      ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/CMake/Externals/LibXml2-CMakeLists.txt
        ${EP_SOURCE_DIR}/CMakeLists.txt
      COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/CMake/Externals/LibXml2-config.h
        ${EP_SOURCE_DIR}/include/config.h
      COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/CMake/Externals/LibXml2-xmlversion.h
        ${EP_SOURCE_DIR}/include/libxml/xmlversion.h
    CMAKE_CACHE_ARGS
      ${EMSCRIPTEN_TOOLCHAIN_OPTIONS}
      # LibXml2 options
    INSTALL_COMMAND ""
    USES_TERMINAL_DOWNLOAD 1
    USES_TERMINAL_UPDATE 1
    USES_TERMINAL_CONFIGURE 1
    USES_TERMINAL_BUILD 1
    USES_TERMINAL_INSTALL 1
    DEPENDS
      ${${proj}_DEPENDENCIES}
    )
  set(LIBXML2_INCLUDE_DIR ${EP_SOURCE_DIR}/include)
  set(LIBXML2_LIBRARIES ${EP_BINARY_DIR}/libxml2.so)
else()
  # The project is provided using LIBXML2_LIBRARIES and LIBXML2_LIBRARIES, nevertheless since other project may depend on <proj>,
  # let's add an 'empty' one
  ExternalProject_Add_Empty(${proj} DEPENDS ${${proj}_DEPENDENCIES})
endif()

mark_as_superbuild(
  VARS
    LIBXML2_INCLUDE_DIR:PATH
    LIBXML2_LIBRARIES:STRING
  PROJECTS DCMTK
  LABELS "FIND_PACKAGE"
  )

ExternalProject_Message(${proj} "LIBXML2_INCLUDE_DIR:${LIBXML2_INCLUDE_DIR}")
ExternalProject_Message(${proj} "LIBXML2_LIBRARIES:${LIBXML2_LIBRARIES}")
