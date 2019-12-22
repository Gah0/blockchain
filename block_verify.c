/*区块链verify部分*/

#include "block_verify.h"

unsigned char calculate_hash(unsigned char *str1, unsigned char *str2) {
    int i;  

    for ( i = 0; i<SHA256_DIGEST_LENGTH; i++) {
    	if (str1[i] != str2[i]) 
    		return 0;
    }
    return 1;
}

void pr_hash(unsigned char hash[], int hashlen){
	int i;

	for (i=0; i<hashlen; i++){
		printf("%02x\n",hash[i]);
	}
}

void verifychain(){
	int count = 1;

	if (block_head == NULL){
		printf("不存在区块链，请在一条链上生成两个以上的区块\n");
		return;
	}

	struct block_data *curr_blk = block_head->next_block; 
 	struct block_data *prevhash = block_head;

 	while(curr_blk)
 	{
 		printf("%d\n[%d]\t", count++, curr_blk->blkdata);
		//sha256_hash((unsigned char*)"string", char buf, size_t);
 		pr_hash(sha256_hash(convert_str(*prevhash), curr_blk->prevhash, sizeof(*prehash)));
		printf("*****************");
		pr_hash(curr_blk->prevhash, SHA256_DIGEST_LENGTH);
	
		if(calculate_hash(sha256_hash(convert_str(*prevhash), curr_blk->prevhash, SHA256_DIGEST_LENGTH)), sizeof(*prehash)){
			printf("验证成功, 该区块在链上\n");
			return;
		}else{
  			printf("验证失败，该区块不在链上\n");
  		}
		prevhash = curr_blk;
		curr_blk = curr_blk->next_block;
	}
}