OS=web ARCH=wasm make -f Makefile_pb
OS=web ARCH=wasm make -f Makefile_trezor
OS=web ARCH=wasm make

OS=ios ARCH=arm64 make -f Makefile_pb
OS=ios ARCH=arm64 make -f Makefile_trezor
OS=ios ARCH=arm64 make

OS=ios ARCH=x86_64 make -f Makefile_pb
OS=ios ARCH=x86_64 make -f Makefile_trezor
OS=ios ARCH=x86_64 make

#OS=ios ARCH=m1sim make -f Makefile_pb
#OS=ios ARCH=m1sim make -f Makefile_trezor
#OS=ios ARCH=m1sim make

OS=android ARCH=arm64 make -f Makefile_pb
OS=android ARCH=arm64 make -f Makefile_trezor
OS=android ARCH=arm64 make

OS=android ARCH=armv7a make -f Makefile_pb
OS=android ARCH=armv7a make -f Makefile_trezor
OS=android ARCH=armv7a make

OS=android ARCH=x86 make -f Makefile_pb
OS=android ARCH=x86 make -f Makefile_trezor
OS=android ARCH=x86 make

OS=android ARCH=x86_64 make -f Makefile_pb
OS=android ARCH=x86_64 make -f Makefile_trezor
OS=android ARCH=x86_64 make