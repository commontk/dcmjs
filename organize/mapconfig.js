// problems:
// - clone $dicomDOM

// example setup
mapping = [
    ['anonymous', 'hey I mapped you'],
    ['', 'this was empty before']
];

var getSpecificReplacer = function(parser) {
    return {
        dicom: {
            'PatientID': function() {
                return "Mr X.";
            },
            'PatientName': function() {
                return parser.getMapTable(parser.getDicom('PatientName'), 0, 1);
            }
        },
        filePath: {
            // TODO
        }
    };
};


// (parser is created once per run)
var getParser = function($oldDicomDom, mapping) {
    return {
        getMapTable: function(matchValue, matchIndex, newIndex) {
            // var mapping = list of lists read from mappingFilePath
            var mapRow = mapping.filter(function(row) {
                return row[matchIndex] === matchValue;
            });
            if (mapRow.length) {
                return mapRow[0][newIndex];
            }
            else {
                throw("No value '" + matchValue +
                    "' found in mapping table column " + matchIndex);
            }
        },
        getFilePath: function(filePath) {
            return filePath.split(/[\/]+/);
        },
        getDicom: function(tagName) {
            return $oldDicomDom.find('[name=' + tagName + ']').text();
        }
    };
};

var specificReplace = {
    dicom: {
        'PatientName': function() {
            return "Mr X.";
        },
        'PatientID': function() {
            return parsers.mapTable(parsers.dicom('PatientID'), 0, 1);
        }
    },
    filePath: {
        // TODO
    }
};

// tag manipulation functions
// empty if present
function tagEmpty(jQDom, name) {
    jQDom.find('[name=' + name + ']').text("");
}

function tagReplace(jQDom, name, value) {
    // (ensure it's used as a setter with the || "")
    jQDom.find('[name=' + name + ']').text(value || "");
}

function hashUID(uid) {
    function hexToByte(hex) {
        var byteArr=[];
        for (i = 0; i < s.length/2; i++) {
            var vh = s[i*2];
            var vl = s[i*2 + 1];
            var h = vh.charCodeAt(0) - '0'.charCodeAt(0);
            var l = vl.charCodeAt(0) - '0'.charCodeAt(0);
            byteArr[i] = h << 4 + l;
        }
        return byteArr;
    }
    var hashUIDbytes = hexToByte(sha1(uid));

}


var applyReplaceDefaults = function($newDicomDOM, specificReplace) {
    function unlessSpecified(tagList) {
        return tagList.filter(function(tag) {
            return !(tag in specificReplace.dicom);
        });
    }
    unlessSpecified([
        'PatientName',
        'PatientID'
    ]).forEach(function(name) {
        tagEmpty(name);
    });
};

// in main func:
// read from old dicom dom and write to new dicomdom
var mapDom = function($oldDicomDOM, xmlString) {
    var $newDicomDOM = $($.parseXML(xmlString));
    // TODO: define filePath
    var filePath;
    var parser = getParser($oldDicomDOM, mappingTable, filePath);
    var specificReplace = getSpecificReplacer(parser);
    // deal with dicoms
    Object.keys(specificReplace.dicom).forEach(function(name) {
        tagReplace(name, specificReplace.dicom[name]());
    });
    Object.keys(specificReplace.filePath).forEach(function(name) {
        // TODO
    });
    applyReplaceDefaults($newDicomDOM, specificReplace);
    return $newDicomDOM;
};