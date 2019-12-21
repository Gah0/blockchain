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

	
	printf("在%d链条上找到%d区块", whichIndex, LengthList());
	
	new_block -> index = whichIndex;
	new_block -> id = i + 1;
	new_block -> blkdata = inputnums;
	new_block -> timestamp = gettimeofday();

	//sha256_hash(unsigned char *buf, const unsigned char *data, size_t size)
	sha256_hash((unsigned char*)toString(currentblock), new_block->prehash, 32);
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