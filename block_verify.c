/*区块链verify部分*/

#include "stdio.h"
#include "block.h"
#include "block_priv.h"
#include "block_verify.h"

void verifychain()
{
	int count = 1;

	if (block_head == NULL) {
		printf("不存在区块链，请新建两个以上的区块" );
		return;
	}
 	struct block_data *currentblk = block_head->next_block, *prehash = block_head;

 	while(current_block){
 		printf("%d\n[%d]\t", .count++, current_block->hash);
 		show_hash(SHA256_hash(toString(*prehash), sizeof(*prehash)));//转换为字符串类型，sizeof， null
		printf("*****************");
		show_hash(current_block->prevhash, SHA256_DIGEST_LENGTH);
		if(calculate_hash(SHA256_hash(toString(*prehash), sizeof(*prehash)), current_block->prevhash)) 
			printf("验证成功\n");
  		else 
  			printf("验证失败\n");

			prehash = current_block;
			current_block = current_block->next_block;
	}
}

void calculate_hash(unsigned char *str1, unsigned char *str2) {

    int i ;  
    for ( i = 0; i<SHA256SHA256_DIGEST_LENGTH; i++) {
    	if (str1[i] != str2[i]) 
    		return 0;
    }
    return 1;
}

void show_hash(unsigned char hash[]){
	int i;
	for (i=0; i<SHA256_DIGEST_LENGTH; i++)
		printf("%02x\n",hash[i]);
}