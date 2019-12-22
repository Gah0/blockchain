#include "stdio.h"

#define SHA256_DIGGEST_LENGTH 32

void verifychain();
void calculate_hash(unsigned char *str1, unsigned char *str2);
void pr_hash(unsigned char hash[], int hashlen);
