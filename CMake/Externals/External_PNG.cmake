
set(proj PNG)

# Set dependency list
set(${proj}_DEPENDENCIES ZLIB)

# Include dependent projects if any
ExternalProject_Include_Dependencies(${proj} PROJECT_VAR proj DEPENDS_VAR ${proj}_DEPENDENCIES)

if(${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})
  message(FATAL_ERROR "Enabling ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj} is not supported !")
endif()

# Sanity checks
if(DEFINED ${proj}_DIR AND NOT EXISTS ${${proj}_DIR})
  message(FATAL_ERROR "${proj}_DIR variable is defined but corresponds to non-existing directory")
endif()

if(NOT DEFINED ${proj}_DIR AND NOT ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})

  set(EP_SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj})
  set(EP_BINARY_DIR ${CMAKE_BINARY_DIR}/${proj}-build)
  set(EP_INSTALL_DIR ${CMAKE_BINARY_DIR}/${proj}-install)

  ExternalProject_Add(${proj}
    ${${proj}_EP_ARGS}
    URL "http://download.sourceforge.net/libpng/libpng-1.6.26.tar.xz"
    URL_MD5 "faed9bb495d2e12dd0c9ec561ca60cd8"
    SOURCE_DIR ${EP_SOURCE_DIR}
    BINARY_DIR ${EP_BINARY_DIR}
    INSTALL_DIR ${EP_INSTALL_DIR}
    CMAKE_CACHE_ARGS
      ${EMSCRIPTEN_TOOLCHAIN_OPTIONS}
      # PNG options
      -DPNG_TESTS:BOOL=OFF
      -DPNG_SHARED:BOOL=ON
      -DPNG_STATIC:BOOL=OFF
      -DM_LIBRARY:FILEPATH= # Disable floating point
      -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
    USES_TERMINAL_DOWNLOAD 1
    USES_TERMINAL_UPDATE 1
    USES_TERMINAL_CONFIGURE 1
    USES_TERMINAL_BUILD 1
    USES_TERMINAL_INSTALL 1
    DEPENDS
      ${${proj}_DEPENDENCIES}
    )
  set(${proj}_DIR ${EP_INSTALL_DIR})
  set(${proj}_PNG_INCLUDE_DIR ${${proj}_DIR}/include)
  set(${proj}_LIBRARY ${${proj}_DIR}/lib/libpng16.so)
else()
  # The project is provided using <proj>_DIR, nevertheless since other project may depend on <proj>,
  # let's add an 'empty' one
  ExternalProject_Add_Empty(${proj} DEPENDS ${${proj}_DEPENDENCIES})
endif()

mark_as_superbuild(
  VARS
    ${proj}_PNG_INCLUDE_DIR:PATH
    ${proj}_LIBRARY:FILEPATH
  PROJECTS DCMTK
  LABELS "FIND_PACKAGE"
  )

ExternalProject_Message(${proj} "${proj}_INCLUDE_DIR:${${proj}_INCLUDE_DIR}")
ExternalProject_Message(${proj} "${proj}_LIBRARY:${${proj}_LIBRARY}")
