#include "stdio.h"
#include "block_priv.h"
#include "block_verify.h"

void create_block(char inputnums, char hash);
void add_block(int whichIndex);
void file_write ();
void pr_block ();
void print_all_Blocks();
int LengthList();

struct block_data {
	int index;//链条索引
	int id;//区块id
	int blkdata;//随机数据
	int timestamp;//时间戳
	char prehash[32];//前一个哈希
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

extern char mddigest[SHA256_DIGEST_LENGTH*2+1];