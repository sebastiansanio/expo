---
title: React Native version mismatch error
---

When developing a React Native app, it's not uncommon to run into an error that looks like:

```
React Native version mismatch.

Javascript version: X.XX.X
Native version: X.XX.X

Make sure you have rebuilt the native code...
```

## What this error means

The packager that you're running in your terminal (either with `expo start` or `react-native start`) is using a different version of `react-native` than the app on your device or emulator. This can happen after upgrading your React Native or Expo SDK version, _or_ when connecting to the wrong local packager instance.

## How to fix it

- Close out any packagers you have running (you can list all terminal processes with the `ps` command, and search for Expo CLI or React Native CLI processes with `ps -A | grep "expo\|react-native"`).

- If this is a managed workflow project, either remove the `sdkVersion` field from your `app.json` file, or make sure it matches the value of the `expo` dependency in your `package.json` file.

- If this is a managed workflow project, you should make sure your `react-native` version is correct. Run `expo upgrade` and follow the prompts. Expo CLI will make sure that your dependency versions for packages like `expo` and `react-native` are aligned. Your `react-native` version should be pointing to a `.tar.gz` file that has your SDK version in it, something like `https://github.com/expo/react-native/archive/sdk-XX.X.X.tar.gz`.

- If this is a bare workflow project, and this error is occurring right after upgrading your React Native version, you should double-check that you've performed each of the upgrade steps correctly.

- Finally:
  - Clear your cache by running `rm -rf node_modules && yarn cache clean && yarn && watchman watch-del-all && rm -rf $TMPDIR/react-native-packager-cache-* && rm -rf $TMPDIR/metro-bundler-cache-* && expo start -c`
     - Commands if you are using NPM can be found [here.](clear-cache-osx-linux)
     - Commands if you are using Windows can be found [here.](clear-cache-windows)
  - If this is a bare workflow app, run `npx pod-install`, then rebuild your native projects (run `yarn android` to rebuild for Android, and `yarn ios` to rebuild iOS)
