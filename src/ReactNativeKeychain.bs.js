'use strict';

var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Js_json = require("bs-platform/lib/js/js_json.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");

var SecurityLevel = { };

var Accessible = { };

var AccessControl = { };

var AuthenticationType = { };

var BiometryType = { };

function decodeGetGenericPasswordResult(result) {
  var match = Js_json.classify(result);
  if (typeof match === "number" || match.tag !== /* JSONObject */2) {
    return ;
  } else {
    var dict = match[0];
    var match$1 = Belt_Option.map(Js_dict.get(dict, "service"), Js_json.classify);
    var match$2 = Belt_Option.map(Js_dict.get(dict, "username"), Js_json.classify);
    var match$3 = Belt_Option.map(Js_dict.get(dict, "password"), Js_json.classify);
    if (match$1 !== undefined) {
      var match$4 = match$1;
      if (typeof match$4 === "number" || match$4.tag || match$2 === undefined) {
        return ;
      } else {
        var match$5 = match$2;
        if (typeof match$5 === "number" || match$5.tag || match$3 === undefined) {
          return ;
        } else {
          var match$6 = match$3;
          if (typeof match$6 === "number" || match$6.tag) {
            return ;
          } else {
            return /* record */[
                    /* service */match$4[0],
                    /* username */match$5[0],
                    /* password */match$6[0]
                  ];
          }
        }
      }
    } else {
      return ;
    }
  }
}

exports.SecurityLevel = SecurityLevel;
exports.Accessible = Accessible;
exports.AccessControl = AccessControl;
exports.AuthenticationType = AuthenticationType;
exports.BiometryType = BiometryType;
exports.decodeGetGenericPasswordResult = decodeGetGenericPasswordResult;
/* No side effect */
