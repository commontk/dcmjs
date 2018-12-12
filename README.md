dcmjs
=====

[![CircleCI](https://circleci.com/gh/commontk/dcmjs.svg?style=svg)](https://circleci.com/gh/commontk/dcmjs)

Overview
--------

dcmjs is a javascript cross-compilation of dcmtk (dcmtk.org) for use
in a javascript environment.  Uses emscripten.

See                  [http://dcmjs.org](http://dcmjs.org)

See License.txt for information on using and contributing.

This package is intended for use in browser environments.  For server side use probably you want to call to the corresponding natively compiled dcmtk executables.

<table>
<tr><td>To see javascript that uses <code>dcmjs.js</code> see the
<code>gh-pages</code> branch of
<a href="https://github.com/commontk/dcmjs.org/tree/gh-pages">commontk/dcmjs.org</a> repository
which is what hosts dcmjs.org.</td></tr>
</table>

Usage
-----

The module `dcmjs.js` allows to selectively execute a dcmtk application.

* To list available application:

```
$ nodejs dcmjs.js list
dcm2pnm
dcmdump
dcm2xml
dcmftest
```


* To execute an application:

```
$ nodejs dcmjs.js dcmdump
$dcmtk: dcmdump v3.6.1 DEV $

dcmdump: Dump DICOM file and data set
usage: dcmdump [options] dcmfile-in...

parameters:
  dcmfile-in                    DICOM input file or directory to be dumped
[...]
```

* Note that node executables do not have access to the local file system.  To use dcmjs on a browser see the demos in the gh-pages branch.

Prerequisites
-------------

* Install Git: http://git-scm.com/downloads

* Install Docker: https://docs.docker.com/engine/installation/

* Install `dockcross-browser-asmjs`:

```
docker pull dockcross/browser-asmjs
docker run dockcross/browser-asmjs > ~/bin/dockcross-browser-asmjs
chmod u+x ~/bin/dockcross-browser-asmjs
```

For more details, see https://github.com/dockcross/dockcross#readme


Building
--------

The following commands will checkout dcmjs project and build `dcmjs.js` using `dockcross-browser-asmjs`.

```
git clone git://github.com/commontk/dcmjs
cd dcmjs
dockcross-browser-asmjs cmake -Bdcmjs-build -H. -GNinja
dockcross-browser-asmjs ninja -Cdcmjs-build
```

When done, you will have the files `dcmjs.js` and `dcmjs.js.gz` in the `dcmjs-build/dcmjs-build/bin` folder:

```
$ ls -1 dcmjs-build/dcmjs-build/bin/
dcmjs.js
dcmjs.js.gz
```

Add / Remove applications
-------------------------

Re-configuring the project setting any of these options allows to customize the
list of applications bundled in the `dcmjs.js` module:

* [dcm2pdf](http://support.dcmtk.org/docs/dcm2pdf.html): `-DCMTK_APP_DCM2PDF:BOOL=[ON|OFF]`
* [dcm2pnm](http://support.dcmtk.org/docs/dcm2pnm.html): `-DCMTK_APP_DCM2PNM:BOOL=[ON|OFF]`
* [dcm2xml](http://support.dcmtk.org/docs/dcm2xml.html): `-DCMTK_APP_DCM2XML:BOOL=[ON|OFF]`
* [dcmcjpeg](http://support.dcmtk.org/docs/dcmcjpeg.html): `-DCMTK_APP_DCMCJPEG:BOOL=[ON|OFF]`
* [dcmcjpls](http://support.dcmtk.org/docs/dcmcjpls.html): `-DCMTK_APP_DCMCJPLS:BOOL=[ON|OFF]`
* [dcmconv](http://support.dcmtk.org/docs/dcmconv.html): `-DCMTK_APP_DCMCONV:BOOL=[ON|OFF]`
* [dcmcrle](http://support.dcmtk.org/docs/dcmcrle.html): `-DCMTK_APP_DCMCRLE:BOOL=[ON|OFF]`
* [dcmdjpeg](http://support.dcmtk.org/docs/dcmdjpeg.html): `-DCMTK_APP_DCMDJPEG:BOOL=[ON|OFF]`
* [dcmdjpls](http://support.dcmtk.org/docs/dcmdjpls.html): `-DCMTK_APP_DCMDJPLS:BOOL=[ON|OFF]`
* [dcmdrle](http://support.dcmtk.org/docs/dcmdrle.html): `-DCMTK_APP_DCMDRLE:BOOL=[ON|OFF]`
* [dcmdspfn](http://support.dcmtk.org/docs/dcmdspfn.html): `-DCMTK_APP_DCMDSPFN:BOOL=[ON|OFF]`
* [dcmdump](http://support.dcmtk.org/docs/dcmdump.html): `-DCMTK_APP_DCMDUMP:BOOL=[ON|OFF]`
* [dcmftest](http://support.dcmtk.org/docs/dcmftest.html): `-DCMTK_APP_DCMFTEST:BOOL=[ON|OFF]`
* [dcmgpdir](http://support.dcmtk.org/docs/dcmgpdir.html): `-DCMTK_APP_DCMGPDIR:BOOL=[ON|OFF]`
* [dcmj2pnm](http://support.dcmtk.org/docs/dcmj2pnm.html): `-DCMTK_APP_DCMJ2PNM:BOOL=[ON|OFF]`
* [dcml2pnm](http://support.dcmtk.org/docs/dcml2pnm.html): `-DCMTK_APP_DCML2PNM:BOOL=[ON|OFF]`
* [dcmmkcrv](http://support.dcmtk.org/docs/dcmmkcrv.html): `-DCMTK_APP_DCMMKCRV:BOOL=[ON|OFF]`
* [dcmmkdir](http://support.dcmtk.org/docs/dcmmkdir.html): `-DCMTK_APP_DCMMKDIR:BOOL=[ON|OFF]`
* [dcmmklut](http://support.dcmtk.org/docs/dcmmklut.html): `-DCMTK_APP_DCMMKLUT:BOOL=[ON|OFF]`
* [dcmodify](http://support.dcmtk.org/docs/dcmodify.html): `-DCMTK_APP_DCMODIFY:BOOL=[ON|OFF]`
* [dcmp2pgm](http://support.dcmtk.org/docs/dcmp2pgm.html): `-DCMTK_APP_DCMP2PGM:BOOL=[ON|OFF]`
* [dcmprscp](http://support.dcmtk.org/docs/dcmprscp.html): `-DCMTK_APP_DCMPRSCP:BOOL=[ON|OFF]`
* [dcmprscu](http://support.dcmtk.org/docs/dcmprscu.html): `-DCMTK_APP_DCMPRSCU:BOOL=[ON|OFF]`
* [dcmpschk](http://support.dcmtk.org/docs/dcmpschk.html): `-DCMTK_APP_DCMPSCHK:BOOL=[ON|OFF]`
* [dcmpsmk](http://support.dcmtk.org/docs/dcmpsmk.html): `-DCMTK_APP_DCMPSMK:BOOL=[ON|OFF]`
* [dcmpsprt](http://support.dcmtk.org/docs/dcmpsprt.html): `-DCMTK_APP_DCMPSPRT:BOOL=[ON|OFF]`
* [dcmpsrcv](http://support.dcmtk.org/docs/dcmpsrcv.html): `-DCMTK_APP_DCMPSRCV:BOOL=[ON|OFF]`
* [dcmpssnd](http://support.dcmtk.org/docs/dcmpssnd.html): `-DCMTK_APP_DCMPSSND:BOOL=[ON|OFF]`
* [dcmqridx](http://support.dcmtk.org/docs/dcmqridx.html): `-DCMTK_APP_DCMQRIDX:BOOL=[ON|OFF]`
* [dcmqrscp](http://support.dcmtk.org/docs/dcmqrscp.html): `-DCMTK_APP_DCMQRSCP:BOOL=[ON|OFF]`
* [dcmqrti](http://support.dcmtk.org/docs/dcmqrti.html): `-DCMTK_APP_DCMQRTI:BOOL=[ON|OFF]`
* [dcmquant](http://support.dcmtk.org/docs/dcmquant.html): `-DCMTK_APP_DCMQUANT:BOOL=[ON|OFF]`
* [dcmrecv](http://support.dcmtk.org/docs/dcmrecv.html): `-DCMTK_APP_DCMRECV:BOOL=[ON|OFF]`
* [dcmscale](http://support.dcmtk.org/docs/dcmscale.html): `-DCMTK_APP_DCMSCALE:BOOL=[ON|OFF]`
* [dcmsend](http://support.dcmtk.org/docs/dcmsend.html): `-DCMTK_APP_DCMSEND:BOOL=[ON|OFF]`
* [dcmsign](http://support.dcmtk.org/docs/dcmsign.html): `-DCMTK_APP_DCMSIGN:BOOL=[ON|OFF]`
* [dcod2lum](http://support.dcmtk.org/docs/dcod2lum.html): `-DCMTK_APP_DCOD2LUM:BOOL=[ON|OFF]`
* [dconvlum](http://support.dcmtk.org/docs/dconvlum.html): `-DCMTK_APP_DCONVLUM:BOOL=[ON|OFF]`
* [drtdump](http://support.dcmtk.org/docs/drtdump.html): `-DCMTK_APP_DRTDUMP:BOOL=[ON|OFF]`
* [dsr2html](http://support.dcmtk.org/docs/dsr2html.html): `-DCMTK_APP_DSR2HTML:BOOL=[ON|OFF]`
* [dsr2xml](http://support.dcmtk.org/docs/dsr2xml.html): `-DCMTK_APP_DSR2XML:BOOL=[ON|OFF]`
* [dsrdump](http://support.dcmtk.org/docs/dsrdump.html): `-DCMTK_APP_DSRDUMP:BOOL=[ON|OFF]`
* [dump2dcm](http://support.dcmtk.org/docs/dump2dcm.html): `-DCMTK_APP_DUMP2DCM:BOOL=[ON|OFF]`
* [echoscu](http://support.dcmtk.org/docs/echoscu.html): `-DCMTK_APP_ECHOSCU:BOOL=[ON|OFF]`
* [findscu](http://support.dcmtk.org/docs/findscu.html): `-DCMTK_APP_FINDSCU:BOOL=[ON|OFF]`
* [getscu](http://support.dcmtk.org/docs/getscu.html): `-DCMTK_APP_GETSCU:BOOL=[ON|OFF]`
* [img2dcm](http://support.dcmtk.org/docs/img2dcm.html): `-DCMTK_APP_IMG2DCM:BOOL=[ON|OFF]`
* [mdfconen](http://support.dcmtk.org/docs/mdfconen.html): `-DCMTK_APP_MDFCONEN:BOOL=[ON|OFF]`
* [mdfdsman](http://support.dcmtk.org/docs/mdfdsman.html): `-DCMTK_APP_MDFDSMAN:BOOL=[ON|OFF]`
* [movescu](http://support.dcmtk.org/docs/movescu.html): `-DCMTK_APP_MOVESCU:BOOL=[ON|OFF]`
* [pdf2dcm](http://support.dcmtk.org/docs/pdf2dcm.html): `-DCMTK_APP_PDF2DCM:BOOL=[ON|OFF]`
* [preplock](http://support.dcmtk.org/docs/preplock.html): `-DCMTK_APP_PREPLOCK:BOOL=[ON|OFF]`
* [readoviw](http://support.dcmtk.org/docs/readoviw.html): `-DCMTK_APP_READOVIW:BOOL=[ON|OFF]`
* [readwlst](http://support.dcmtk.org/docs/readwlst.html): `-DCMTK_APP_READWLST:BOOL=[ON|OFF]`
* [storescp](http://support.dcmtk.org/docs/storescp.html): `-DCMTK_APP_STORESCP:BOOL=[ON|OFF]`
* [storescu](http://support.dcmtk.org/docs/storescu.html): `-DCMTK_APP_STORESCU:BOOL=[ON|OFF]`
* [termscu](http://support.dcmtk.org/docs/termscu.html): `-DCMTK_APP_TERMSCU:BOOL=[ON|OFF]`
* [wlcefs](http://support.dcmtk.org/docs/wlcefs.html): `-DCMTK_APP_WLCEFS:BOOL=[ON|OFF]`
* [wlmscpfs](http://support.dcmtk.org/docs/wlmscpfs.html): `-DCMTK_APP_WLMSCPFS:BOOL=[ON|OFF]`
* [writwlst](http://support.dcmtk.org/docs/writwlst.html): `-DCMTK_APP_WRITWLST:BOOL=[ON|OFF]`
* [xml2dcm](http://support.dcmtk.org/docs/xml2dcm.html): `-DCMTK_APP_XML2DCM:BOOL=[ON|OFF]`
* [xml2dsr](http://support.dcmtk.org/docs/xml2dsr.html): `-DCMTK_APP_XML2DSR:BOOL=[ON|OFF]`

The list above has been generated using:
```
cd DCMTK
for file in `find -wholename *apps/*.cc`; do
  appname=$( basename ${file%.*} );
  echo -e "* [${appname}](http://support.dcmtk.org/docs/${appname}.html): \`-DCMTK_APP_${appname^^}:BOOL=[ON|OFF]\`";
done | sort
```

List of options found in [CMake/Externals/External_DCMTK.cmake](https://github.com/commontk/dcmjs/blob/master/CMake/Externals/External_DCMTK.cmake) can be generated using:

```
cd DCMTK
for file in `find -wholename *apps/*.cc`; do
  appname=$( basename ${file%.*} );
  echo -e "      -DBUILD_${appname}_APP:BOOL=OFF";
done | sort
```
