#include "WalletCoreJni.h"
#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWAnyAddress.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWEthereumAbi.h>
#include <string>
#include <stdlib.h>
#include <android/log.h>

#define TAG    "wallet-core"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__)

extern "C" {
  extern const char* GoCreateMili23(const char* curve, const char* session, const char* preParam);
  extern const char* GoSignMili23(const char* curve, const char* key, const char* msg);
  extern const char* GoReshareMili23(const char* curve, const char* session, const char* localkey, const char* preParam);
  extern const char* GoDecryptShareKey(const char* userId, const char* accountId, const char* enKey);
  extern const char* GoEncryptShareKey(const char* userId, const char* accountId, const char* deKey);
  extern void GoSetRequestEnv(const char* jsonEnv);
  extern const char* GoGwRequest(const char* method, const char* header, const char* path, const char* params, const char* payload);
  extern const char* GoBuildRequest(const char* aesKey, const char* method, const char* header, const char* path, const char* params, const char* payload);
  extern const char* GoLandResponse(const char* aesKey, const char* enResp);

  extern void chaindata_initChainConfig(const char* chainConfig);
  extern const char* chaindata_getEIP1559TokenParams(const char* chain, const char* fromAddress, const char* toAddress, const char* tokenAddress, const char* tpe);
  extern const char* chaindata_getTokenTxParams(const char* chain, const char* fromAddress, const char* toAddress, const char* tokenAddress, const char* tpe);
  extern const char* chaindata_getTxParams(const char* chain, const char* fromAddress);
  extern const char* chaindata_getSTCTxParams(const char* chain, const char* fromAddress, const char* toAddress, const char* publicKey, const char* typeArgs);
  extern const char* chaindata_getEIP1559TxParams(const char* chain, const char* fromAddress);
  extern const char* chaindata_getTokenType(const char* chain, const char* tokenAddress);
  extern const char* chaindata_sendRawTransaction(const char* chain, const char* rawTx);
  extern const char* chaindata_getTransaction(const char* chain, const char* address, const char* txHashs);
  extern const char* chaindata_allBalance(const char* chain, const char* address);
}

static jstring CStrToJString(JNIEnv *env, const char *cstr) {
    //定义java String类 strClass
    jclass strClass = (env)->FindClass("java/lang/String");
    //获取java String类方法String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
    jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
    //建立byte数组
    jbyteArray bytes = (env)->NewByteArray((jsize) strlen(cstr));
    //将char* 转换为byte数组
    (env)->SetByteArrayRegion(bytes, 0, (jsize) strlen(cstr), (jbyte *) cstr);
    //设置String, 保存语言类型,用于byte数组转换至String时的参数
    jstring encoding = (env)->NewStringUTF("UTF-8");
    //将byte数组转换为java String,并输出
    return (jstring) (env)->NewObject(strClass, ctorID, bytes, encoding);
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_CreateMili23(JNIEnv *env, jobject jthis, jstring curveJstr, jstring sessionJstr, jstring preParamJstr)
{
  const char* curve = env->GetStringUTFChars(curveJstr, NULL);
  const char* session = env->GetStringUTFChars(sessionJstr, NULL);
  const char* preParam = env->GetStringUTFChars(preParamJstr, NULL);
  const char* goRet = GoCreateMili23(curve, session, preParam);
  env->ReleaseStringUTFChars(curveJstr, curve);
  env->ReleaseStringUTFChars(sessionJstr, session);
  env->ReleaseStringUTFChars(preParamJstr, preParam);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_ReshareMili23(JNIEnv *env, jobject jthis, jstring curveJstr, jstring sessionJstr, jstring keyJstr, jstring preParamJstr)
{
  const char* curve = env->GetStringUTFChars(curveJstr, NULL);
  const char* session = env->GetStringUTFChars(sessionJstr, NULL);
  const char* key = env->GetStringUTFChars(keyJstr, NULL);
  const char* preParam = env->GetStringUTFChars(preParamJstr, NULL);
  const char* goRet = GoReshareMili23(curve, session, key, preParam);
  env->ReleaseStringUTFChars(curveJstr, curve);
  env->ReleaseStringUTFChars(sessionJstr, session);
  env->ReleaseStringUTFChars(keyJstr, key);
  env->ReleaseStringUTFChars(preParamJstr, preParam);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_GetAddress(JNIEnv *env, jobject jthis, jstring keyJstr, jint coinId)
{
  const char* key = env->GetStringUTFChars(keyJstr, NULL);
  const char* cppRet = CppAddressCreateWithMiliKey(key, (TWCoinType)coinId);
  env->ReleaseStringUTFChars(keyJstr, key);
  return env->NewStringUTF(cppRet);
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_GetPublicKey(JNIEnv *env, jobject jthis, jstring keyJstr, jint coinId)
{
  const char* key = env->GetStringUTFChars(keyJstr, NULL);
  const char* cppRet = CppPublicKeyWithMiliKey(key, (TWCoinType)coinId);
  env->ReleaseStringUTFChars(keyJstr, key);
  return env->NewStringUTF(cppRet);
}

JNIEXPORT jboolean JNICALL Java_com_openblock_wallet_jni_WalletCore_VerifyAddress(JNIEnv *env, jobject jthis, jstring addressJstr, jint coinId)
{
  const char* address = env->GetStringUTFChars(addressJstr, NULL);
  bool ret = CppAddressIsValid(address, (TWCoinType)coinId);
  env->ReleaseStringUTFChars(addressJstr, address);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_DecodeEvmCall(JNIEnv *env, jobject jthis, jstring callDataJstr)
{
  const char* callData = env->GetStringUTFChars(callDataJstr, NULL);
  auto cppRet = (const std::string*)CppDecodeEvmCall(callData);
  env->ReleaseStringUTFChars(callDataJstr, callData);
  jstring ret = env->NewStringUTF(cppRet->c_str());
  delete cppRet;
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_JsonTransactionMili23(JNIEnv *env, jobject jthis, jstring sessionJstr, jstring keyJstr, jint coinId, jstring inputJstr)
{
  const char* session = env->GetStringUTFChars(sessionJstr, NULL);
  const char* key = env->GetStringUTFChars(keyJstr, NULL);
  const char* input = env->GetStringUTFChars(inputJstr, NULL);
  auto cppRet = (const std::string*)CppJsonTransactionMili23(session, key, (TWCoinType)coinId, input);
  env->ReleaseStringUTFChars(sessionJstr, session);
  env->ReleaseStringUTFChars(keyJstr, key);
  env->ReleaseStringUTFChars(inputJstr, input);
  jstring ret = env->NewStringUTF(cppRet->c_str());
  delete cppRet;
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_SignMili23(JNIEnv *env, jobject jthis, jstring sessionJstr, jstring keyJstr, jint coinId, jstring msgJstr)
{
  const char* session = env->GetStringUTFChars(sessionJstr, NULL);
  const char* key = env->GetStringUTFChars(keyJstr, NULL);
  const char* msg = env->GetStringUTFChars(msgJstr, NULL);
  const char* cppRet = CppSignMili23(session, key, (TWCoinType)coinId, msg);
  env->ReleaseStringUTFChars(sessionJstr, session);
  env->ReleaseStringUTFChars(keyJstr, key);
  env->ReleaseStringUTFChars(msgJstr, msg);
  return env->NewStringUTF(cppRet);
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_SignMessageMili23(JNIEnv *env, jobject jthis, jstring curveJstr, jstring keyJstr, jstring msgJstr)
{
  const char* curve = env->GetStringUTFChars(curveJstr, NULL);
  const char* key = env->GetStringUTFChars(keyJstr, NULL);
  const char* msg = env->GetStringUTFChars(msgJstr, NULL);
  const char* goRet = GoSignMili23(curve, key, msg);
  env->ReleaseStringUTFChars(curveJstr, curve);
  env->ReleaseStringUTFChars(keyJstr, key);
  env->ReleaseStringUTFChars(msgJstr, msg);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_DecryptShareKey
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr, jstring arg3Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* arg3 = env->GetStringUTFChars(arg3Jstr, NULL);
  const char* goRet = GoDecryptShareKey(arg1, arg2, arg3);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  env->ReleaseStringUTFChars(arg3Jstr, arg3);
  //jstring ret = env->NewStringUTF(goRet);
  jstring ret = CStrToJString(env, goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_EncryptShareKey
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr, jstring arg3Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* arg3 = env->GetStringUTFChars(arg3Jstr, NULL);
  const char* goRet = GoEncryptShareKey(arg1, arg2, arg3);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  env->ReleaseStringUTFChars(arg3Jstr, arg3);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}


JNIEXPORT void JNICALL Java_com_openblock_wallet_jni_WalletCore_SetRequestEnv
  (JNIEnv *env, jobject jthis, jstring jsonEnvJstr)
{
  const char* jsonEnv = env->GetStringUTFChars(jsonEnvJstr, NULL);
  GoSetRequestEnv(jsonEnv);
  env->ReleaseStringUTFChars(jsonEnvJstr, jsonEnv);
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_GwRequest
  (JNIEnv *env, jobject jthis, jstring methodJstr, jstring headerJstr, jstring pathJstr, jstring paramsJstr, jstring payloadJstr)
{
  const char* method = env->GetStringUTFChars(methodJstr, NULL);
  const char* header = env->GetStringUTFChars(headerJstr, NULL);
  const char* path = env->GetStringUTFChars(pathJstr, NULL);
  const char* params = env->GetStringUTFChars(paramsJstr, NULL);
  const char* payload = env->GetStringUTFChars(payloadJstr, NULL);
  const char* goRet = GoGwRequest(method, header, path, params, payload);
  env->ReleaseStringUTFChars(methodJstr, method);
  env->ReleaseStringUTFChars(headerJstr, header);
  env->ReleaseStringUTFChars(pathJstr, path);
  env->ReleaseStringUTFChars(paramsJstr, params);
  env->ReleaseStringUTFChars(payloadJstr, payload);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_BuildRequest
  (JNIEnv *env, jobject jthis, jstring aesKeyJstr, jstring methodJstr, jstring headerJstr, jstring pathJstr, jstring paramsJstr, jstring payloadJstr)
{
  const char* aesKey = env->GetStringUTFChars(aesKeyJstr, NULL);
  const char* method = env->GetStringUTFChars(methodJstr, NULL);
  const char* header = env->GetStringUTFChars(headerJstr, NULL);
  const char* path = env->GetStringUTFChars(pathJstr, NULL);
  const char* params = env->GetStringUTFChars(paramsJstr, NULL);
  const char* payload = env->GetStringUTFChars(payloadJstr, NULL);
  const char* goRet = GoBuildRequest(aesKey, method, header, path, params, payload);
  env->ReleaseStringUTFChars(aesKeyJstr, aesKey);
  env->ReleaseStringUTFChars(methodJstr, method);
  env->ReleaseStringUTFChars(headerJstr, header);
  env->ReleaseStringUTFChars(pathJstr, path);
  env->ReleaseStringUTFChars(paramsJstr, params);
  env->ReleaseStringUTFChars(payloadJstr, payload);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}


JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_LandResponse
  (JNIEnv *env, jobject jthis, jstring aesKeyJstr, jstring enRespJstr)
{
  const char* aesKey = env->GetStringUTFChars(aesKeyJstr, NULL);
  const char* enResp = env->GetStringUTFChars(enRespJstr, NULL);
  const char* goRet = GoLandResponse(aesKey, enResp);
  env->ReleaseStringUTFChars(aesKeyJstr, aesKey);
  env->ReleaseStringUTFChars(enRespJstr, enResp);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT void JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1initChainConfig
  (JNIEnv *env, jobject jthis, jstring arg1Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  chaindata_initChainConfig(arg1);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getEIP1559TokenParams
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr, jstring arg3Jstr, jstring arg4Jstr, jstring arg5Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* arg3 = env->GetStringUTFChars(arg3Jstr, NULL);
  const char* arg4 = env->GetStringUTFChars(arg4Jstr, NULL);
  const char* arg5 = env->GetStringUTFChars(arg5Jstr, NULL);
  const char* goRet = chaindata_getEIP1559TokenParams(arg1, arg2, arg3, arg4, arg5);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  env->ReleaseStringUTFChars(arg3Jstr, arg3);
  env->ReleaseStringUTFChars(arg4Jstr, arg4);
  env->ReleaseStringUTFChars(arg5Jstr, arg5);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTokenTxParams
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr, jstring arg3Jstr, jstring arg4Jstr, jstring arg5Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* arg3 = env->GetStringUTFChars(arg3Jstr, NULL);
  const char* arg4 = env->GetStringUTFChars(arg4Jstr, NULL);
  const char* arg5 = env->GetStringUTFChars(arg5Jstr, NULL);
  const char* goRet = chaindata_getTokenTxParams(arg1, arg2, arg3, arg4, arg5);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  env->ReleaseStringUTFChars(arg3Jstr, arg3);
  env->ReleaseStringUTFChars(arg4Jstr, arg4);
  env->ReleaseStringUTFChars(arg5Jstr, arg5);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTxParams
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* goRet = chaindata_getTxParams(arg1, arg2);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getSTCTxParams
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr, jstring arg3Jstr, jstring arg4Jstr, jstring arg5Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* arg3 = env->GetStringUTFChars(arg3Jstr, NULL);
  const char* arg4 = env->GetStringUTFChars(arg4Jstr, NULL);
  const char* arg5 = env->GetStringUTFChars(arg5Jstr, NULL);
  const char* goRet = chaindata_getSTCTxParams(arg1, arg2, arg3, arg4, arg5);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  env->ReleaseStringUTFChars(arg3Jstr, arg3);
  env->ReleaseStringUTFChars(arg4Jstr, arg4);
  env->ReleaseStringUTFChars(arg5Jstr, arg5);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getEIP1559TxParams
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* goRet = chaindata_getEIP1559TxParams(arg1, arg2);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTokenType
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* goRet = chaindata_getTokenType(arg1, arg2);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1sendRawTransaction
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* goRet = chaindata_sendRawTransaction(arg1, arg2);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTransaction
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr, jstring arg3Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* arg3 = env->GetStringUTFChars(arg3Jstr, NULL);
  const char* goRet = chaindata_getTransaction(arg1, arg2, arg3);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  env->ReleaseStringUTFChars(arg3Jstr, arg3);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}

JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1allBalance
  (JNIEnv *env, jobject jthis, jstring arg1Jstr, jstring arg2Jstr)
{
  const char* arg1 = env->GetStringUTFChars(arg1Jstr, NULL);
  const char* arg2 = env->GetStringUTFChars(arg2Jstr, NULL);
  const char* goRet = chaindata_allBalance(arg1, arg2);
  env->ReleaseStringUTFChars(arg1Jstr, arg1);
  env->ReleaseStringUTFChars(arg2Jstr, arg2);
  jstring ret = env->NewStringUTF(goRet);
  free((void*)goRet);
  return ret;
}