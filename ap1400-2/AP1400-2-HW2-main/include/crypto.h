/* 
 * File： crypto.cpp
 * ----------------------------------------------------
 * This file serves as a cryptography library, designed for handling RSA encryption, signing and 
 * verification, as well as Base64 encoding and decoding.
 */

#ifndef CRYPTO_H
#define CRYPTO_H

#include <iostream>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <assert.h>

namespace crypto{

/* Function: createPrivateRSA, createPublicRSA
 * ----------------------------------------------------
 * These functions create the corresponding public key and the private key, and the 'key' parameter 
 * is a string representation the RSA key.
 */

  RSA* createPrivateRSA(std::string key);

  RSA* createPublicRSA(std::string key);

/* Function: RSASign
 * ----------------------------------------------------
 * This function generates an RSA key. We input the message 'Msg' and its length 'MsgLen', and 
 * sign the message using the private key 'rsa'. The signature is stored in 'EncMsg', and its 
 * length is returned in 'MsgLenEnc'.
 */

  bool RSASign( RSA* rsa,
                const unsigned char* Msg,
                size_t MsgLen,
                unsigned char** EncMsg,
                size_t* MsgLenEnc);

/* Function: RSAVerifySignature
 * ----------------------------------------------------
 * This function verifies an RSA key. We input hash message 'MsgHash', 'MsgHashLen'; raw message
 * 'Msg' and 'MsgLen', and store the authentic results in 'Authentic'.
 */

  bool RSAVerifySignature( RSA* rsa,
                          unsigned char* MsgHash,
                          size_t MsgHashLen,
                          const char* Msg,
                          size_t MsgLen,
                          bool* Authentic);

/* Function: Base64Encode
 * ----------------------------------------------------
 * Encode Binary data into Base64 strings.
 */

  void Base64Encode( const unsigned char* buffer,
                    size_t length,
                    char** base64Text);

/* Function: calcDecodeLength, Base64Decode
 * ----------------------------------------------------
 * Decode Binary data into Base64 strings, and calculate the length after decoding.
 */

  size_t calcDecodeLength(const char* b64input);

  void Base64Decode(const char* b64message, unsigned char** buffer, size_t* length);

  std::string signMessage(std::string privateKey, std::string plainText);

  bool verifySignature(std::string publicKey, std::string plainText, std::string signatureBase64);

  const char* keyFromRSA(RSA* rsa, bool isPrivate);

  void generate_key(std::string& public_key, std::string& private_key);

  std::string sha256(std::string s);

}
#endif //CRYPTO_H