var dcmjs = dcmjs || {};
dcmjs.utils = dcmjs.utils || {};

/*
  Read the file and invoke processor function
*/
dcmjs.utils.readFile = function(file, processor) {
  var reader = new FileReader();

  // Closure to capture the file information.
  reader.onload = (function(file) {
    return function(e) { processor(reader, file) };
  })(file);
  //var blob = new Blob([typedArray], {type: 'application/octet-binary'});
  // Read in the image file
  reader.readAsArrayBuffer(file);
}

dcmjs.utils.displayFileProperties = function(files) {
  // files is a FileList of File objects. List some properties.
  var output = [];
  $.each(files, function(index,file) {
    output.push('<li><strong>', escape(file.name), '</strong> (', file.type || 'n/a', ') - ',
                file.size, ' bytes, last modified: ',
                file.lastModifiedDate ? file.lastModifiedDate.toLocaleDateString() : 'n/a',
                '</li>');
  })
  $('#fileListProperties').innerHTML = '<ul>' + output.join('') + '</ul>';
}

$(function() {
  /*
    File management
        http://www.html5rocks.com/en/tutorials/file/dndfiles/
  */
  // Check for the various File API support.
  if (window.File && window.FileReader && window.FileList && window.Blob) {
    // Great success! All the File APIs are supported.
    //console.log('The File APIs ARE fully supported in this browser.');
  } else {
    alert('The File APIs are not fully supported in this browser.');
  }
})
