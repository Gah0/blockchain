/*区块链加密*/

#include "stdio.h"
#include "block.h"
#include "block_priv.h"
#include "block_verify.h"
#include "sha256/sha256.h"

void sha256hash(char inputhash){
      int i = 0;
      char digest[SHA256_DIGEST_LENGTH];
      extern char mddigest[SHA256_DIGEST_LENGTH*2+1];

      sha256_t inputhash;
      sha256_init(&inputhash);
      sha256_update(&inputhash,((unsigned char *)toString(inputhash)), SHA256_DIGEST_LENGTH);
      sha256_final(&inputhash, digest);

      for (i=0; i<SHA256_DIGEST_LENGTH; i++){
      	sprintf(&mddigest[i*2], "%02x", (unsigned int)digest[i])
      }
      printf("sha256 digest: %s\n", mddigest);

}


