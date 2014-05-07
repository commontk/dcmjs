dcmjs
=====

Overview
--------

dcmjs is a javascript cross-compilation of dcmtk (dcmtk.org) for use
in a javascript environment.  Uses emscripten.

                      http://www.dcmjs.org

See License.txt for information on using and contributing.

Prerequisites
-------------

* Install emscripten: https://github.com/kripken/emscripten/wiki/Emscripten-SDK

* Install CMake: http://www.cmake.org

* Install Git: http://git-scm.com/downloads

Building
--------

The following commands will checkout dcmjs project and build a js file for each DCMTK applications.

Note that you need to change `EMSCRIPTEN_ROOT_PATH` with the path containing `emcc` / `em++`:

```
git clone git://github.com/commontk/dcmjs
mkdir dcmjs-build
cd dcmjs-build
cmake -DEMSCRIPTEN_ROOT_PATH:PATH=/path/to/emscripten -DCMAKE_BUILD_TYPE:STRING=Release ../dcmjs
make -j5
```

When done, you will have a set of `.js` and `.js.gz` files in the `DCMTK-build/bin` folder:

```
$ ls DCMTK-build/bin/
dcm2pdf.js      dcmcrle.js           dcmdump.js      dcmmkdir.js         dcmprscu.js     dcmqridx.js        dcmscale.js        drtdump.js      echoscu.js      ofstd_tests.js     storescu.js
dcm2pdf.js.gz   dcmcrle.js.gz        dcmdump.js.gz   dcmmkdir.js.gz      dcmprscu.js.gz  dcmqridx.js.gz     dcmscale.js.gz     drtdump.js.gz   echoscu.js.gz   ofstd_tests.js.gz  storescu.js.gz
dcm2pnm.js      dcmdata_tests.js     dcmftest.js     dcmmklut.js         dcmpschk.js     dcmqrscp.js        dcmsend.js         drttest.js      findscu.js      pdf2dcm.js         termscu.js
dcm2pnm.js.gz   dcmdata_tests.js.gz  dcmftest.js.gz  dcmmklut.js.gz      dcmpschk.js.gz  dcmqrscp.js.gz     dcmsend.js.gz      drttest.js.gz   findscu.js.gz   pdf2dcm.js.gz      termscu.js.gz
dcm2xml.js      dcmdjpeg.js          dcmgpdir.js     dcmnet_tests.js     dcmpsmk.js      dcmqrti.js         dcmsign.js         dsr2html.js     getscu.js       preplock.js        wlmscpfs.js
dcm2xml.js.gz   dcmdjpeg.js.gz       dcmgpdir.js.gz  dcmnet_tests.js.gz  dcmpsmk.js.gz   dcmqrti.js.gz      dcmsign.js.gz      dsr2html.js.gz  getscu.js.gz    preplock.js.gz     wlmscpfs.js.gz
dcmcjpeg.js     dcmdjpls.js          dcmj2pnm.js     dcmodify.js         dcmpsprt.js     dcmquant.js        dcmsr_tests.js     dsr2xml.js      img2dcm.js      readoviw.js        writwlst.js
dcmcjpeg.js.gz  dcmdjpls.js.gz       dcmj2pnm.js.gz  dcmodify.js.gz      dcmpsprt.js.gz  dcmquant.js.gz     dcmsr_tests.js.gz  dsr2xml.js.gz   img2dcm.js.gz   readoviw.js.gz     writwlst.js.gz
dcmcjpls.js     dcmdrle.js           dcml2pnm.js     dcmp2pgm.js         dcmpsrcv.js     dcmrecv.js         dcod2lum.js        dsrdump.js      mkreport.js     readwlst.js        xml2dcm.js
dcmcjpls.js.gz  dcmdrle.js.gz        dcml2pnm.js.gz  dcmp2pgm.js.gz      dcmpsrcv.js.gz  dcmrecv.js.gz      dcod2lum.js.gz     dsrdump.js.gz   mkreport.js.gz  readwlst.js.gz     xml2dcm.js.gz
dcmconv.js      dcmdspfn.js          dcmmkcrv.js     dcmprscp.js         dcmpssnd.js     dcmrt_tests.js     dconvlum.js        dump2dcm.js     movescu.js      storescp.js        xml2dsr.js
dcmconv.js.gz   dcmdspfn.js.gz       dcmmkcrv.js.gz  dcmprscp.js.gz      dcmpssnd.js.gz  dcmrt_tests.js.gz  dconvlum.js.gz     dump2dcm.js.gz  movescu.js.gz   storescp.js.gz     xml2dsr.js.gz
```



