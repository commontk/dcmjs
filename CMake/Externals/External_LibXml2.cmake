
set(proj LibXml2)

# Set dependency list
set(${proj}_DEPENDENCIES "")

# Include dependent projects if any
ExternalProject_Include_Dependencies(${proj} PROJECT_VAR proj DEPENDS_VAR ${proj}_DEPENDENCIES)

if(${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})
  
endif()

# Sanity checks
if(DEFINED ${proj}_DIR AND NOT EXISTS ${${proj}_DIR})
  message(FATAL_ERROR "<proj>_DIR variable is defined but corresponds to non-existing directory")
endif()

if(NOT DEFINED ${proj}_DIR AND NOT ${CMAKE_PROJECT_NAME}_USE_SYSTEM_${proj})

  set(EP_SOURCE_DIR ${CMAKE_BINARY_DIR}/${proj})
  set(EP_BINARY_DIR ${CMAKE_BINARY_DIR}/${proj}-build)
  set(EP_INSTALL_DIR ${CMAKE_BINARY_DIR}/${proj}-install)
  
  include(ExternalProjectForNonCMakeProject)

  # Adapted from http://mozakai.blogspot.com/2012/03/howto-port-cc-library-to-javascript.html

  # environment
  set(_env_script ${CMAKE_BINARY_DIR}/${proj}_Env.cmake)
  ExternalProject_Write_SetBuildEnv_Commands(${_env_script})
  file(APPEND ${_env_script}
"#------------------------------------------------------------------------------
# Added by '${CMAKE_CURRENT_LIST_FILE}'
include(\"${${CMAKE_PROJECT_NAME}_CMAKE_DIR}/ExternalProjectForNonCMakeProject.cmake\")
set(CMAKE_BINARY_DIR \"${CMAKE_BINARY_DIR}\")

")

  set(_src_dir ${EP_SOURCE_DIR})

  # configure step
  set(_configure_script ${CMAKE_BINARY_DIR}/${proj}_configure_step.cmake)
  file(WRITE ${_configure_script}
"include(\"${_env_script}\")
set(${proj}_WORKING_DIR \"${_src_dir}\")
ExternalProject_Execute(${proj} \"configure\" ${EMSCRIPTEN_ROOT_PATH}/emconfigure ./configure
  --without-python --without-iconv --without-http --without-ftp
  ) 
")

  # build step
  set(_build_script ${CMAKE_BINARY_DIR}/${proj}_build_step.cmake)
  file(WRITE ${_build_script}
"include(\"${_env_script}\")
set(${proj}_WORKING_DIR \"${_src_dir}\")
ExternalProject_Execute(${proj} \"build\" ${EMSCRIPTEN_ROOT_PATH}/emmake make)
")
    
  ExternalProject_Add(${proj}
    ${${proj}_EP_ARGS}
    URL "ftp://xmlsoft.org/libxml2/libxml2-2.9.4.tar.gz"
    URL_MD5 "ae249165c173b1ff386ee8ad676815f5"
    DOWNLOAD_DIR ${DOWNLOAD_CACHE_DIR}
    DOWNLOAD_NO_PROGRESS 1
    SOURCE_DIR ${EP_SOURCE_DIR}
    BUILD_IN_SOURCE 1
    CONFIGURE_COMMAND ${CMAKE_COMMAND} -P ${_configure_script}
    BUILD_COMMAND ${CMAKE_COMMAND} -P ${_build_script}
    USES_TERMINAL_DOWNLOAD 1
    USES_TERMINAL_UPDATE 1
    USES_TERMINAL_CONFIGURE 1
    USES_TERMINAL_BUILD 1
    INSTALL_COMMAND ""
    DEPENDS
      ${${proj}_DEPENDENCIES}
    )
  set(${proj}_DIR ${_src_dir})
  set(LIBXML2_INCLUDE_DIR ${${proj}_DIR}/include)
  set(LIBXML2_LIBRARIES ${${proj}_DIR}/.libs/libxml2.a)
else()
  # The project is provided using <proj>_DIR, nevertheless since other project may depend on <proj>,
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
