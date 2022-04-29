package com.openblock.wallet.jni;

public class WalletCore
{
    /*
    * tss私钥创建
    * @curve: ecdsa或者eddsa
    * @session: 用户系统返回
    * @preParam: 初始化时从后端拉取
    * 返回：私钥碎片json串
    */
    public native String CreateMili23(String curve, String session, String preParam);

    /*
    * tss私钥重置
    * @curve: 同上
    * @session: 同上
    * @key: 本地私钥碎片
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
    * 返回：十六进制签名结果
    */
    public native String SignMessageMili23(String curve, String key, String msg);

    /*
    * 设置请求环境变量(json)
    * @jsonEnv: {"server":"", "gw_server":"", "token":"", "secret":"", "public_key":"", "cert_sn":""}
    */
    public native void SetRequestEnv(String jsonEnv);

    /*
    * 发送网关请求
    * @method: POST/GET
    * @header: 请求header，json字典
    * @path: 请求路径
    * @params: json结构[{"k":"参数名", "v":"参数值", "sign_it": true}], 如果一些参数不参与签名，sign_it为false
    * @payload: 请求body，如果params传空，则解析payload并在其中添加sign后做为body
    * 返回：请求结果
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

    public static void main(String[] args) {
        System.loadLibrary("wallet_core.android.arm64.a"); //载入本地库
        WalletCore wc = new WalletCore();
    }
}