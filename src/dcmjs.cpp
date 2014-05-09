
// STD includes
#include <iostream>
#include <cstdlib>


#include "dcmjs_app_config.h"

// The following list of header has been generated using:
//  cd DCMTK
//  for file in `find -wholename *apps/*.cc`; do appname=$( basename ${file%.*} ); echo -e "#ifdef DCMJS_APP_${appname}\n#include <dcmtk/config/${appname}_app.h>\n#endif"; done

#ifdef DCMJS_APP_dcmdspfn
#include <dcmtk/config/dcmdspfn_app.h>
#endif
#ifdef DCMJS_APP_dconvlum
#include <dcmtk/config/dconvlum_app.h>
#endif
#ifdef DCMJS_APP_dcod2lum
#include <dcmtk/config/dcod2lum_app.h>
#endif
#ifdef DCMJS_APP_dcmj2pnm
#include <dcmtk/config/dcmj2pnm_app.h>
#endif
#ifdef DCMJS_APP_dcmmkdir
#include <dcmtk/config/dcmmkdir_app.h>
#endif
#ifdef DCMJS_APP_dcmdjpeg
#include <dcmtk/config/dcmdjpeg_app.h>
#endif
#ifdef DCMJS_APP_dcmcjpeg
#include <dcmtk/config/dcmcjpeg_app.h>
#endif
#ifdef DCMJS_APP_storescp
#include <dcmtk/config/storescp_app.h>
#endif
#ifdef DCMJS_APP_dcmrecv
#include <dcmtk/config/dcmrecv_app.h>
#endif
#ifdef DCMJS_APP_termscu
#include <dcmtk/config/termscu_app.h>
#endif
#ifdef DCMJS_APP_getscu
#include <dcmtk/config/getscu_app.h>
#endif
#ifdef DCMJS_APP_findscu
#include <dcmtk/config/findscu_app.h>
#endif
#ifdef DCMJS_APP_dcmsend
#include <dcmtk/config/dcmsend_app.h>
#endif
#ifdef DCMJS_APP_echoscu
#include <dcmtk/config/echoscu_app.h>
#endif
#ifdef DCMJS_APP_storescu
#include <dcmtk/config/storescu_app.h>
#endif
#ifdef DCMJS_APP_movescu
#include <dcmtk/config/movescu_app.h>
#endif
#ifdef DCMJS_APP_dcm2pnm
#include <dcmtk/config/dcm2pnm_app.h>
#endif
#ifdef DCMJS_APP_dcmquant
#include <dcmtk/config/dcmquant_app.h>
#endif
#ifdef DCMJS_APP_dcmscale
#include <dcmtk/config/dcmscale_app.h>
#endif
#ifdef DCMJS_APP_dcmsign
#include <dcmtk/config/dcmsign_app.h>
#endif
#ifdef DCMJS_APP_drtdump
#include <dcmtk/config/drtdump_app.h>
#endif
#ifdef DCMJS_APP_dcmdjpls
#include <dcmtk/config/dcmdjpls_app.h>
#endif
#ifdef DCMJS_APP_dcmcjpls
#include <dcmtk/config/dcmcjpls_app.h>
#endif
#ifdef DCMJS_APP_dcml2pnm
#include <dcmtk/config/dcml2pnm_app.h>
#endif
#ifdef DCMJS_APP_readoviw
#include <dcmtk/config/readoviw_app.h>
#endif
#ifdef DCMJS_APP_writwlst
#include <dcmtk/config/writwlst_app.h>
#endif
#ifdef DCMJS_APP_readwlst
#include <dcmtk/config/readwlst_app.h>
#endif
#ifdef DCMJS_APP_preplock
#include <dcmtk/config/preplock_app.h>
#endif
#ifdef DCMJS_APP_wlmscpfs
#include <dcmtk/config/wlmscpfs_app.h>
#endif
#ifdef DCMJS_APP_wlcefs
#include <dcmtk/config/wlcefs_app.h>
#endif
#ifdef DCMJS_APP_dcmdump
#include <dcmtk/config/dcmdump_app.h>
#endif
#ifdef DCMJS_APP_dcm2xml
#include <dcmtk/config/dcm2xml_app.h>
#endif
#ifdef DCMJS_APP_img2dcm
#include <dcmtk/config/img2dcm_app.h>
#endif
#ifdef DCMJS_APP_dcmodify
#include <dcmtk/config/dcmodify_app.h>
#endif
#ifdef DCMJS_APP_dcmdrle
#include <dcmtk/config/dcmdrle_app.h>
#endif
#ifdef DCMJS_APP_dcmftest
#include <dcmtk/config/dcmftest_app.h>
#endif
#ifdef DCMJS_APP_mdfconen
#include <dcmtk/config/mdfconen_app.h>
#endif
#ifdef DCMJS_APP_mdfdsman
#include <dcmtk/config/mdfdsman_app.h>
#endif
#ifdef DCMJS_APP_dcmcrle
#include <dcmtk/config/dcmcrle_app.h>
#endif
#ifdef DCMJS_APP_pdf2dcm
#include <dcmtk/config/pdf2dcm_app.h>
#endif
#ifdef DCMJS_APP_dump2dcm
#include <dcmtk/config/dump2dcm_app.h>
#endif
#ifdef DCMJS_APP_dcmgpdir
#include <dcmtk/config/dcmgpdir_app.h>
#endif
#ifdef DCMJS_APP_dcmconv
#include <dcmtk/config/dcmconv_app.h>
#endif
#ifdef DCMJS_APP_xml2dcm
#include <dcmtk/config/xml2dcm_app.h>
#endif
#ifdef DCMJS_APP_dcm2pdf
#include <dcmtk/config/dcm2pdf_app.h>
#endif
#ifdef DCMJS_APP_dcmpschk
#include <dcmtk/config/dcmpschk_app.h>
#endif
#ifdef DCMJS_APP_dcmp2pgm
#include <dcmtk/config/dcmp2pgm_app.h>
#endif
#ifdef DCMJS_APP_dcmpsprt
#include <dcmtk/config/dcmpsprt_app.h>
#endif
#ifdef DCMJS_APP_dcmmklut
#include <dcmtk/config/dcmmklut_app.h>
#endif
#ifdef DCMJS_APP_dcmpsmk
#include <dcmtk/config/dcmpsmk_app.h>
#endif
#ifdef DCMJS_APP_dcmpsrcv
#include <dcmtk/config/dcmpsrcv_app.h>
#endif
#ifdef DCMJS_APP_dcmprscp
#include <dcmtk/config/dcmprscp_app.h>
#endif
#ifdef DCMJS_APP_dcmmkcrv
#include <dcmtk/config/dcmmkcrv_app.h>
#endif
#ifdef DCMJS_APP_dcmpssnd
#include <dcmtk/config/dcmpssnd_app.h>
#endif
#ifdef DCMJS_APP_dcmprscu
#include <dcmtk/config/dcmprscu_app.h>
#endif
#ifdef DCMJS_APP_dcmqridx
#include <dcmtk/config/dcmqridx_app.h>
#endif
#ifdef DCMJS_APP_dcmqrti
#include <dcmtk/config/dcmqrti_app.h>
#endif
#ifdef DCMJS_APP_dcmqrscp
#include <dcmtk/config/dcmqrscp_app.h>
#endif
#ifdef DCMJS_APP_dsrdump
#include <dcmtk/config/dsrdump_app.h>
#endif
#ifdef DCMJS_APP_xml2dsr
#include <dcmtk/config/xml2dsr_app.h>
#endif
#ifdef DCMJS_APP_dsr2xml
#include <dcmtk/config/dsr2xml_app.h>
#endif
#ifdef DCMJS_APP_dsr2html
#include <dcmtk/config/dsr2html_app.h>
#endif

//-----------------------------------------------------------------------------
void display_help(const char* prog_name)
{
  std::cout << "Usage: " << prog_name << " <appname> [options]"<< std::endl;
}

//-----------------------------------------------------------------------------
// Provide empty implementation of openlog/closelog/syslog to shut down warnings.
// See https://github.com/commontk/dcmjs/issues/1
extern "C"
{
void openlog (const char *ident, int option, int facility){}
void closelog (void){}
void syslog(int pri, const char *fmt, ...){}
}

//-----------------------------------------------------------------------------
void display_list()
{
  // The following if/else statement has been generated using:
  //  cd DCMTK
  //  for file in `find -wholename *apps/*.cc`; do appname=$( basename ${file%.*} ); echo -e "#ifdef DCMJS_APP_${appname}\nstd::cout << \"${appname}\" << std::endl;\n#endif"; done
  #ifdef DCMJS_APP_dcmdspfn
  std::cout << "dcmdspfn" << std::endl;
  #endif
  #ifdef DCMJS_APP_dconvlum
  std::cout << "dconvlum" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcod2lum
  std::cout << "dcod2lum" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmj2pnm
  std::cout << "dcmj2pnm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmmkdir
  std::cout << "dcmmkdir" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmdjpeg
  std::cout << "dcmdjpeg" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmcjpeg
  std::cout << "dcmcjpeg" << std::endl;
  #endif
  #ifdef DCMJS_APP_storescp
  std::cout << "storescp" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmrecv
  std::cout << "dcmrecv" << std::endl;
  #endif
  #ifdef DCMJS_APP_termscu
  std::cout << "termscu" << std::endl;
  #endif
  #ifdef DCMJS_APP_getscu
  std::cout << "getscu" << std::endl;
  #endif
  #ifdef DCMJS_APP_findscu
  std::cout << "findscu" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmsend
  std::cout << "dcmsend" << std::endl;
  #endif
  #ifdef DCMJS_APP_echoscu
  std::cout << "echoscu" << std::endl;
  #endif
  #ifdef DCMJS_APP_storescu
  std::cout << "storescu" << std::endl;
  #endif
  #ifdef DCMJS_APP_movescu
  std::cout << "movescu" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcm2pnm
  std::cout << "dcm2pnm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmquant
  std::cout << "dcmquant" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmscale
  std::cout << "dcmscale" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmsign
  std::cout << "dcmsign" << std::endl;
  #endif
  #ifdef DCMJS_APP_drtdump
  std::cout << "drtdump" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmdjpls
  std::cout << "dcmdjpls" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmcjpls
  std::cout << "dcmcjpls" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcml2pnm
  std::cout << "dcml2pnm" << std::endl;
  #endif
  #ifdef DCMJS_APP_readoviw
  std::cout << "readoviw" << std::endl;
  #endif
  #ifdef DCMJS_APP_writwlst
  std::cout << "writwlst" << std::endl;
  #endif
  #ifdef DCMJS_APP_readwlst
  std::cout << "readwlst" << std::endl;
  #endif
  #ifdef DCMJS_APP_preplock
  std::cout << "preplock" << std::endl;
  #endif
  #ifdef DCMJS_APP_wlmscpfs
  std::cout << "wlmscpfs" << std::endl;
  #endif
  #ifdef DCMJS_APP_wlcefs
  std::cout << "wlcefs" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmdump
  std::cout << "dcmdump" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcm2xml
  std::cout << "dcm2xml" << std::endl;
  #endif
  #ifdef DCMJS_APP_img2dcm
  std::cout << "img2dcm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmodify
  std::cout << "dcmodify" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmdrle
  std::cout << "dcmdrle" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmftest
  std::cout << "dcmftest" << std::endl;
  #endif
  #ifdef DCMJS_APP_mdfconen
  std::cout << "mdfconen" << std::endl;
  #endif
  #ifdef DCMJS_APP_mdfdsman
  std::cout << "mdfdsman" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmcrle
  std::cout << "dcmcrle" << std::endl;
  #endif
  #ifdef DCMJS_APP_pdf2dcm
  std::cout << "pdf2dcm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dump2dcm
  std::cout << "dump2dcm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmgpdir
  std::cout << "dcmgpdir" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmconv
  std::cout << "dcmconv" << std::endl;
  #endif
  #ifdef DCMJS_APP_xml2dcm
  std::cout << "xml2dcm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcm2pdf
  std::cout << "dcm2pdf" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmpschk
  std::cout << "dcmpschk" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmp2pgm
  std::cout << "dcmp2pgm" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmpsprt
  std::cout << "dcmpsprt" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmmklut
  std::cout << "dcmmklut" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmpsmk
  std::cout << "dcmpsmk" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmpsrcv
  std::cout << "dcmpsrcv" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmprscp
  std::cout << "dcmprscp" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmmkcrv
  std::cout << "dcmmkcrv" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmpssnd
  std::cout << "dcmpssnd" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmprscu
  std::cout << "dcmprscu" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmqridx
  std::cout << "dcmqridx" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmqrti
  std::cout << "dcmqrti" << std::endl;
  #endif
  #ifdef DCMJS_APP_dcmqrscp
  std::cout << "dcmqrscp" << std::endl;
  #endif
  #ifdef DCMJS_APP_dsrdump
  std::cout << "dsrdump" << std::endl;
  #endif
  #ifdef DCMJS_APP_xml2dsr
  std::cout << "xml2dsr" << std::endl;
  #endif
  #ifdef DCMJS_APP_dsr2xml
  std::cout << "dsr2xml" << std::endl;
  #endif
  #ifdef DCMJS_APP_dsr2html
  std::cout << "dsr2html" << std::endl;
  #endif
}

//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  if(argc < 2)
    {
    display_help(argv[0]);
    return EXIT_FAILURE;
    }
  
  char * app_name = argv[1];
  char ** app_argv = &argv[1];
  int app_argc = argc - 1;
  
  if (strcmp(app_name, "list") == 0)
    {
    display_list();
    }
  //-----------------------------------------------------------------------------
  // The following if/else statement has been generated using:
  //  cd DCMTK
  //  for file in `find -wholename *apps/*.cc`; do \
  //    appname=$( basename ${file%.*} )
  //    echo "//-----------------------------------------------------------------------------"
  //    echo "else if (strcmp(app_name, \"${appname}\") == 0)"
  //    echo "  {"
  //    echo "#ifdef DCMJS_APP_${appname}"
  //    echo "  return ${appname}_main(app_argc, app_argv);"
  //    echo "#else"
  //    echo "  std::cerr << \"${appname} not available" '!' "\" << std::endl;"
  //    echo "#endif"
  //    echo "  }";
  //  done
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmdspfn") == 0)
    {
  #ifdef DCMJS_APP_dcmdspfn
    return dcmdspfn_main(app_argc, app_argv);
  #else
    std::cerr << "dcmdspfn not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dconvlum") == 0)
    {
  #ifdef DCMJS_APP_dconvlum
    return dconvlum_main(app_argc, app_argv);
  #else
    std::cerr << "dconvlum not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcod2lum") == 0)
    {
  #ifdef DCMJS_APP_dcod2lum
    return dcod2lum_main(app_argc, app_argv);
  #else
    std::cerr << "dcod2lum not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmj2pnm") == 0)
    {
  #ifdef DCMJS_APP_dcmj2pnm
    return dcmj2pnm_main(app_argc, app_argv);
  #else
    std::cerr << "dcmj2pnm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmmkdir") == 0)
    {
  #ifdef DCMJS_APP_dcmmkdir
    return dcmmkdir_main(app_argc, app_argv);
  #else
    std::cerr << "dcmmkdir not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmdjpeg") == 0)
    {
  #ifdef DCMJS_APP_dcmdjpeg
    return dcmdjpeg_main(app_argc, app_argv);
  #else
    std::cerr << "dcmdjpeg not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmcjpeg") == 0)
    {
  #ifdef DCMJS_APP_dcmcjpeg
    return dcmcjpeg_main(app_argc, app_argv);
  #else
    std::cerr << "dcmcjpeg not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "storescp") == 0)
    {
  #ifdef DCMJS_APP_storescp
    return storescp_main(app_argc, app_argv);
  #else
    std::cerr << "storescp not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmrecv") == 0)
    {
  #ifdef DCMJS_APP_dcmrecv
    return dcmrecv_main(app_argc, app_argv);
  #else
    std::cerr << "dcmrecv not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "termscu") == 0)
    {
  #ifdef DCMJS_APP_termscu
    return termscu_main(app_argc, app_argv);
  #else
    std::cerr << "termscu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "getscu") == 0)
    {
  #ifdef DCMJS_APP_getscu
    return getscu_main(app_argc, app_argv);
  #else
    std::cerr << "getscu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "findscu") == 0)
    {
  #ifdef DCMJS_APP_findscu
    return findscu_main(app_argc, app_argv);
  #else
    std::cerr << "findscu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmsend") == 0)
    {
  #ifdef DCMJS_APP_dcmsend
    return dcmsend_main(app_argc, app_argv);
  #else
    std::cerr << "dcmsend not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "echoscu") == 0)
    {
  #ifdef DCMJS_APP_echoscu
    return echoscu_main(app_argc, app_argv);
  #else
    std::cerr << "echoscu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "storescu") == 0)
    {
  #ifdef DCMJS_APP_storescu
    return storescu_main(app_argc, app_argv);
  #else
    std::cerr << "storescu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "movescu") == 0)
    {
  #ifdef DCMJS_APP_movescu
    return movescu_main(app_argc, app_argv);
  #else
    std::cerr << "movescu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcm2pnm") == 0)
    {
  #ifdef DCMJS_APP_dcm2pnm
    return dcm2pnm_main(app_argc, app_argv);
  #else
    std::cerr << "dcm2pnm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmquant") == 0)
    {
  #ifdef DCMJS_APP_dcmquant
    return dcmquant_main(app_argc, app_argv);
  #else
    std::cerr << "dcmquant not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmscale") == 0)
    {
  #ifdef DCMJS_APP_dcmscale
    return dcmscale_main(app_argc, app_argv);
  #else
    std::cerr << "dcmscale not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmsign") == 0)
    {
  #ifdef DCMJS_APP_dcmsign
    return dcmsign_main(app_argc, app_argv);
  #else
    std::cerr << "dcmsign not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "drtdump") == 0)
    {
  #ifdef DCMJS_APP_drtdump
    return drtdump_main(app_argc, app_argv);
  #else
    std::cerr << "drtdump not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmdjpls") == 0)
    {
  #ifdef DCMJS_APP_dcmdjpls
    return dcmdjpls_main(app_argc, app_argv);
  #else
    std::cerr << "dcmdjpls not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmcjpls") == 0)
    {
  #ifdef DCMJS_APP_dcmcjpls
    return dcmcjpls_main(app_argc, app_argv);
  #else
    std::cerr << "dcmcjpls not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcml2pnm") == 0)
    {
  #ifdef DCMJS_APP_dcml2pnm
    return dcml2pnm_main(app_argc, app_argv);
  #else
    std::cerr << "dcml2pnm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "readoviw") == 0)
    {
  #ifdef DCMJS_APP_readoviw
    return readoviw_main(app_argc, app_argv);
  #else
    std::cerr << "readoviw not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "writwlst") == 0)
    {
  #ifdef DCMJS_APP_writwlst
    return writwlst_main(app_argc, app_argv);
  #else
    std::cerr << "writwlst not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "readwlst") == 0)
    {
  #ifdef DCMJS_APP_readwlst
    return readwlst_main(app_argc, app_argv);
  #else
    std::cerr << "readwlst not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "preplock") == 0)
    {
  #ifdef DCMJS_APP_preplock
    return preplock_main(app_argc, app_argv);
  #else
    std::cerr << "preplock not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "wlmscpfs") == 0)
    {
  #ifdef DCMJS_APP_wlmscpfs
    return wlmscpfs_main(app_argc, app_argv);
  #else
    std::cerr << "wlmscpfs not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "wlcefs") == 0)
    {
  #ifdef DCMJS_APP_wlcefs
    return wlcefs_main(app_argc, app_argv);
  #else
    std::cerr << "wlcefs not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmdump") == 0)
    {
  #ifdef DCMJS_APP_dcmdump
    return dcmdump_main(app_argc, app_argv);
  #else
    std::cerr << "dcmdump not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcm2xml") == 0)
    {
  #ifdef DCMJS_APP_dcm2xml
    return dcm2xml_main(app_argc, app_argv);
  #else
    std::cerr << "dcm2xml not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "img2dcm") == 0)
    {
  #ifdef DCMJS_APP_img2dcm
    return img2dcm_main(app_argc, app_argv);
  #else
    std::cerr << "img2dcm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmodify") == 0)
    {
  #ifdef DCMJS_APP_dcmodify
    return dcmodify_main(app_argc, app_argv);
  #else
    std::cerr << "dcmodify not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmdrle") == 0)
    {
  #ifdef DCMJS_APP_dcmdrle
    return dcmdrle_main(app_argc, app_argv);
  #else
    std::cerr << "dcmdrle not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmftest") == 0)
    {
  #ifdef DCMJS_APP_dcmftest
    return dcmftest_main(app_argc, app_argv);
  #else
    std::cerr << "dcmftest not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "mdfconen") == 0)
    {
  #ifdef DCMJS_APP_mdfconen
    return mdfconen_main(app_argc, app_argv);
  #else
    std::cerr << "mdfconen not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "mdfdsman") == 0)
    {
  #ifdef DCMJS_APP_mdfdsman
    return mdfdsman_main(app_argc, app_argv);
  #else
    std::cerr << "mdfdsman not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmcrle") == 0)
    {
  #ifdef DCMJS_APP_dcmcrle
    return dcmcrle_main(app_argc, app_argv);
  #else
    std::cerr << "dcmcrle not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "pdf2dcm") == 0)
    {
  #ifdef DCMJS_APP_pdf2dcm
    return pdf2dcm_main(app_argc, app_argv);
  #else
    std::cerr << "pdf2dcm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dump2dcm") == 0)
    {
  #ifdef DCMJS_APP_dump2dcm
    return dump2dcm_main(app_argc, app_argv);
  #else
    std::cerr << "dump2dcm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmgpdir") == 0)
    {
  #ifdef DCMJS_APP_dcmgpdir
    return dcmgpdir_main(app_argc, app_argv);
  #else
    std::cerr << "dcmgpdir not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmconv") == 0)
    {
  #ifdef DCMJS_APP_dcmconv
    return dcmconv_main(app_argc, app_argv);
  #else
    std::cerr << "dcmconv not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "xml2dcm") == 0)
    {
  #ifdef DCMJS_APP_xml2dcm
    return xml2dcm_main(app_argc, app_argv);
  #else
    std::cerr << "xml2dcm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcm2pdf") == 0)
    {
  #ifdef DCMJS_APP_dcm2pdf
    return dcm2pdf_main(app_argc, app_argv);
  #else
    std::cerr << "dcm2pdf not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmpschk") == 0)
    {
  #ifdef DCMJS_APP_dcmpschk
    return dcmpschk_main(app_argc, app_argv);
  #else
    std::cerr << "dcmpschk not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmp2pgm") == 0)
    {
  #ifdef DCMJS_APP_dcmp2pgm
    return dcmp2pgm_main(app_argc, app_argv);
  #else
    std::cerr << "dcmp2pgm not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmpsprt") == 0)
    {
  #ifdef DCMJS_APP_dcmpsprt
    return dcmpsprt_main(app_argc, app_argv);
  #else
    std::cerr << "dcmpsprt not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmmklut") == 0)
    {
  #ifdef DCMJS_APP_dcmmklut
    return dcmmklut_main(app_argc, app_argv);
  #else
    std::cerr << "dcmmklut not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmpsmk") == 0)
    {
  #ifdef DCMJS_APP_dcmpsmk
    return dcmpsmk_main(app_argc, app_argv);
  #else
    std::cerr << "dcmpsmk not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmpsrcv") == 0)
    {
  #ifdef DCMJS_APP_dcmpsrcv
    return dcmpsrcv_main(app_argc, app_argv);
  #else
    std::cerr << "dcmpsrcv not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmprscp") == 0)
    {
  #ifdef DCMJS_APP_dcmprscp
    return dcmprscp_main(app_argc, app_argv);
  #else
    std::cerr << "dcmprscp not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmmkcrv") == 0)
    {
  #ifdef DCMJS_APP_dcmmkcrv
    return dcmmkcrv_main(app_argc, app_argv);
  #else
    std::cerr << "dcmmkcrv not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmpssnd") == 0)
    {
  #ifdef DCMJS_APP_dcmpssnd
    return dcmpssnd_main(app_argc, app_argv);
  #else
    std::cerr << "dcmpssnd not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmprscu") == 0)
    {
  #ifdef DCMJS_APP_dcmprscu
    return dcmprscu_main(app_argc, app_argv);
  #else
    std::cerr << "dcmprscu not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmqridx") == 0)
    {
  #ifdef DCMJS_APP_dcmqridx
    return dcmqridx_main(app_argc, app_argv);
  #else
    std::cerr << "dcmqridx not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmqrti") == 0)
    {
  #ifdef DCMJS_APP_dcmqrti
    return dcmqrti_main(app_argc, app_argv);
  #else
    std::cerr << "dcmqrti not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dcmqrscp") == 0)
    {
  #ifdef DCMJS_APP_dcmqrscp
    return dcmqrscp_main(app_argc, app_argv);
  #else
    std::cerr << "dcmqrscp not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dsrdump") == 0)
    {
  #ifdef DCMJS_APP_dsrdump
    return dsrdump_main(app_argc, app_argv);
  #else
    std::cerr << "dsrdump not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "xml2dsr") == 0)
    {
  #ifdef DCMJS_APP_xml2dsr
    return xml2dsr_main(app_argc, app_argv);
  #else
    std::cerr << "xml2dsr not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dsr2xml") == 0)
    {
  #ifdef DCMJS_APP_dsr2xml
    return dsr2xml_main(app_argc, app_argv);
  #else
    std::cerr << "dsr2xml not available ! " << std::endl;
  #endif
    }
  //-----------------------------------------------------------------------------
  else if (strcmp(app_name, "dsr2html") == 0)
    {
  #ifdef DCMJS_APP_dsr2html
    return dsr2html_main(app_argc, app_argv);
  #else
    std::cerr << "dsr2html not available ! " << std::endl;
  #endif
    }
  else 
    {
    std::cerr << "Unknown application name !" << std::endl;
    display_help(argv[0]);
    return EXIT_FAILURE;
    }
  
  return EXIT_SUCCESS;
}
