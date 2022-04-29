#include "WalletCoreJni.h"
#include <TrustWalletCore/TWCoinType.h>
#include <TrustWalletCore/TWAnyAddress.h>
#include <TrustWalletCore/TWAnySigner.h>
#include <TrustWalletCore/TWEthereumAbi.h>
#include <string>
#include <stdlib.h>

extern "C" {
  extern const char* GoCreateMili23(const char* curve, const char* session, const char* preParam);
  extern const char* GoSignMili23(const char* curve, const char* key, const char* msg);
  extern const char* GoReshareMili23(const char* curve, const char* session, const char* localkey, const char* preParam);
  extern void GoSetRequestEnv(const char* jsonEnv);
  extern const char* GoGwRequest(const char* method, const char* header, const char* path, const char* params, const char* payload);
  extern const char* GoBuildRequest(const char* aesKey, const char* method, const char* header, const char* path, const char* params, const char* payload);
  extern const char* GoLandResponse(const char* aesKey, const char* enResp);
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