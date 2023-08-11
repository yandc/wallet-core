package com.openblock.wallet.jni;

public class WalletCore
{
    /*
    * tss私钥创建
    * @curve: ecdsa或者eddsa
    * @session: 用户系统返回
    *           普通托管创建： sessionid-salt
    *           社交托管创建： sessionid-salt
    * @preParam: 初始化时从后端拉取
    * @mode: 枚举，托管trust, 社交恢复发起方origin, 社交恢复托管方backup, 升级为社交恢复upgrade
    *        普通托管创建： 发起方trust
    *        社交托管创建： 发起方origin，托管方backup
    *        企业钱包创建2-2： user_v2
    * 返回：私钥碎片json串，结构：{"status":true/false, "result":"", "error":""}
    */
    public native String CreateMili23(String curve, String session, String preParam, String mode);

    /*
    * tss私钥重置
    * @session: 用户系统返回，格式：
    *           普通托管重置： sessionId-oldSalt-userId-accountId-newSalt
    *           社交托管重置： sessionId-oldSalt---newSalt
    *           升级为社交托管：sessionId-oldSalt---newSalt
    * @key: 本地私钥碎片，结构：{"Key": "...", "Pub": "..."}
    * @mode: 枚举，托管trust, 社交恢复发起方origin, 社交恢复托管方backup, 升级为社交恢复upgrade
    *        普通托管重置： 发起方trust
    *        快速托管重置： 发起方trust_v2
    *        社交托管c重置： 发起方origin，托管方backup
    *        升级为社交托管：发起方upgrade，托管费backup
    *        企业钱包邀请管理员：创建founder，管理员manager
    *        企业钱包v2：邀请人manager_v2_invitor, 管理员manager_v2
    * 返回：私钥碎片，结构：{"status":true/false, "result":"", "error":""}
    */
    public native String ReshareMili23(String curve, String session, String key, String preParam, String mode);

    /*
    * @key: 本地单元，格式{"Key":"...", "Pub":["...","..."]}
    * @offset: 后端返回
    * 返回：{"Key":md5(managerKey), "Pub":managerKey.Pub}，和企业钱包普通成员的派生结果作用相同
    */
    public native String DeriveMili23(String curve, String key, String offset);

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
    * @session: 拼接格式：sessionId-salt[-offset](offset可选)
    * @input: 交易输入参数，json结构
    * 返回：十六进制交易
    */
    public native String JsonTransactionMili23(String session, String key, String preSign, int coinId, String input);

    /*
    * 对任意消息签名
    * @session: 拼接格式：sessionId-salt[-offset](offset可选)
    * @msg: 签名消息，任意字符串
    * 返回：十六进制签名结果
    */
    public native String SignMili23(String session, String key, String preSign, int coinId, String msg);

    /*
    * 对十六进制数据签名，如果dapp传入数据未经转换就直接传入，可能直接转移资产
    * @session: 拼接格式：sessionId-salt[-offset](offset可选)
    * @hexMsg: 十六进制消息
    */
    public native String RawSignMili23(String curve, String session, String key, String preSign, String hexMsg);

    /*
    * 预签名，目前只支持ECDSA
    * @session: 拼接格式：sessionId-salt[-offset](offset可选)
    * 返回：预签名结果，结构：{"status":true/false, "result":"preSign", "error":""}
    */
    public native String OfflineSignMili23(String curve, String session, String key);

    /*
    * UTXO plan
    * @input: 交易输入参数，json结构
    * 返回：{"amount":1000, "fee":100, "utxo_size":2}
    */
    public native String UtxoPlan(int coinId, String input);
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
    resolvers: json对象，链配置中获取，具体文档：https://tk3en79uf0.larksuite.com/docx/doxus5KstWG3LsebEHAdoj62vWb
    返回结构：{"status":true/false, "result":"", "error":""}
    */
    public native String chaindata_initChainConfig(String chainConfig, String resolvers);

    /*
    chaindata_getTransactionParams统一获取交易参数的接口
    chain：哪条链
    params:不同的链，传不同对象的json字符串
    传入不同链的参数文档：https://tk3en79uf0.larksuite.com/docx/doxustISaUMqqdBwFNx4h1oPbge
    */
    public native String chaindata_getTransactionParams(String chain, String params);

    public native String chaindata_dappJson(String chain, String params);

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

    /*
    chaindata_getGasEstimate get gas estimated time
    chain:那条链，现在暂只支持ETH
    params:map[string]string{"gas_price":"8000000000"}格式的json字符串
    */
    public native String chaindata_getGasEstimate(String chain, String params);

    /*
    chaindata_abiDecode 解析dapp交互data字段
    contract: 合约地址
    data: dapp rpc交互中data字段
    */
    public native String chaindata_abiDecode(String chain, String contract, String data);

    /*
    chaindata_addressActive：判断当前地址的token地址时候有激活(主要是aptos)
    chain: 链名称
    address: 钱包地址
    result:返回所有激活的token
    */
    public native String chaindata_addressActive(String chain, String address);

    /*
    chaindata_getResourceActive：获取address下的token资源是否激活(solana使用)
    chain: 链名称
    resourceInfo: {"address":"","token_address":""}格式的json字符串
    result:true:激活；false：没有激活
    */
    public native String chaindata_getResourceActive(String chain, String resourceInfo);

    /*
    chaindata_getRpcURL：获取当前链的rpc(web端是在显示当前节点地方调用)
    */
    public native String chaindata_getRpcURL(String chain);

    /*
    chaindata_detectNode 探测节点(web端是打开所有可用节点的时候调用，主动触发)
    chain:链
    nodeURL:节点
    result:返回map,字段key是height，subTime
    */
    public native String chaindata_detectNode(String chain, String nodeURL);

    /*
    chaindata_setRpc 设置当前节点(web端在rpc节点选择的时候去选择节点)
    chain：链
    nodeURL:节点
    recordFlag：是否设置成最优节点 bool
    */
    public native String chaindata_setRpc(String chain, String nodeURL, String recordFlag);

    /*
    chaindata_getSubTime 获取当前节点状况，网络延时，web在节点地方调用
    chain：链
    nodeURL:节点
    result:返回map，字段key是sub_time，own_flag
    */
    public native String chaindata_getSubTime(String chain, String nodeURL);

    /*
    chaindata_getNonce 获取nonce
    chain：链
    address:地址
    */
    public native String chaindata_getNonce(String chain, String address);

    /*
    chaindata_getDirectTransfer 获取是否支持转nft(aptos nft用到)
    chain：链
    address:地址
    */
    public native String chaindata_getDirectTransfer(String chain, String address);

    /*
    chaindata_identifyRiskAddress 转账风险地址判定
    query: {"from_address": "", "to_address": ""}
    */
    public native String chaindata_identifyRiskAddress(String chain, String query);
    /*
    queryInfo: json object，内部字段如下：
    query: 域名或地址
    reverse: 是否反向解析， "true" or "false"
    project: 查询项目
    具体文档：https://tk3en79uf0.larksuite.com/docx/doxus5KstWG3LsebEHAdoj62vWb
    */
    public native String chaindata_lookupDomain(String chain, String queryInfo);

    /*
    chaindata_initCustomConfig 添加自定义链
    chainConfig:是链配置数组的字符串
    chainConfig例子：[{"type":"EVM","chain":"ETH","proxyKey":"gasOracleETH","rpcURLs":["https://mainnet.infura.io/v3/9aa3d95b3bc440fa88ea12eaa4456161","https://web3os.tokenpocket.pro"],"proxyCacheTime":15,"useNodeProxy":true,"chainId":1}]
    */
    public native String chaindata_initCustomConfig(String chainConfig);

    public static void main(String[] args) {
        System.loadLibrary("wallet_core.android.arm64.a"); //载入本地库
        WalletCore wc = new WalletCore();
    }
}