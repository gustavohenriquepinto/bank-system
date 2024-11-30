#include "../include/password.h"

#include <openssl/evp.h>
#include <openssl/sha.h>
#include <stdlib.h>
#include <string.h>

#define SAME_HEX 0

void calculateSHA256(char* text, unsigned char hash[SHA256_DIGEST_LENGTH]) {
  EVP_MD_CTX* ctx = EVP_MD_CTX_new();
  EVP_DigestInit_ex(ctx, EVP_sha256(), NULL);
  EVP_DigestUpdate(ctx, text, strlen(text));
  EVP_DigestFinal_ex(ctx, hash, NULL);
  EVP_MD_CTX_free(ctx);
}

void passwordInitialize(EncryptedPassword* password, char* text) {
  *password = malloc(SHA256_DIGEST_LENGTH * sizeof(unsigned char));
  calculateSHA256(text, *password);
}

bool passwordIsCorrect(EncryptedPassword password, char* text) {
  EncryptedPassword test_password;
  passwordInitialize(&test_password, text);

  bool result =
      memcmp(password, test_password, SHA256_DIGEST_LENGTH) == SAME_HEX;
  free(test_password);

  return result;
}
