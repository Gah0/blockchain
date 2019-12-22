#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <openssl/crypto.h>

#define SHA256_DIGEST_LENGTH 32

void create_block(int inputnums);
void add_block(int whichIndex);
void file_write ();
void pr_block ();
void pr_all_Blocks();
int LengthList();

struct block_data {
	int index;//链条索引
	int id;//区块id
	int blkdata;//随机数据
	int timestamp;//时间戳
	char prehash[SHA256_DIGEST_LENGTH];//前一个哈希
	struct block_data *next_block;//链表结构
}*block_head;
