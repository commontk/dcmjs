
set(proj DCMTK)

# Set dependency list
set(${proj}_DEPENDENCIES PNG ZLIB LibXml2)

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
  set(${proj}_GIT_TAG "728784645e1768c671871a41bb56f1acfedce1ec") # emscripten-2018-11-29-1967b1313 (Based of DCMTK-3.6.4)

  set(app_cache_args)

  macro(dcmtk_build_app_option varname default)
    if(NOT DEFINED ${varname})
      set(value ${default})
    else()
      set(value ${${varname}})
    endif()
    list(APPEND app_cache_args
      -D${varname}:BOOL=${value}
      )
    if(${value})
      ExternalProject_Message(${proj} "${varname}: ${value}")
    endif()
  endmacro()

  dcmtk_build_app_option(BUILD_cda2dcm_APP   OFF)
  dcmtk_build_app_option(BUILD_dcm2json_APP  OFF)
  dcmtk_build_app_option(BUILD_dcm2pdf_APP   OFF)
  dcmtk_build_app_option(BUILD_dcm2pnm_APP   ON)
  dcmtk_build_app_option(BUILD_dcm2xml_APP   ON)
  dcmtk_build_app_option(BUILD_dcmcjpeg_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmcjpls_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmconv_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmcrle_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmdjpeg_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmdjpls_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmdrle_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmdspfn_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmdump_APP   ON)
  dcmtk_build_app_option(BUILD_dcmftest_APP  ON)
  dcmtk_build_app_option(BUILD_dcmgpdir_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmicmp_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmj2pnm_APP  OFF)
  dcmtk_build_app_option(BUILD_dcml2pnm_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmmkcrv_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmmkdir_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmmklut_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmodify_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmp2pgm_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmprscp_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmprscu_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmpschk_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmpsmk_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmpsprt_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmpsrcv_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmpssnd_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmqridx_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmqrscp_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmqrti_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmquant_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmrecv_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmscale_APP  OFF)
  dcmtk_build_app_option(BUILD_dcmsend_APP   OFF)
  dcmtk_build_app_option(BUILD_dcmsign_APP   OFF)
  dcmtk_build_app_option(BUILD_dcod2lum_APP  OFF)
  dcmtk_build_app_option(BUILD_dconvlum_APP  OFF)
  dcmtk_build_app_option(BUILD_drtdump_APP   OFF)
  dcmtk_build_app_option(BUILD_dsr2html_APP  OFF)
  dcmtk_build_app_option(BUILD_dsr2xml_APP   OFF)
  dcmtk_build_app_option(BUILD_dsrdump_APP   OFF)
  dcmtk_build_app_option(BUILD_dump2dcm_APP  OFF)
  dcmtk_build_app_option(BUILD_echoscu_APP   OFF)
  dcmtk_build_app_option(BUILD_findscu_APP   OFF)
  dcmtk_build_app_option(BUILD_getscu_APP    OFF)
  dcmtk_build_app_option(BUILD_img2dcm_APP   OFF)
  dcmtk_build_app_option(BUILD_mdfconen_APP  OFF)
  dcmtk_build_app_option(BUILD_mdfdsman_APP  OFF)
  dcmtk_build_app_option(BUILD_movescu_APP   OFF)
  dcmtk_build_app_option(BUILD_pdf2dcm_APP   OFF)
  dcmtk_build_app_option(BUILD_stl2dcm_APP   OFF)
  dcmtk_build_app_option(BUILD_storescp_APP  OFF)
  dcmtk_build_app_option(BUILD_storescu_APP  OFF)
  dcmtk_build_app_option(BUILD_termscu_APP   OFF)
  dcmtk_build_app_option(BUILD_wlcefs_APP    OFF)
  dcmtk_build_app_option(BUILD_wlmscpfs_APP  OFF)
  dcmtk_build_app_option(BUILD_xml2dcm_APP   ON)
  dcmtk_build_app_option(BUILD_xml2dsr_APP   OFF)

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
      -DDCMTK_WITH_XML:BOOL=ON
      -DDCMTK_WITH_ICONV:BOOL=OFF
      -DDCMTK_WITH_THREADS:BOOL=OFF
      -DBUILD_TESTING:BOOL=OFF
      ${app_cache_args}
      # Toolchain customization
      -DC_CHAR_SIGNED:BOOL=1
      -DHAVE__FINDFIRST:BOOL=0
      -DGXX_SUPPORTS_VISIBILITY:BOOL=0
      -DSIZEOF_VOID_P:STRING=4
      -DDCMTK_ENABLE_BUILTIN_DICTIONARY:BOOL=ON
      -DDCMTK_ENABLE_EXTERNAL_DICTIONARY:BOOL=OFF
    USES_TERMINAL_DOWNLOAD 1
    USES_TERMINAL_UPDATE 1
    USES_TERMINAL_CONFIGURE 1
    USES_TERMINAL_BUILD 1
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
