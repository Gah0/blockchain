/*区块链加密*/

#include "stdio.h"
#include "block.h"
#include "sha256/sha256.h"

//可自定义字符数组长度和sha256_hash_size_t长度
//在该sha256加密库中
//sha256_hash(unsigned char *buf, const unsigned char *data, size_t size)
#define SHA256_DIGEST_LENGTH 32

void sha256hash(char hash, block_data.prehash){
      int i = 0;
      char digest[SHA256_DIGEST_LENGTH];
      char mddigest[SHA256_DIGEST_LENGTH*2+1]

      sha256_t hash;
      sha256_init(&hash);
      sha256_update(&hash,((unsigned char *)toString(hash)), SHA256_DIGEST_LENGTH);
      sha256_final(&hash, digest);

      for (i=0; i<SHA256_DIGEST_LENGTH; i++){
      	sprintf(&mddigest[i*2], "%02x", (unsigned int)digest[i])
      }
      printf("sha256 digest: %s\n", mddigest);

}


