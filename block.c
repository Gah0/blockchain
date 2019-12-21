/* Gah0-blockchain born in 2019 */
#include "block.h"
#include "block_verify.h"
#include "sha256/sha256.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>

/*---------------------------------------------------------*/
	//如果没有区块

void create_block (char inputnums){
	struct block_data *block_head;

	static int index = 0;
	int id = 1;

	if (block_head == NULL){
		index++;

		block_head = malloc(sizeof(struct block_data));

		//sha256_hash((unsigned char*)"string", char buf, size_t);
		sha256_hash((unsigned char*)"", block_head->prehash, 32);

		block_head -> index = index;
		block_head -> id = id;
		block_head -> blkdata = inputnums;
		block_head -> timestamp = gettimeofday();
		file_write();
		return;
	}
}

//如果已经存在区块了
void add_block (int whichIndex; int inputnums){
	struct block_data *block_head;

	if (block_head == NULL){
		empty_failed();
		return;
	}

	struct block_data *currentblock = block_head;

	while(currentblock->next_block){
		currentblock = currentblock->next_block;
	}
		
	struct block_data *new_block = malloc(sizeof(struct block_data));

	currentblock->next_block = new_block;
	new_block -> index = whichIndex;
	new_block -> id = i + 1;
	new_block -> blkdata = inputnums;
	new_block -> timestamp = gettimeofday();

	//sha256_hash(unsigned char *buf, const unsigned char *data, size_t size)
	sha256_hash((unsigned char *)convert_str(currentblock), new_block->prehash, 32);
	file_write();
}


void file_write(){
	FILE *fp;
	int i;


	fp=fopen("/home/gah0/桌面/blockchain/data.txt", "wb");
	if (fp == NULL){
		printf("打开失败\n");
		exit(0);
	}

	fwrite(&block_head, sizeof(**block_data), 1, fp);//typedef 
	fclose(fp);
}

unsigned char *convert_str(struct block_data *blk){
	unsigned char *str = malloc(sizeof(unsigned char)*sizeof(blk));

	memcpy(str, &blk, sizeof(blk));
	return str;
}


void pr_hash (unsigned char hash[], int hashlen){
	int i;
	for (i=0; i<hashlen; i++){
		printf("%02x\n",hash[i]);
	}
}


void pr_block (struct block_data *blk){

	printf("%p", blk);//指针addr
	printf("Index:[%d]\n", block_head->hash);//链条
	printf("id:[%d]\n", block_head->hash);//区块id
	pr_hash(blk->prehash, sizeof(blk->prehash));
	printf("timestamp:[%s]", blk->timestamp);//时间戳
	printf("%p\n", block_head->next_block);//指针addr
}

void pr_all_Blocks(){
	struct block_data *currentblk = block_head;
	int count = 0;

	while(currentblk)
	{	
		pr_block(currentblk);
		currentblk = currentblk->next_block;
	}
}

//计算区块数量
int LengthList()
{
	struct block_data *len;
    int length = 0;
    if (block_head->next_block == NULL){
    	return 0;
    }
    else{
    	len = block_head -> next_block;
    	while(len){
    		length++;
    		len = len->next_block;
    	} 
    	return length;
    }
}
/*

智能合约部分
void trans(char sender; char receiver ; float money){
*/