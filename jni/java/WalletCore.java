package com.openblock.wallet.jni;

public class WalletCore
{
    /*
    * tss私钥创建
    * @curve: ecdsa或者eddsa
    * @session: 用户系统返回
    * @preParam: 初始化时从后端拉取
    * 返回：私钥碎片json串，结构：{"status":true/false, "result":"", "error":""}
    */
    public native String CreateMili23(String curve, String session, String preParam);

    /*
    * tss私钥重置
    * @curve: 同上
    * @session: 同上
    * @key: 本地私钥碎片
    * 返回：私钥碎片，结构：{"status":true/false, "result":"", "error":""}
    */
    public native String ReshareMili23(String curve, String session, String key, String preParam);

    /*
    * 地址创建
    * @key: 本地私钥碎片
    * @coinId: 链配置中的coinId
    * 返回：地址
    */
    public native String GetAddress(String key, int coinId);

    /*
    * 获取公钥
    * @key: 本地私钥碎片
    * @coinId: 链配置中的coinId
    * 返回：公钥hex串
    */
    public native String GetPublicKey(String key, int coinId);

    /*
    * 地址校验
    */
    public native boolean VerifyAddress(String address, int coinId);

    /*
    * 解析Evm合约数据
    */
    public native String DecodeEvmCall(String callData);

    /*
    * 构建可上链交易
    * @input: 交易输入参数，json结构
    * 返回：十六进制交易
    */
    public native String JsonTransactionMili23(String session, String key, int coinId, String input);

    /*
    * 对任意消息签名
    * @msg: 签名消息，任意字符串
    * 返回：十六进制签名结果
    */
    public native String SignMili23(String session, String key, int coinId, String msg);

    /*
    * 对消息签名【内部使用】
    * @msg: 签名消息，十六进制
    * 返回：十六进制签名结果，结构：{"status":true/false, "result":"", "error":""}
    */
    public native String SignMessageMili23(String curve, String key, String msg);

    /*
    * 私钥分片解密
    * @userId: 用户Id
    * @accountId: 私钥对应accountId
    * @deKey: 密文
    * 返回：解密结果
    */
    public native String DecryptShareKey(String userId, String accountId, String enKey);

    /*
    * 私钥分片加密
    * @userId: 同上
    * @accountId: 同上
    * @deKey: 明文
    * 返回：加密结果
    */
    public native String EncryptShareKey(String userId, String accountId, String deKey);

    /*
    * 设置请求环境变量(json)
    * @jsonEnv: {"server":"", "gw_server":"", "token":"", "secret":"", "cert":"", "cert_sn":""}
    */
    public native void SetRequestEnv(String jsonEnv);

    /*
    * 发送网关请求
    * @method: POST/GET
    * @header: 请求header，json字典
    * @path: 请求路径
    * @params: json结构[{"k":"参数名", "v":"参数值", "sign_it": true}], 如果一些参数不参与签名，sign_it为false
    * @payload: 请求body，如果params传空，则解析payload并在其中添加sign后做为body
    * 返回：请求结果，结构：{"status":true/false, "result":"", "error":""}
    */
    public native String GwRequest(String method, String header, String path, String params, String payload);

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
    public native String BuildRequest(String aesKey, String method, String header, String path, String params, String payload);

    /*
    * 解密网关返回结果
    * @aesKey: 对应GoBuildRequest中的加密密钥
    * @resp: 网关返回data
    * 返回：请求结果
    */
    public native String LandResponse(String aesKey, String enResp);

    /*===============以下是链上信息获取接口==================*/
    /*
    chaindata_initChainConfig下发链配置，初始化SDK之后，需要先调用一下
    chainConfig:是链配置数组的字符串
    chainConfig例子：[{"chain_type":"EVM","chain":"ETH","proxy_key":"gasOracleETH","rpc_urls":["https://mainnet.infura.io/v3/9aa3d95b3bc440fa88ea12eaa4456161","https://web3os.tokenpocket.pro"],"proxy_cache_time":15}]
    返回结构：{"status":true/false, "result":"", "error":""}
    */
    public native String chaindata_initChainConfig(String chainConfig);

    /*
    chaindata_getEIP1559TokenParams获取eip1559 token交易参数
    handler：链名称
    fromAddress：发送地址
    toAddress：接受地址
    tokenAddress：token地址
    tpe:approve或者transfer
    返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
    */
    public native String chaindata_getEIP1559TokenParams(String chain, String fromAddress, String toAddress, String tokenAddress, String tpe);

    /*
    chaindata_getTokenTxParams获取token交易参数
    chain：链名称
    fromAddress：发送地址
    toAddress：接受地址
    tokenAddress：token地址
    tpe:approve或者transfer
    返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
    */
    public native String chaindata_getTokenTxParams(String chain, String fromAddress, String toAddress, String tokenAddress, String tpe);

    /*
    chaindata_getTxParams获取交易参数
    handler：链名称
    fromAddress：发送地址
    返回：交易参数，返回结果类型是map[string]interface{}的json的字符串，value中可能也包含map结构
    */
    public native String chaindata_getTxParams(String chain, String fromAddress);

    /*
    chaindata_getSTCTxParams获取stc交易参数
    handler：链名称
    fromAddress：发送地址
    toAddress：接受地址
    publicKey: 用户的公钥
    typeArgs：代币地址
    返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
    */
    public native String chaindata_getSTCTxParams(String chain, String fromAddress, String toAddress, String publicKey, String typeArgs);

    /*
    chaindata_getEIP1559TxParams获取eip1559交易参数
    handler：链名称
    fromAddress：发送地址
    返回：交易参数，返回结果类型是map[string]interface{}的json字符串，value中可能也包含map结构
    */
    public native String chaindata_getEIP1559TxParams(String chain, String fromAddress);

    /*
    chaindata_getTokenType获取token信息
    handler：链名称
    tokenAddress：token地址的数组的json字符串
    返回：token信息，返回结果类型是map[tokenAddress]tokenInfo的json字符串;tokenInfo是map[string]string
    */
    public native String chaindata_getTokenType(String chain, String tokenAddress);

    /*
    chaindata_sendRawTransaction发送交易
    handler：链名称
    rawTx：交易数据
    返回：交易hash
    */
    public native String chaindata_sendRawTransaction(String chain, String rawTx);

    /*
    chaindata_getTransaction获取交易信息
    handler：链名称
    address：当前用户的address
    txHashs: 交易hash的数组的json字符串
    返回：交易hash信息，返回结构是map[txhash]txInfo的json字符串;txInfo是map[string]string
    */
    public native String chaindata_getTransaction(String chain, String address, String txHashs);

    /*
    chaindata_allBalance获取当前链的所有地址的所有币种的余额
    handler：链名称
    address：当前链的所有地址，结构是map[address]map[contract][decimals]的json字符串
    返回：返回结构是map[address:map[{address:balance, token1:balance}]]的json字符串
    */
    public native String chaindata_allBalance(String chain, String address);

    public static void main(String[] args) {
        System.loadLibrary("wallet_core.android.arm64.a"); //载入本地库
        WalletCore wc = new WalletCore();
    }
}