#ifndef __WalletCore_H__
#define __WalletCore_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef const void TWString;

/*
* tss私钥创建
* @curve: ecdsa或者eddsa
* @session: 用户系统返回
* @preParam: 初始化时从后端拉取
* 返回：私钥碎片json串，需要调用free释放
*/
extern const char* GoCreateMili23(const char* curve, const char* session, const char* preParam);

/*
* tss私钥重置
* @curve: 同上
* @session: 同上
* @key: 本地私钥碎片，需要调用free释放
*/
extern const char* GoReshareMili23(const char* curve, const char* session, const char* key, const char* preParam);

/*
* 对消息签名【内部使用】
* @msg: 签名消息，十六进制
* 返回：十六进制签名结果
*/
extern const char* GoSignMili23(const char* curve, const char* key, const char* msg);

/*
* 地址创建
* @key: 本地私钥碎片
* @coinId: 链配置中的coinId
* 返回：地址
*/
extern const char* CppAddressCreateWithMiliKey(const char * key, int coinId);

/*
* 地址校验
*/
extern bool CppAddressIsValid(const char* address, int coinId);

/*
* 对任意消息签名
* @msg: 签名消息
* 返回：十六进制签名结果，无需释放
*/
extern const char* CppSignMili23(const char* session, const char* key, int coinId, const char* msg);

/*
* 构建可上链交易
* @input: 交易输入参数，json结构
* 返回：十六进制交易
*/
extern TWString* CppJsonTransactionMili23(const char* session, const char* key, int coinId, const char* input);

/*
* 解析Evm合约数据
*/
extern TWString* CppDecodeEvmCall(const char* callData);

/*
* 操作TWString类型
*/
const char* TWStringUTF8Bytes(TWString* string);
size_t TWStringSize(TWString* string);
void TWStringDelete(TWString* string);

#ifdef __cplusplus
}
#endif
#endif
