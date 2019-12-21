#include "stdio.h"
#include "block_verify.h"

void create_block(char inputnums, char hash);
void add_block(int whichIndex);
void file_write ();
void pr_hash(unsigned char hash[], int hashlen);
void pr_block ();
void pr_all_Blocks();
int LengthList();

struct block_data {
	int index;//链条索引
	int id;//区块id
	int blkdata;//随机数据
	int timestamp;//时间戳
	char prehash;//前一个哈希
	struct block_data *next_block;//链表结构
}*block_head;
