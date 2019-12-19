#include "stdio.h"
#include "Gblock.h"
#include "verifyhash.h"

void create_block(char hash, char mddigest);
void add_block(char hash, int whichIndex);
void verifychain();
void hashPrinter(unsigned char hash[],int new_data);
int hashCompare (unsigned char *str1, unsigned char *str2 );
void print_all_Blocks();
void output_Block(struct block_data *b );

typedef struct block_data {
	int index;//链条索引
	int id;//区块id
	int timestamp;//时间戳
	char hash;//哈希
	char prehash;//前一个hash
	struct block_data *next_block;//链表结构
}*block_head;

/*-----------------------------------------*/
/*
typedef struct blk_data {
	char name;//每一个人都有一个独自链条
	int index;//链条索引
	int id;//区块id
	int timestamp;//时间戳
	char hash;//哈希
	char prehash;//前一个hash
	struct block_data *next_blk;//链表结构
}*head;
*/