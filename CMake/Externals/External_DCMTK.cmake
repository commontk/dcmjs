
set(proj DCMTK)

# Set dependency list
set(${proj}_DEPENDENCIES PNG ZLIB)

# Include dependent projects if any
ExternalProject_Include_Dependencies(${proj} PROJECT_VAR proj DEPENDS_VAR ${proj}_DEPENDENCIES)

if(${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})
  message(FATAL_ERROR "Enabling ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj} is not supported !")
endif()

# Sanity checks
if(DEFINED DCMTK_DIR AND NOT EXISTS ${DCMTK_DIR})
  message(FATAL_ERROR "DCMTK_DIR variable is defined but corresponds to non-existing directory")
endif()

if(NOT DEFINED DCMTK_DIR AND NOT ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})

  set(${proj}_REPOSITORY ${git_protocol}://github.com/jcfr/DCMTK)
  set(${proj}_GIT_TAG "7ef3b94093fe5fbef8b19ba0c2aabb9ed22af054")
  
  ExternalProject_Add(${proj}
    ${${proj}_EP_ARGS}
    GIT_REPOSITORY ${DCMTK_REPOSITORY}
    GIT_TAG ${DCMTK_GIT_TAG}
    SOURCE_DIR ${proj}
    BINARY_DIR ${proj}-build
    CMAKE_CACHE_ARGS
      ${EMSCRIPTEN_TOOLCHAIN_OPTIONS}
      # DCMTK options
      -DUSE_COMPILER_HIDDEN_VISIBILITY:BOOL=OFF
      -DDCMTK_FORCE_FPIC_ON_UNIX:BOOL=ON
      -DDCMTK_WITH_WRAP:BOOL=OFF
      -DBUILD_SHARED_LIBS:BOOL=ON
      -DDCMTK_WITH_DOXYGEN:BOOL=OFF
      -DDCMTK_WITH_ZLIB:BOOL=ON
      -DDCMTK_WITH_OPENSSL:BOOL=OFF
      -DDCMTK_WITH_PNG:BOOL=ON
      -DDCMTK_WITH_TIFF:BOOL=OFF
      -DDCMTK_WITH_XML:BOOL=OFF
      -DDCMTK_WITH_ICONV:BOOL=OFF
      -DDCMTK_WITH_THREADS:BOOL=OFF
      -DBUILD_TESTING:BOOL=OFF
      # Toolchain customization
      -DC_CHAR_SIGNED:BOOL=1
      -DHAVE__FINDFIRST:BOOL=0
      -DGXX_SUPPORTS_VISIBILITY:BOOL=0
      -DSIZEOF_VOID_P:STRING=4
      -DDCMJS_PREJS_SCRIPT:FILEPATH=${CMAKE_SOURCE_DIR}/javascripts/pre.js
    INSTALL_COMMAND ""
    DEPENDS
      ${${proj}_DEPENDENCIES}
  )
  set(DCMTK_DIR ${CMAKE_BINARY_DIR}/${proj}-build)

else()
  ExternalProject_Add_Empty(${proj} DEPENDS ${${proj}_DEPENDENCIES})
endif()

mark_as_superbuild(
  VARS DCMTK_DIR:PATH
  LABELS "FIND_PACKAGE"
  )
