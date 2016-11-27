
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
  set(${proj}_GIT_TAG "693eabe2f2a8285be4027b45d816774d50389256") # Based of DCMTK-3.6.1_20161102

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
      -DBUILD_ofstd_tests_APP:BOOL=OFF
      -DBUILD_dcm2xml_APP:BOOL=ON
      -DBUILD_dcmconv_APP:BOOL=OFF
      -DBUILD_dcmcrle_APP:BOOL=OFF
      -DBUILD_dcmdrle_APP:BOOL=OFF
      -DBUILD_dcmdump_APP:BOOL=ON
      -DBUILD_dcmftest_APP:BOOL=ON
      -DBUILD_dcmgpdir_APP:BOOL=OFF
      -DBUILD_dump2dcm_APP:BOOL=OFF
      -DBUILD_xml2dcm_APP:BOOL=ON
      -DBUILD_pdf2dcm_APP:BOOL=OFF
      -DBUILD_dcm2pdf_APP:BOOL=OFF
      -DBUILD_img2dcm_APP:BOOL=OFF
      -DBUILD_dcmodify_APP:BOOL=OFF
      -DBUILD_dcmdata_tests_APP:BOOL=OFF
      -DBUILD_dcmdspfn_APP:BOOL=OFF
      -DBUILD_dcod2lum_APP:BOOL=OFF
      -DBUILD_dconvlum_APP:BOOL=OFF
      -DBUILD_dcm2pnm_APP:BOOL=ON
      -DBUILD_dcmquant_APP:BOOL=OFF
      -DBUILD_dcmscale_APP:BOOL=OFF
      -DBUILD_dcmcjpeg_APP:BOOL=OFF
      -DBUILD_dcmdjpeg_APP:BOOL=OFF
      -DBUILD_dcmj2pnm_APP:BOOL=OFF
      -DBUILD_dcmmkdir_APP:BOOL=OFF
      -DBUILD_dcmcjpls_APP:BOOL=OFF
      -DBUILD_dcmdjpls_APP:BOOL=OFF
      -DBUILD_dcml2pnm_APP:BOOL=OFF
      -DBUILD_dcmrecv_APP:BOOL=OFF
      -DBUILD_dcmsend_APP:BOOL=OFF
      -DBUILD_echoscu_APP:BOOL=OFF
      -DBUILD_findscu_APP:BOOL=OFF
      -DBUILD_getscu_APP:BOOL=OFF
      -DBUILD_movescu_APP:BOOL=OFF
      -DBUILD_storescp_APP:BOOL=OFF
      -DBUILD_storescu_APP:BOOL=OFF
      -DBUILD_termscu_APP:BOOL=OFF
      -DBUILD_dcmnet_tests_APP:BOOL=OFF
      -DBUILD_dsr2html_APP:BOOL=OFF
      -DBUILD_dsr2xml_APP:BOOL=OFF
      -DBUILD_dsrdump_APP:BOOL=OFF
      -DBUILD_xml2dsr_APP:BOOL=OFF
      -DBUILD_mkreport_APP:BOOL=OFF
      -DBUILD_dcmsr_tests_APP:BOOL=OFF
      -DBUILD_dcmsign_APP:BOOL=OFF
      -DBUILD_wlmscpfs_APP:BOOL=OFF
      -DBUILD_readoviw_APP:BOOL=OFF
      -DBUILD_readwlst_APP:BOOL=OFF
      -DBUILD_writwlst_APP:BOOL=OFF
      -DBUILD_preplock_APP:BOOL=OFF
      -DBUILD_dcmqrscp_APP:BOOL=OFF
      -DBUILD_dcmqridx_APP:BOOL=OFF
      -DBUILD_dcmqrti_APP:BOOL=OFF
      -DBUILD_dcmmkcrv_APP:BOOL=OFF
      -DBUILD_dcmmklut_APP:BOOL=OFF
      -DBUILD_dcmp2pgm_APP:BOOL=OFF
      -DBUILD_dcmprscp_APP:BOOL=OFF
      -DBUILD_dcmprscu_APP:BOOL=OFF
      -DBUILD_dcmpschk_APP:BOOL=OFF
      -DBUILD_dcmpsmk_APP:BOOL=OFF
      -DBUILD_dcmpsprt_APP:BOOL=OFF
      -DBUILD_dcmpsrcv_APP:BOOL=OFF
      -DBUILD_dcmpssnd_APP:BOOL=OFF
      -DBUILD_drtdump_APP:BOOL=OFF
      -DBUILD_drttest_APP:BOOL=OFF
      -DBUILD_dcmrt_tests_APP:BOOL=OFF
      # Toolchain customization
      -DC_CHAR_SIGNED:BOOL=1
      -DHAVE__FINDFIRST:BOOL=0
      -DGXX_SUPPORTS_VISIBILITY:BOOL=0
      -DSIZEOF_VOID_P:STRING=4
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
