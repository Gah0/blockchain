#include "stdio.h"
#include "block.h"


void blockchain_menu (struct block_data *block_head){
	int choise = 0, n = 0, whichIndex = 0;
	char sender, recvier;
	char inputhash;
	float money = 0;

	printf("区块链应用<交易账>\t\n");
	printf("请输入小键盘数字操作\n");
	printf("(1)生成首个区块并保存\n(2)添加到区块下\n(3)输出区块链\n(4)验证区块链\n(5)破解链条\n");

	scanf("%d",&choise);

	do{
		switch(choise){
/*智能合约部分
			case 0:
				printf("请输入双方名称，以及金额数(such as "Ben,Jerry,50"):");
				scanf("%s,%s,%f",&sender, &recvier, &money)
				trans(sender,recvier,money);
				break;
*/
			case 1:
				printf("生成首个区块中(create_block)");
				printf("请输入你的hash值");
				scanf("%d",&inputhash);
				create_block(inputhash);
				break;
			case 2:
				printf("生成区块并添加到上一个区块上(add_block)");
				scanf("%d", &whichIndex);
				add_block(whichIndex);
				break;
			case 3:
				printf("打印所有区块:");
				print_all_Blocks();
				break;
			case 4:
				printf("请输入一个区块以检查在哪个链上:");//
				verifychain();
				break;
			default:
				printf("没有此功能！\n");
				break;
		}
	}while(1);
}

void empty_failed() {
	printf("请先生成首个区块");
}