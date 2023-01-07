import base64
import json
import ctypes
import logging

import requests

dll = ctypes.cdll.LoadLibrary
lib = dll('./build/lib/libwallet_core.so')

def Number2Base64(n):
    b = n.to_bytes(8, byteorder='big').lstrip(b'\0')
    if len(b) == 0:
        return base64.b64encode(bytes([0])).decode('utf-8')
    return base64.b64encode(b).decode('utf-8')

def GetCppStringResult(cppString):
    lib.TWStringUTF8Bytes.restype = ctypes.c_char_p
    result = lib.TWStringUTF8Bytes(cppString).decode('utf-8')
    lib.TWStringDelete(cppString)
    return result

def CheckAddress(address, coinId):
    print(lib.CppAddressIsValid(bytes(address, encoding='utf-8'), coinId))

def GetJsonRpcCall(method, params, callId):
    return {
        'jsonrpc': '2.0',
        'method': method,
        'id': callId,
        'params': params
    }

def EvmTransfer(chainId, fromAddress, toAddress, amount, key, rpcNodeList):
    paramCall = [
        GetJsonRpcCall('eth_gasPrice', [], 0),
        GetJsonRpcCall('eth_getTransactionCount', [fromAddress, 'latest'], 1)
    ]

    txParam = {}
    for rpcUrl in rpcNodeList:
        resp = requests.post(rpcUrl, json=paramCall)
        if resp.ok:
            for callResp in resp.json():
                callId = callResp['id']
                if callId == 0:
                    txParam['gasPrice'] = int(callResp['result'], 16)
                elif callId == 1:
                    txParam['nonce'] = int(callResp['result'], 16)
            break
    if not txParam:
        return 0, ''

    txInput = {
        'chainId': Number2Base64(chainId),
        'gasPrice': Number2Base64(txParam['gasPrice']),
        'gasLimit': Number2Base64(21000),
        'toAddress': toAddress,
        'nonce': Number2Base64(txParam['nonce']),
        'transaction': {
            'transfer': {
                'amount': Number2Base64(amount)
            }
        }
    }
    lib.CppJsonTransactionPrivateKey.restype = ctypes.c_void_p
    rawTx = GetCppStringResult(lib.CppJsonTransactionPrivateKey(bytes(json.dumps(txInput), encoding='utf-8'), bytes(key, encoding='utf-8'), 60))

    sendCall = GetJsonRpcCall('eth_sendRawTransaction', ['0x'+rawTx], 0)
    txHash = ''
    for rpcUrl in rpcNodeList:
        resp = requests.post(rpcUrl, json=sendCall)
        if resp.ok:
            res = resp.json()
            if 'result' in res:
                txHash = res['result'].get('hash', '')
            else:
                logging.error(res['error']['message'])
            break

    return txParam['nonce'], txHash

if __name__ == '__main__':
    chainId = 0 #链配置中获取
    fromAddress = '0x0038Eb06dd6C847ACE7A32B1b61831A77E06998C'
    toAddress = '0xa3b282ce9dafadbc6a6e1fe18f98ed3ad2859a05'
    amount = 1900000000000000 #0.0019
    key = '016320cf25f284d9a328abe7e9d4ff6d715734390e6acaa3338d52ab37e39093' #私钥
    rpcNodeList = [ #链配置中获取
        'https://polygon-rpc.com',
        'https://rpc.ankr.com/polygon'
    ]

    nonce, txHash = EvmTransfer(chainId, fromAddress, toAddress, amount, key, rpcNodeList)
    #txHash 唯一标记一笔交易，不同txHash 可能对应同一个nonce，同一个nonce的多个txHash中只有一个能成功
    print(nonce, txHash)
