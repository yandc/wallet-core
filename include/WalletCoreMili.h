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

/*===============以下是链上信息获取接口==================*/
/*
chaindata_setClient设置rpc连接
handler：链名称
chainType：链的分类，是main还是type
nodeURL：rpc
*/
extern void chaindata_setClient(const char* handler, const char* chainType, const char* nodeURL);

/*
chaindata_getEIP1559TokenParams获取eip1559 token交易参数
handler：链名称
fromAddress：发送地址
toAddress：接受地址
tokenAddress：token地址
返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
*/
extern const char* chaindata_getEIP1559TokenParams(const char* handler, const char* fromAddress, const char* toAddress, const char* tokenAddress);

/*
chaindata_getTokenTxParams获取token交易参数
handler：链名称
fromAddress：发送地址
toAddress：接受地址
tokenAddress：token地址
返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
*/
extern const char* chaindata_getTokenTxParams(const char* handler, const char* fromAddress, const char* toAddress, const char* tokenAddress);

/*
chaindata_getTxParams获取交易参数
handler：链名称
fromAddress：发送地址
返回：交易参数，返回结果类型是map[string]interface{}的json的字符串，value中可能也包含map结构
*/
extern const char* chaindata_getTxParams(const char* handler, const char* fromAddress);

/*
chaindata_getSTCTxParams获取stc交易参数
handler：链名称
fromAddress：发送地址
toAddress：接受地址
publicKey: 用户的公钥
typeArgs：代币地址
返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
*/
extern const char* chaindata_getSTCTxParams(const char* handler, const char* fromAddress, const char* toAddress, const char* publicKey, const char* typeArgs);

/*
chaindata_getEIP1559TxParams获取eip1559交易参数
handler：链名称
fromAddress：发送地址
返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
*/
extern const char* chaindata_getEIP1559TxParams(const char* handler, const char* fromAddress);

/*
chaindata_getTokenType获取token信息
handler：链名称
tokenAddress：token地址的数组的json字符串
返回：token信息，返回结果类型是map[tokenAddress]tokenInfo的json字符串;tokenInfo是map[string]string
*/
extern const char* chaindata_getTokenType(const char* handler, const char* tokenAddress);

/*
chaindata_sendRawTransaction发送交易
handler：链名称
rawTx：交易数据
返回：交易hash
*/
extern const char* chaindata_sendRawTransaction(const char* handler, const char* rawTx);

/*
chaindata_getTransaction获取交易信息
handler：链名称
address：当前用户的address
txHashs: 交易hash的数组的json字符串
返回：交易hash信息，返回结构是map[txhash]txInfo的json字符串;txInfo是map[string]string
*/
extern const char* chaindata_getTransaction(const char* handler, const char* address, const char* txHashs);

/*
chaindata_allBalance获取当前链的所有地址的所有币种的余额
handler：链名称
address：当前链的所有地址，结构是map[address]map[contract][decimals]的json字符串
返回：返回结构是map[address:map[{address:balance, token1:balance}]]的json字符串
*/
extern const char* chaindata_allBalance(const char* handler, const char* address);


#ifdef __cplusplus
}
#endif
#endif
