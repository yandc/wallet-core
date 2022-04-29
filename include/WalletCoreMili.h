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
* 设置请求环境变量(json)
* @params: {"server":"", "gw_server":"", "token":"", "secret":"", "public_key":"", "cert_sn":""}
*/
extern void GoSetRequestEnv(const char* jsonEnv);

/*
* 发送网关请求
* @method: POST/GET
* @header: 请求header，json字典
* @path: 请求路径
* @params: json结构[{"k":"参数名", "v":"参数值", "sign_it": true}], 如果一些参数不参与签名，sign_it为false
* @payload: 请求body，如果params传空，则解析payload并在其中添加sign后做为body
* 返回：请求结果
*/
extern const char* GoGwRequest(const char* method, const char* header, const char* path, const char* params, const char* payload);

/*
* 构建网关请求【将GwRequest拆分为构建、发送、解密三个步骤】
* @aesKey: 加密密钥
* @method: POST/GET
* @header: 同上
* @path: 同上
* @params: 同上
* @payload: 同上
* 返回：待发送POST请求的body
*/
extern const char* GoBuildRequest(const char* aesKey, const char* method, const char* header, const char* path, const char* params, const char* payload);

/*
* 解密网关返回结果
* @aesKey: 对应GoBuildRequest中的加密密钥
* @enResp: 网关返回data
* 返回：请求结果
*/
extern const char* GoLandResponse(const char* aesKey, const char* enResp);

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
