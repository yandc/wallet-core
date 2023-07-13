/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_openblock_wallet_jni_WalletCore */

#ifndef _Included_com_openblock_wallet_jni_WalletCore
#define _Included_com_openblock_wallet_jni_WalletCore
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    CreateMili23
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_CreateMili23
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    ReshareMili23
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_ReshareMili23
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    GetAddress
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_GetAddress
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    GetPublicKey
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_GetPublicKey
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    VerifyAddress
 * Signature: (Ljava/lang/String;I)Z
 */
JNIEXPORT jboolean JNICALL Java_com_openblock_wallet_jni_WalletCore_VerifyAddress
  (JNIEnv *, jobject, jstring, jint);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    DecodeEvmCall
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_DecodeEvmCall
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    JsonTransactionMili23
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_JsonTransactionMili23
  (JNIEnv *, jobject, jstring, jstring, jstring, jint, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    SignMili23
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_SignMili23
  (JNIEnv *, jobject, jstring, jstring, jstring, jint, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    RawSignMili23
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_RawSignMili23
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    OfflineSignMili23
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_OfflineSignMili23
  (JNIEnv *, jobject, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    UtxoPlan
 * Signature: (ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_UtxoPlan
  (JNIEnv *, jobject, jint, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    DecryptShareKey
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_DecryptShareKey
  (JNIEnv *, jobject, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    EncryptShareKey
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_EncryptShareKey
  (JNIEnv *, jobject, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    SetRequestEnv
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_openblock_wallet_jni_WalletCore_SetRequestEnv
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    GwRequest
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_GwRequest
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    BuildRequest
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_BuildRequest
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    LandResponse
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_LandResponse
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_initChainConfig
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1initChainConfig
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getTransactionParams
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTransactionParams
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_dappJson
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1dappJson
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getEIP1559TokenParams
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getEIP1559TokenParams
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getTokenTxParams
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTokenTxParams
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getTxParams
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTxParams
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getSTCTxParams
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getSTCTxParams
  (JNIEnv *, jobject, jstring, jstring, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getEIP1559TxParams
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getEIP1559TxParams
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getTokenType
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTokenType
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_sendRawTransaction
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1sendRawTransaction
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getTransaction
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getTransaction
  (JNIEnv *, jobject, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_allBalance
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1allBalance
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getGasEstimate
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getGasEstimate
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_abiDecode
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1abiDecode
  (JNIEnv *, jobject, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_addressActive
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1addressActive
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getResourceActive
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getResourceActive
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getRpcURL
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getRpcURL
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_detectNode
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1detectNode
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_setRpc
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1setRpc
  (JNIEnv *, jobject, jstring, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getSubTime
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getSubTime
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getNonce
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getNonce
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_getDirectTransfer
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1getDirectTransfer
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_identifyRiskAddress
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1identifyRiskAddress
  (JNIEnv *, jobject, jstring, jstring);

/*
 * Class:     com_openblock_wallet_jni_WalletCore
 * Method:    chaindata_lookupDomain
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openblock_wallet_jni_WalletCore_chaindata_1lookupDomain
  (JNIEnv *, jobject, jstring, jstring);

#ifdef __cplusplus
}
#endif
#endif
