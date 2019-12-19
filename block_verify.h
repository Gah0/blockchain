#include "stdio.h"
#include "block.h"

void verifychain();
void calculate_hash(unsigned char *str1, unsigned char *str2);
void show_hash(unsigned char hash[], int SHA256_DIGEST_LENGTH);