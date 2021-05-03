'use strict';

var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Js_json = require("bs-platform/lib/js/js_json.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");

var SecurityLevel = {};

var Accessible = {};

var AccessControl = {};

var AuthenticationType = {};

var BiometryType = {};

function decodeGetGenericPasswordResult(result) {
  var dict = Js_json.classify(result);
  if (typeof dict === "number") {
    return ;
  }
  if (dict.TAG !== /* JSONObject */2) {
    return ;
  }
  var dict$1 = dict._0;
  var match = Belt_Option.map(Js_dict.get(dict$1, "service"), Js_json.classify);
  var match$1 = Belt_Option.map(Js_dict.get(dict$1, "username"), Js_json.classify);
  var match$2 = Belt_Option.map(Js_dict.get(dict$1, "password"), Js_json.classify);
  if (match !== undefined && !(typeof match === "number" || !(match.TAG === /* JSONString */0 && match$1 !== undefined && !(typeof match$1 === "number" || !(match$1.TAG === /* JSONString */0 && match$2 !== undefined && !(typeof match$2 === "number" || match$2.TAG !== /* JSONString */0)))))) {
    return {
            service: match._0,
            username: match$1._0,
            password: match$2._0
          };
  }
  
}

exports.SecurityLevel = SecurityLevel;
exports.Accessible = Accessible;
exports.AccessControl = AccessControl;
exports.AuthenticationType = AuthenticationType;
exports.BiometryType = BiometryType;
exports.decodeGetGenericPasswordResult = decodeGetGenericPasswordResult;
/* No side effect */
