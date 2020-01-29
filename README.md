# `@reason-react-native/keychain`

[![Build Status](https://github.com/reason-react-native/keychain/workflows/Build/badge.svg)](https://github.com/reason-react-native/keychain/actions)
[![Version](https://img.shields.io/npm/v/@reason-react-native/keychain.svg)](https://www.npmjs.com/@reason-react-native/keychain)
[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reason-react-native.github.io/discord/)

[ReasonML](https://reasonml.github.io) /
[BuckleScript](https://bucklescript.github.io) bindings for
[`react-native-keychain`](https://github.com/oblador/react-native-keychain).

Exposed as `ReactNativeSomething` module.

`@reason-react-native/keychain` X.y._ means it's compatible with
`react-native-keychain` X.y._

## Installation

When [`react-native-keychain`](https://github.com/oblador/react-native-keychain)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @reason-react-native/keychain
# or
yarn add @reason-react-native/keychain
```

`@reason-react-native/keychain` should be added to `bs-dependencies` in your
`bsconfig.json`. Something like

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/keychain"
  ],
  //...
}
```

## Usage

@todo

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/reason-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/reason-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
