#include "stdio.h"
#include "sha256/sha256.h"

//可自定义字符数组长度和sha256_hash_size_t长度
//在该sha256加密库中
//sha256_hash(unsigned char *buf, const unsigned char *data, size_t size)
#define SHA256_DIGEST_LENGTH 32

void sha256hash(char inputhash);

extern char mddigest[SHA256_DIGEST_LENGTH*2+1];