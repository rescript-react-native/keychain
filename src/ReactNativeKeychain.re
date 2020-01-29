module SecurityLevel = {
  type t;

  [@bs.module "react-native-keychain"] [@bs.scope "SECURITY_LEVEL"]
  external any: t = "ANY";
  [@bs.module "react-native-keychain"] [@bs.scope "SECURITY_LEVEL"]
  external secureSoftware: t = "SECURE_SOFTWARE";
  [@bs.module "react-native-keychain"] [@bs.scope "SECURITY_LEVEL"]
  external secureHardware: t = "SECURE_HARDWARE";
};

module Accessible = {
  type t;

  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external whenUnlocked: t = "WHEN_UNLOCKED";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external afterFirstUnlock: t = "AFTER_FIRST_UNLOCK";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external always: t = "ALWAYS";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external whenPasscodeSetThisDeviceOnly: t =
    "WHEN_PASSCODE_SET_THIS_DEVICE_ONLY";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external whenUnlockedThisDeviceOnly: t = "WHEN_UNLOCKED_THIS_DEVICE_ONLY";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external afterFirstUnlockThisDeviceOnly: t =
    "AFTER_FIRST_UNLOCK_THIS_DEVICE_ONLY";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESSIBLE"]
  external alwaysThisDeviceOnly: t = "ALWAYS_THIS_DEVICE_ONLY";
};

module AccessControl = {
  type t;

  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external userPresence: t = "USER_PRESENCE";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external biometryAny: t = "BIOMETRY_ANY";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external biometryCurrentSet: t = "BIOMETRY_CURRENT_SET";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external devicePasscode: t = "DEVICE_PASSCODE";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external applicationPassword: t = "APPLICATION_PASSWORD";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external biometryAnyOrDevicePasscode: t = "BIOMETRY_ANY_OR_DEVICE_PASSCODE";
  [@bs.module "react-native-keychain"] [@bs.scope "ACCESS_CONTROL"]
  external biometryCurrentSetOrDevicePasscode: t =
    "BIOMETRY_CURRENT_SET_OR_DEVICE_PASSCODE";
};

module AuthenticationType = {
  type t;

  [@bs.module "react-native-keychain"] [@bs.scope "AUTHENTICATION_TYPE"]
  external devicePasscodeOrBiometrics: t = "DEVICE_PASSCODE_OR_BIOMETRICS";
  [@bs.module "react-native-keychain"] [@bs.scope "AUTHENTICATION_TYPE"]
  external biometrics: t = "BIOMETRICS";
};

module BiometryType = {
  type t;

  [@bs.module "react-native-keychain"] [@bs.scope "BIOMETRY_TYPE"]
  external touchId: t = "TOUCH_ID";
  [@bs.module "react-native-keychain"] [@bs.scope "BIOMETRY_TYPE"]
  external faceId: t = "FACE_ID";
  [@bs.module "react-native-keychain"] [@bs.scope "BIOMETRY_TYPE"]
  external fingerprint: t = "FINGERPRINT";
};

// getGenericPassword

type getGenericPasswordResult;

type credentials = {
  service: string,
  username: string,
  password: string,
};

let decodeGetGenericPasswordResult = (result: getGenericPasswordResult) => {
  Js.Json.(
    switch (result->Obj.magic->classify) {
    | JSONFalse => None
    | JSONObject(dict) =>
      switch (
        dict->Js.Dict.get("service")->Belt.Option.map(classify),
        dict->Js.Dict.get("username")->Belt.Option.map(classify),
        dict->Js.Dict.get("password")->Belt.Option.map(classify),
      ) {
      | (
          Some(JSONString(service)),
          Some(JSONString(username)),
          Some(JSONString(password)),
        ) =>
        Some({service, username, password})
      | _ => None // should not happen
      }
    | _ => None // should not happen
    }
  );
};

type getGenericPasswordOptions;
[@bs.obj]
external getGenericPasswordOptions:
  (~authenticationPrompt: string=?, ~service: string=?, unit) =>
  getGenericPasswordOptions =
  "";

[@bs.module "react-native-keychain"]
external getGenericPassword: unit => Js.Promise.t(getGenericPasswordResult) =
  "getGenericPassword";

[@bs.module "react-native-keychain"]
external getGenericPasswordWithService:
  string => Js.Promise.t(getGenericPasswordResult) =
  "getGenericPassword";

[@bs.module "react-native-keychain"]
external getGenericPasswordWithOptions:
  getGenericPasswordOptions => Js.Promise.t(getGenericPasswordResult) =
  "getGenericPassword";

// setGenericPassword

type setGenericPasswordOptions;
[@bs.obj]
external setGenericPasswordOptions:
  (
    ~accessControl: AccessControl.t=?,
    ~accessGroup: string=?,
    ~accessible: Accessible.t=?,
    ~service: string=?,
    ~securityLevel: SecurityLevel.t=?,
    unit
  ) =>
  setGenericPasswordOptions =
  "";

[@bs.module "react-native-keychain"]
external setGenericPassword:
  (~username: string, ~password: string) => Js.Promise.t(bool) =
  "setGenericPassword";

[@bs.module "react-native-keychain"]
external setGenericPasswordWithOptions:
  (
    ~username: string,
    ~password: string,
    ~options: setGenericPasswordOptions
  ) =>
  Js.Promise.t(bool) =
  "setGenericPassword";

[@bs.module "react-native-keychain"]
external setGenericPasswordWithService:
  (~username: string, ~password: string, ~service: string) =>
  Js.Promise.t(bool) =
  "setGenericPassword";

// resetGenericPasswordOptions

type resetGenericPasswordOptions;
[@bs.obj]
external resetGenericPasswordOptions:
  (~service: string=?, unit) => resetGenericPasswordOptions =
  "";

[@bs.module "react-native-keychain"]
external resetGenericPassword: unit => Js.Promise.t(bool) =
  "resetGenericPassword";

[@bs.module "react-native-keychain"]
external resetGenericPasswordWithOptions:
  resetGenericPasswordOptions => Js.Promise.t(bool) =
  "resetGenericPassword";

[@bs.module "react-native-keychain"]
external resetGenericPasswordWithService: string => Js.Promise.t(bool) =
  "resetGenericPassword";
