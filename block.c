/* Gah0-blockchain born in 2019 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "block.h"
#include "block_priv.h"
#include "block_verify.h"
#include "sha256/sha256.h"
#include <sys/types.h>
//

#define ID 1


/*---------------------------------------------------------*/
	//如果没有区块
void create_block (char hash, char mddigest){

	static int index = 0;
	int id = 0;

	struct block_data *data, *temp;
	block_data = (struct block_data *)malloc(sizeof(struct block_data));

	sha256hash(hash);

	id++;
	index++;

	if (block_data == NULL){
		block_data -> index = index;
		block_data -> id = ID;
		block_data -> timestamp = 2019.12.23 12:00;
		block_data -> hash = mddigest;
		block_data -> prehash = NULL;
	}
	file_write();
	return;
}
	//如果已经存在区块了
void add_block (char hash, int whichIndex){
	FILE *fp;



	if (block_data != NULL){
		struct block_data *currentblock = block_head;
		while(currentblock->next_block){
			currentblock=currentblock->next_block;
		}

		struct block_data *newblock = malloc(sizeof(struct block));

		currentblock->next_block = newblock;

		sha256hash(block_data.prehash);

		new_block -> index = whichIndex;
		new_block -> id = block_head.id + 1;
		new_block -> timestamp = gettimeofday();
		new_block -> hash = block_data.prehash;
		new_block -> prehash = block_data.hash;

		//sha256_hash(unsigned char *buf, const unsigned char *data, size_t size)
		sha256_hash(block_data.prehash);
		file_write();
		return;
	}
}

void file_write(){
	FILE *fp;
	int i;
	struct block_data *currentblk = block_head;

	fp=fopen("/home/gah0/桌面/blockchain/data.txt", "wb");
	if (fp == NULL){
		printf("打开失败\n");
		exit(0);
	}

	while(currentblk){
		fp=fwrite(&block_head, sizeof(struct block_head), 1, fp);
		currentblk = currentblk -> next_block;
	}
	fclose(fp);
}

void print_block (struct block_data *block){
	printf("%p"，block);//指针
	printf("Index:[%s]",block->hash);
	printf("id:[%s]",block->hash);
	printf("timestamp:[%s]",block->timestamp);
	printf("prehash:[%s]",block->prehash);
	printf("hash:[%s]",block->hash);
//  show_hash(block->prehash, sizeof(block->prehash));
	printf("next block:[%s]",block->next_block);

}

void print_all_Blocks(){
	struct block_data *currentblk = block_head;
	int count = 0;

	while(currentblk)
	{	
		print_block(currentblk);
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