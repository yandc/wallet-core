#!/bin/sh

if [ "$OS" = "ios" ]; then
    CLANG=`xcrun --sdk iphoneos --find clang`
    AR=`xcrun --sdk iphoneos --find ar`
    if [ "$ARCH" = "x86_64" ]; then
        SDK_PATH=`xcrun --sdk iphonesimulator --show-sdk-path`
    elif [ "$ARCH" = "m1sim" ]; then
        SDK_PATH=`xcrun --sdk iphonesimulator --show-sdk-path`
        ARCH="arm64"
    elif [ "$ARCH" = "arm64" ]; then
        SDK_PATH=`xcrun --sdk iphoneos --show-sdk-path`
    fi
    exec $CLANG -arch $ARCH -isysroot $SDK_PATH -mios-version-min=10.0 -D_LIBCPP_DISABLE_AVAILABILITY "$@"

elif [ "$OS" = "android" ]; then
    ANDROID_SDK=$HOME/Library/Android/sdk
    NDK_BIN=$ANDROID_SDK/ndk/24.0.8215888/toolchains/llvm/prebuilt/darwin-x86_64/bin
    if [ "$ARCH" = "armv7a" ]; then
        CLANG=$NDK_BIN/armv7a-linux-androideabi21-clang
    elif [ "$ARCH" = "arm64" ]; then
        CLANG=$NDK_BIN/aarch64-linux-android21-clang
    elif [ "$ARCH" = "x86" ]; then
        CLANG=$NDK_BIN/i686-linux-android21-clang
    elif [ "$ARCH" = "x86_64" ]; then
        CLANG=$NDK_BIN/x86_64-linux-android21-clang
    fi
    exec $CLANG -v "$@"

elif [ "$OS" = "web" ]; then
    if [[ $@ =~ rcs ]]; then
        exec emar "$@"
    else
        exec emcc "$@"
    fi
elif [ "$OS" = "linux" ]; then
    exec clang-12 "$@"
fi