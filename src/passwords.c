#include "include/passwords.h"

#include <openssl/sha.h>
#include <stdlib.h>
#include <string.h>

void calculateSHA256(char* text, unsigned char hash[SHA256_DIGEST_LENGTH]) {
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, text, strlen(text));
  SHA256_Final(hash, &sha256);
}

// Public
EncryptedPassword newEncryptedPassword(char* text) {
  EncryptedPassword password = malloc(SHA256_DIGEST_LENGTH * sizeof(char));
  calculateSHA256(text, password);
  return password;
}

bool checkCorrectPassword(EncryptedPassword password, char* text) {
  EncryptedPassword test_password = newEncryptedPassword(text);
  return memcmp(password, test_password, SHA256_DIGEST_LENGTH) == 0;
}