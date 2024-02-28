#!/bin/sh

if [ "$OS" = "ios" ]; then
    AR=`xcrun --sdk iphoneos --find ar`
    mkdir -p build/ar_merge
    cd build/ar_merge
    rm -rf ./*
    $AR x ../../../tss-mili/build/go_mili.$OS.$ARCH.a
    cd ../..
    exec $AR -r "$@" ./build/ar_merge/*.o

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
    cp ../tss-mili/build/go_mili.$OS.$ARCH.so ./build/lib/libgo_mili.so
    exec $CLANG -v -shared -o "$@"

elif [ "$OS" = "web" ]; then
    exec emcc -o "$@"
elif [ "$OS" = "linux" ]; then
    exec clang-12 -v -shared -o "$@"
elif [ "$OS" == "macos" ]; then
    CLANG=`xcrun --sdk macosx --find clang`
    exec $CLANG -v -shared -o "$@"
fi