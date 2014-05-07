dcmjs is a javascript cross-compilation of dcmtk (dcmtk.org) for use
in a javascript environment.  Uses emscripten.

                      http://www.dcmjs.org

See License.txt for information on using and contributing.


Full CMake-based instructions coming.  For now these hints should help.

(make dcmdump && (cd dcmdata/apps/; /Users/pieper/Downloads/emscripten/emsdk_portable/emscripten/1.16.0/em++    -D_XOPEN_SOURCE_EXTENDED -D_BSD_SOURCE -D_BSD_COMPAT -D_OSF_SOURCE -D_DARWIN_C_SOURCE -Wl,-search_paths_first -Wl,-headerpad_max_install_names  -s NO_EXIT_RUNTIME=1 CMakeFiles/dcmdump.dir/dcmdump.cc.o  -o ../../bin/dcmdump.js   ../../lib/libdcmdata.a ../../lib/liboflog.a ../../lib/libofstd.a --embed-file f.dcm;)
