OPTIMIZE := -O2 -Wall -Wno-sign-compare -Wno-unused-function
#OPTIMIZE := -g -Wall -Wno-sign-compare -Wno-unused-function
CC := emcc
LD := emcc $(PACKAGE)

INCLUDE_FLAG = -Ibuild/local/include
INCLUDE_FLAG += -Itrezor-crypto/include
INCLUDE_FLAG += -Itrezor-crypto/src
INCLUDE_FLAG += -Iinclude -Isrc -I/opt/homebrew/Cellar/boost/1.76.0/include/

CFLAGS = -std=c++17 $(OPTIMIZE)
CFLAGS += -fexceptions
CFLAGS += $(INCLUDE_FLAG)

LDFLAGS = -fexceptions -s EXPORTED_FUNCTIONS='["_CppAddressCreateWithMiliKey", "_CppAddressIsValid", "_CppDecodeEvmCall", "_CppSignMili23", "_CppJsonTransactionMili23", "_TWStringSize", "_TWStringUTF8Bytes", "_TWStringDelete"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]'

ifneq (v$(V),v1)
	hide?=@
else
	hide?=
endif

#定义可执行文件生成的目录,?=是如果没有被赋值过就赋予等号后面的值
LIB_PATH ?= ./build/wallet-core
BIN_PATH ?= ./build
OBJECT_PATH ?= ./build/wallet-core

TARGET ?= $(BIN_PATH)/MiliWalletCore.js
SOURCES := $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp src/*/*.cc src/*/*/*.cc)

OBJECTS := $(addsuffix .o,$(addprefix $(OBJECT_PATH)/,$(basename $(SOURCES:src/%.cpp=%.cpp))))
DEPENDS := $(addsuffix .d,$(OBJECTS))

#获取所有.o
ALL_OBJECTS := $(OBJECTS)

SOURCES_PB := $(shell find build/local/src/protobuf/protobuf-3.14.0/src/google/protobuf ! -path "*/compiler/*" ! -name "*test.cc" ! -name "*test_util*.cc" ! -name "*zip.cc" -name "*.cc")
SOURCES_PB += build/local/src/protobuf/protobuf-3.14.0/src/google/protobuf/compiler/importer.cc
SOURCES_PB += build/local/src/protobuf/protobuf-3.14.0/src/google/protobuf/compiler/parser.cc
ALL_OBJECTS += $(addsuffix .o,$(addprefix build/protobuf/,$(basename $(notdir $(SOURCES_PB)))))
SOURCES_TZ := crypto/bignum.c crypto/ecdsa.c crypto/curves.c crypto/secp256k1.c crypto/rand.c crypto/hmac.c crypto/bip32.c crypto/bip39.c crypto/pbkdf2.c crypto/base58.c crypto/base32.c crypto/address.c
SOURCES_TZ += crypto/script.c crypto/ripemd160.c crypto/sha2.c crypto/sha3.c crypto/hasher.c
SOURCES_TZ += crypto/aes/aescrypt.c crypto/aes/aeskey.c crypto/aes/aestab.c crypto/aes/aes_modes.c
SOURCES_TZ += crypto/ed25519-donna/curve25519-donna-32bit.c crypto/ed25519-donna/curve25519-donna-helpers.c crypto/ed25519-donna/modm-donna-32bit.c
SOURCES_TZ += crypto/ed25519-donna/ed25519-donna-basepoint-table.c crypto/ed25519-donna/ed25519-donna-32bit-tables.c crypto/ed25519-donna/ed25519-donna-impl-base.c
SOURCES_TZ += crypto/ed25519-donna/ed25519.c crypto/ed25519-donna/curve25519-donna-scalarmult-base.c crypto/ed25519-donna/ed25519-sha3.c crypto/ed25519-donna/ed25519-keccak.c crypto/ed25519-donna/ed25519-blake2b.c
SOURCES_TZ += crypto/sodium/private/fe_25_5/fe.c crypto/sodium/private/ed25519_ref10.c crypto/sodium/private/ed25519_ref10_fe_25_5.c crypto/sodium/keypair.c
SOURCES_TZ += crypto/monero/base58_xmr.c crypto/monero/serialize.c crypto/monero/range_proof.c crypto/blake256.c
SOURCES_TZ += crypto/blake2b.c crypto/blake2s.c crypto/chacha_drbg.c crypto/chacha20poly1305/chacha20poly1305.c crypto/chacha20poly1305/chacha_merged.c crypto/chacha20poly1305/poly1305-donna.c crypto/chacha20poly1305/rfc7539.c
SOURCES_TZ += crypto/rc4.c crypto/nano.c crypto/nem.c crypto/cash_addr.c crypto/memzero.c
SOURCES_TZ += crypto/scrypt.c crypto/nist256p1.c crypto/groestl.c crypto/hmac_drbg.c crypto/rfc6979.c crypto/schnorr.c crypto/shamir.c
SOURCES_TZ := $(addprefix trezor-crypto/,$(SOURCES_TZ))
ALL_OBJECTS += $(addsuffix .o,$(addprefix build/trezor-crypto/,$(basename $(notdir $(SOURCES_TZ)))))

all:begin prepare build finish

begin: ;$(hide) echo ==== start, $(shell date) ====
prepare: $(BIN_PATH) $(OBJECT_PATH)
build: $(TARGET)
finish: ;$(hide) echo ==== done, $(shell date) ====
clean: ;rm -rf $(OBJECT_PATH)

$(OBJECT_PATH): ; mkdir -p $@
$(TARGET) : $(OBJECTS)
	$(info LD $@)
	$(hide) $(LD) -o $@ $(ALL_OBJECTS) $(LDFLAGS)

define make-cmd-cc
$2 : $1
	$$(info CC $$<)
	$$(hide) mkdir -p $$(dir $$@)
	$$(hide) $$(CC) $$(CFLAGS) -MMD -MT $$@ -MF $$@.d -c -o $$@ $$<
endef

$(foreach afile,$(SOURCES),\
	$(eval $(call make-cmd-cc,$(afile),\
		$(addsuffix .o,$(addprefix $(OBJECT_PATH)/,$(basename $(afile:src/%.cpp=%.cpp)))))))


-include $(DEPENDS)