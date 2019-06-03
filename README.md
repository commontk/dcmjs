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
$ node dcmjs.js list
dcm2pnm
dcmdump
dcm2xml
dcmftest
```


* To execute an application:

```
$ node dcmjs.js dcmdump
$dcmtk: dcmdump v3.6.1 DEV $

dcmdump: Dump DICOM file and data set
usage: dcmdump [options] dcmfile-in...

parameters:
  dcmfile-in                    DICOM input file or directory to be dumped
[...]
```

* Notes:

  * Node executables can access the local file system. Read [here](#file-io-using-node) for more details.

  * To use dcmjs on a browser see the demos at http://dcmjs.org/

  * To learn how to use dcmjs from javascript, see [javascripts/utils.js](https://github.com/commontk/dcmjs.org/blob/gh-pages/javascripts/utils.js#L64-L66) and [dump/index.html](https://github.com/commontk/dcmjs.org/blob/gh-pages/dump/index.html#L18-L39)


Prerequisites
-------------

* Install Git: http://git-scm.com/downloads

* Install Docker: https://docs.docker.com/engine/installation/

* Install `dockcross-web-wasm`:

```
docker pull dockcross/web-wasm
docker run dockcross/web-wasm > ~/bin/dockcross-web-wasm
chmod u+x ~/bin/dockcross-web-wasm
```

For more details, see https://github.com/dockcross/dockcross#readme


Building
--------

The following commands will checkout dcmjs project and build `dcmjs.js` using `dockcross-web-wasm`.

```
git clone git://github.com/commontk/dcmjs
cd dcmjs
dockcross-web-wasm cmake -Bdcmjs-build -H. -GNinja
dockcross-web-wasm ninja -Cdcmjs-build
```

When done, you will have the files `dcmjs.js` and `dcmjs.js.gz` in the `dcmjs-build/dcmjs-build/bin` folder:

```
$ ls -1 dcmjs-build/dcmjs-build/bin/
dcmjs.js
dcmjs.js.gz
```

File IO using node
------------------

To support using the javascript module with node, the current folder is mounted as `/working`. This
means that input files must be in in the current directory or a sub-directory.

For example, assuming we have the these files:

```
/home/awesome/downloads/dcmjs.js
/tmp/data/sr.dcm
```

The following is expected to work:

```
cd /tmp
node /home/awesome/downloads/dcmjs.js dsr2xml /working/data/sr.dcm
```

Add / Remove applications
-------------------------

Re-configuring the project setting any of these options allows to customize the
list of applications bundled in the `dcmjs.js` module:

* [cda2dcm](http://support.dcmtk.org/docs/cda2dcm.html): `-DBUILD_cda2dcm_APP:BOOL=[ON|OFF]`
* [dcm2json](http://support.dcmtk.org/docs/dcm2json.html): `-DBUILD_dcm2json_APP:BOOL=[ON|OFF]`
* [dcm2pdf](http://support.dcmtk.org/docs/dcm2pdf.html): `-DBUILD_dcm2pdf_APP:BOOL=[ON|OFF]`
* [dcm2pnm](http://support.dcmtk.org/docs/dcm2pnm.html): `-DBUILD_dcm2pnm_APP:BOOL=[ON|OFF]`
* [dcm2xml](http://support.dcmtk.org/docs/dcm2xml.html): `-DBUILD_dcm2xml_APP:BOOL=[ON|OFF]`
* [dcmcjpeg](http://support.dcmtk.org/docs/dcmcjpeg.html): `-DBUILD_dcmcjpeg_APP:BOOL=[ON|OFF]`
* [dcmcjpls](http://support.dcmtk.org/docs/dcmcjpls.html): `-DBUILD_dcmcjpls_APP:BOOL=[ON|OFF]`
* [dcmconv](http://support.dcmtk.org/docs/dcmconv.html): `-DBUILD_dcmconv_APP:BOOL=[ON|OFF]`
* [dcmcrle](http://support.dcmtk.org/docs/dcmcrle.html): `-DBUILD_dcmcrle_APP:BOOL=[ON|OFF]`
* [dcmdjpeg](http://support.dcmtk.org/docs/dcmdjpeg.html): `-DBUILD_dcmdjpeg_APP:BOOL=[ON|OFF]`
* [dcmdjpls](http://support.dcmtk.org/docs/dcmdjpls.html): `-DBUILD_dcmdjpls_APP:BOOL=[ON|OFF]`
* [dcmdrle](http://support.dcmtk.org/docs/dcmdrle.html): `-DBUILD_dcmdrle_APP:BOOL=[ON|OFF]`
* [dcmdspfn](http://support.dcmtk.org/docs/dcmdspfn.html): `-DBUILD_dcmdspfn_APP:BOOL=[ON|OFF]`
* [dcmdump](http://support.dcmtk.org/docs/dcmdump.html): `-DBUILD_dcmdump_APP:BOOL=[ON|OFF]`
* [dcmftest](http://support.dcmtk.org/docs/dcmftest.html): `-DBUILD_dcmftest_APP:BOOL=[ON|OFF]`
* [dcmgpdir](http://support.dcmtk.org/docs/dcmgpdir.html): `-DBUILD_dcmgpdir_APP:BOOL=[ON|OFF]`
* [dcmicmp](http://support.dcmtk.org/docs/dcmicmp.html): `-DBUILD_dcmicmp_APP:BOOL=[ON|OFF]`
* [dcmj2pnm](http://support.dcmtk.org/docs/dcmj2pnm.html): `-DBUILD_dcmj2pnm_APP:BOOL=[ON|OFF]`
* [dcml2pnm](http://support.dcmtk.org/docs/dcml2pnm.html): `-DBUILD_dcml2pnm_APP:BOOL=[ON|OFF]`
* [dcmmkcrv](http://support.dcmtk.org/docs/dcmmkcrv.html): `-DBUILD_dcmmkcrv_APP:BOOL=[ON|OFF]`
* [dcmmkdir](http://support.dcmtk.org/docs/dcmmkdir.html): `-DBUILD_dcmmkdir_APP:BOOL=[ON|OFF]`
* [dcmmklut](http://support.dcmtk.org/docs/dcmmklut.html): `-DBUILD_dcmmklut_APP:BOOL=[ON|OFF]`
* [dcmodify](http://support.dcmtk.org/docs/dcmodify.html): `-DBUILD_dcmodify_APP:BOOL=[ON|OFF]`
* [dcmp2pgm](http://support.dcmtk.org/docs/dcmp2pgm.html): `-DBUILD_dcmp2pgm_APP:BOOL=[ON|OFF]`
* [dcmprscp](http://support.dcmtk.org/docs/dcmprscp.html): `-DBUILD_dcmprscp_APP:BOOL=[ON|OFF]`
* [dcmprscu](http://support.dcmtk.org/docs/dcmprscu.html): `-DBUILD_dcmprscu_APP:BOOL=[ON|OFF]`
* [dcmpschk](http://support.dcmtk.org/docs/dcmpschk.html): `-DBUILD_dcmpschk_APP:BOOL=[ON|OFF]`
* [dcmpsmk](http://support.dcmtk.org/docs/dcmpsmk.html): `-DBUILD_dcmpsmk_APP:BOOL=[ON|OFF]`
* [dcmpsprt](http://support.dcmtk.org/docs/dcmpsprt.html): `-DBUILD_dcmpsprt_APP:BOOL=[ON|OFF]`
* [dcmpsrcv](http://support.dcmtk.org/docs/dcmpsrcv.html): `-DBUILD_dcmpsrcv_APP:BOOL=[ON|OFF]`
* [dcmpssnd](http://support.dcmtk.org/docs/dcmpssnd.html): `-DBUILD_dcmpssnd_APP:BOOL=[ON|OFF]`
* [dcmqridx](http://support.dcmtk.org/docs/dcmqridx.html): `-DBUILD_dcmqridx_APP:BOOL=[ON|OFF]`
* [dcmqrscp](http://support.dcmtk.org/docs/dcmqrscp.html): `-DBUILD_dcmqrscp_APP:BOOL=[ON|OFF]`
* [dcmqrti](http://support.dcmtk.org/docs/dcmqrti.html): `-DBUILD_dcmqrti_APP:BOOL=[ON|OFF]`
* [dcmquant](http://support.dcmtk.org/docs/dcmquant.html): `-DBUILD_dcmquant_APP:BOOL=[ON|OFF]`
* [dcmrecv](http://support.dcmtk.org/docs/dcmrecv.html): `-DBUILD_dcmrecv_APP:BOOL=[ON|OFF]`
* [dcmscale](http://support.dcmtk.org/docs/dcmscale.html): `-DBUILD_dcmscale_APP:BOOL=[ON|OFF]`
* [dcmsend](http://support.dcmtk.org/docs/dcmsend.html): `-DBUILD_dcmsend_APP:BOOL=[ON|OFF]`
* [dcmsign](http://support.dcmtk.org/docs/dcmsign.html): `-DBUILD_dcmsign_APP:BOOL=[ON|OFF]`
* [dcod2lum](http://support.dcmtk.org/docs/dcod2lum.html): `-DBUILD_dcod2lum_APP:BOOL=[ON|OFF]`
* [dconvlum](http://support.dcmtk.org/docs/dconvlum.html): `-DBUILD_dconvlum_APP:BOOL=[ON|OFF]`
* [drtdump](http://support.dcmtk.org/docs/drtdump.html): `-DBUILD_drtdump_APP:BOOL=[ON|OFF]`
* [dsr2html](http://support.dcmtk.org/docs/dsr2html.html): `-DBUILD_dsr2html_APP:BOOL=[ON|OFF]`
* [dsr2xml](http://support.dcmtk.org/docs/dsr2xml.html): `-DBUILD_dsr2xml_APP:BOOL=[ON|OFF]`
* [dsrdump](http://support.dcmtk.org/docs/dsrdump.html): `-DBUILD_dsrdump_APP:BOOL=[ON|OFF]`
* [dump2dcm](http://support.dcmtk.org/docs/dump2dcm.html): `-DBUILD_dump2dcm_APP:BOOL=[ON|OFF]`
* [echoscu](http://support.dcmtk.org/docs/echoscu.html): `-DBUILD_echoscu_APP:BOOL=[ON|OFF]`
* [findscu](http://support.dcmtk.org/docs/findscu.html): `-DBUILD_findscu_APP:BOOL=[ON|OFF]`
* [getscu](http://support.dcmtk.org/docs/getscu.html): `-DBUILD_getscu_APP:BOOL=[ON|OFF]`
* [img2dcm](http://support.dcmtk.org/docs/img2dcm.html): `-DBUILD_img2dcm_APP:BOOL=[ON|OFF]`
* [mdfconen](http://support.dcmtk.org/docs/mdfconen.html): `-DBUILD_mdfconen_APP:BOOL=[ON|OFF]`
* [mdfdsman](http://support.dcmtk.org/docs/mdfdsman.html): `-DBUILD_mdfdsman_APP:BOOL=[ON|OFF]`
* [movescu](http://support.dcmtk.org/docs/movescu.html): `-DBUILD_movescu_APP:BOOL=[ON|OFF]`
* [pdf2dcm](http://support.dcmtk.org/docs/pdf2dcm.html): `-DBUILD_pdf2dcm_APP:BOOL=[ON|OFF]`
* [stl2dcm](http://support.dcmtk.org/docs/stl2dcm.html): `-DBUILD_stl2dcm_APP:BOOL=[ON|OFF]`
* [storescp](http://support.dcmtk.org/docs/storescp.html): `-DBUILD_storescp_APP:BOOL=[ON|OFF]`
* [storescu](http://support.dcmtk.org/docs/storescu.html): `-DBUILD_storescu_APP:BOOL=[ON|OFF]`
* [termscu](http://support.dcmtk.org/docs/termscu.html): `-DBUILD_termscu_APP:BOOL=[ON|OFF]`
* [wlcefs](http://support.dcmtk.org/docs/wlcefs.html): `-DBUILD_wlcefs_APP:BOOL=[ON|OFF]`
* [wlmscpfs](http://support.dcmtk.org/docs/wlmscpfs.html): `-DBUILD_wlmscpfs_APP:BOOL=[ON|OFF]`
* [xml2dcm](http://support.dcmtk.org/docs/xml2dcm.html): `-DBUILD_xml2dcm_APP:BOOL=[ON|OFF]`
* [xml2dsr](http://support.dcmtk.org/docs/xml2dsr.html): `-DBUILD_xml2dsr_APP:BOOL=[ON|OFF]`

The list above has been generated using:
```
cd DCMTK
for file in `find -wholename *apps/*.cc`; do
  appname=$( basename ${file%.*} );
  echo -e "* [${appname}](http://support.dcmtk.org/docs/${appname}.html): \`-DBUILD_${appname}_APP:BOOL=[ON|OFF]\`";
done | sort
```

List of options found in [CMake/Externals/External_DCMTK.cmake](https://github.com/commontk/dcmjs/blob/master/CMake/Externals/External_DCMTK.cmake) can be generated using:

```
cd DCMTK
for file in `find -wholename *apps/*.cc`; do
  appname=$( basename ${file%.*} );
  echo -e "dcmtk_build_app_option(BUILD_${appname}_APP OFF)";
done | sort | column -t
```

Creating a release
------------------

1. Choose a release name (e.g dcmjs-3.6.1)

```
release=<name-of-release>
```

2. Fetch and tag repository

```
git fetch
git tag -s -m "${release}" ${release} origin/master
```

3. Publish tag

```
git push origin ${release}
```
