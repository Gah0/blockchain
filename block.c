/* Gah0-blockchain born in 2019 */
#include "block.h"
#include "block_priv.h"
#include "block_verify.h"
#include "sha256/sha256.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
//

#define ID 1


/*---------------------------------------------------------*/
	//如果没有区块

void create_block (char inputhash){
	struct block_data *block_head;

	static int index = 0;
	int id = 0;

	id++;
	index++;

	if (block_head == NULL){
		block_head = malloc(sizeof(struct block_data));

		sha256hash(inputhash);

		block_head -> index = index;
		block_head -> id = ID;
		block_head -> timestamp = gettimeofday();
		block_head -> hash = mddigest;
		block_head -> prehash = NULL;
	}
	file_write();
	return;
}
	//如果已经存在区块了
void add_block (int whichIndex){
	struct block_data *block_head;
	char ph;

	if (block_head == NULL){
		empty_failed();
		return;
	}
		struct block_data *currentblock = block_head;
		while(currentblock->next_block){
			currentblock=currentblock->next_block;
		}

		struct block_data *new_block = malloc(sizeof(struct block_data));

		currentblock->next_block = new_block;

		ph = block_head -> prehash;
		sha256hash(ph);

		new_block -> index = whichIndex;
		new_block -> id = (block_head -> id) + 1;
		new_block -> timestamp = gettimeofday();
		new_block -> hash = mddigest;
		new_block -> prehash = (block_head -> hash);

		//sha256_hash(unsigned char *buf, const unsigned char *data, size_t size)
		file_write();
		return;
	}
}

void file_write(){
	struct block_data *block_head;
	struct block_data *currentblk = block_head;
	FILE *fp;
	int i;


	fp=fopen("/home/gah0/桌面/blockchain/data.txt", "wb");
	if (fp == NULL){
		printf("打开失败\n");
		exit(0);
	}

	while(currentblk){
		fp=fwrite(&block_head, sizeof(*block_head), 1, fp);
		currentblk = currentblk -> next_block;
	}
	fclose(fp);
}

void pr_block (){
	struct block_data *block_head;

	printf("%p", block_head);//指针
	printf("Index:[%s]", block_head->hash);
	printf("id:[%s]", block_head->hash);
	printf("timestamp:[%s]", block_head->timestamp);
	printf("prehash:[%s]", block_head->prehash);
	printf("hash:[%s]", block_head->hash);
//  show_hash(block->prehash, sizeof(block->prehash));
	printf("next block:[%s]", block_head->next_block);

}
void print_all_Blocks(){
	struct block_data *block_head;
	struct block_data *currentblk = block_head;
	int count = 0;

	while(currentblk)
	{	
		pr_block(currentblk);
		currentblk = currentblk->next_block;
	}
}
/*-------------------------------------------------------------------*/


/*

智能合约部分
void trans(char sender; char receiver ; float money){
	static int index = 0, id = 0;
	int i = 0;

	blk_data = (struct blk_data *)malloc(sizeof(struct blk_data));

	if(sender !=0)
	{
		[].trans=0
		[].trans=1
	}


	for (i=0, i<*head; i++){

	}

	if (block_data == NULL){

	}
	return block_data;
}
*/