#include "../include/password.h"

#include <openssl/sha.h>
#include <stdlib.h>
#include <string.h>

#define SAME_HEX 0

void calculateSHA256(char* text, unsigned char hash[SHA256_DIGEST_LENGTH]) {
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, text, strlen(text));
  SHA256_Final(hash, &sha256);
}

// Public
void initializeEncryptedPassword(EncryptedPassword* password, char* text) {
  password = malloc(SHA256_DIGEST_LENGTH * sizeof(unsigned char));
  calculateSHA256(text, *password);
}

bool checkCorrectPassword(EncryptedPassword password, char* text) {
  EncryptedPassword test_password;
  initializeEncryptedPassword(&test_password, text);
  return memcmp(password, test_password, SHA256_DIGEST_LENGTH) == SAME_HEX;
}