#include"Customer.h"
#include"structs.h"
#include"main_manu.h"


Customer* head;
Customer* tail;
Customer* cur = NULL;


void CustomerManagement()   //用户管理程序
{
	//主界面
	printf("============      用户管理      ============\n");

	printf("====                                    ====\n");
	printf("====           1.添加会员            ====\n\n");
	printf("====           2.显示所有会员            ====\n\n");
	printf("====           3.查询会员	            ====\n\n");
	printf("====           4.会员充值            ====\n");
	printf("====           5.删除会员	            ====\n\n");
	printf("====           6.退出	            ====\n\n");
	printf("====                                    ====\n");
	printf("============================================\n");
	int choose = 0;
	printf("请输入要进行的操作序号  :");
	do {
		scanf_s("%d", &choose);
		if (choose > 4 || choose < 1)
			printf("请输入正确的选项  :");
	} while (choose > 4 || choose < 1);
	switch (choose)
	{
	case 1:
		createCustomer();
		break;
	case 2:
		showCustomer();
		break;
	case 3:
		queryCustomer();
		break;
	case 4:
		increaseMoney();
		break;
	case 5:
		deleteCustomer();
		break;
	case 6:
		manu();
		break;
	}

}

void createCustomer() {
	FILE* fd;
	fd = fopen("Customer.txt", "a+");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		return;
	}
	cur = (Customer*)malloc(sizeof(Customer));
	printf("请输入会员号 ： ");
	int t_id;
	bool flag = false;
	do {
		flag = false;
		scanf("%d", &t_id);
		if (t_id < 0 || t_id>999999) {
			printf("请输入合法的会员号！！！");
			flag = true;
		}
	} while (flag);

	cur->Id = t_id;

	printf("请输入会员姓名 ： ");
	char t_name[20];
	bool flag = false;
	do {
		flag = false;
		scanf("%s", t_name);
		if (t_name[0] == '\0') {
			printf("请输入合法的会员姓名！！！");
			flag = true;
		}
	} while (flag);

	strcpy(cur->Name, t_name);

	//写入金额，初始金额
	printf("请输入初始充值金额 ： ");
	float t_money;
	bool flag = false;
	do {
		flag = false;
		scanf("%f", &t_money);
		if (t_money < 0 || t_money>999999) {
			printf("请输入合法的金额数！！！");
			flag = true;
		}
	} while (flag);

	cur->Money = t_money;

	fwrite(cur, sizeof(struct Customer), 1, fd);
	fclose(fd);
	printf(" 添加会员成功！");

}



void showCustomer() {

	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		return;
	}

	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		printf("会员号 ： %6d\n",cur->Id);
		printf("会员姓名 ： %s\n", cur->Name);
		printf("会员卡余额 ： %f\n", cur->Money);
		printf("**************\n");

	}

	fclose(fd);


}



void deleteCustomer() {
	int t_id;
	printf("请输入要删除的会员卡号 ：\n");
	
	bool flag = false;
	do {
		scanf("%d", &t_id);
		if (t_id < 0 || t_id > 999999) {
			printf("请输入合法的会员卡号！！！");
			flag = true;
		}
	}while(flag);
	

	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		return;
	}

	bool is_IN = false; //是否存在该会员号
	FILE* fp1 = fopen("temCustomer.txt", "r+");
	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		if (t_id!= cur->Id) {
			fwrite(cur, sizeof(struct Customer), 1, fp1);
		}
		else {
			is_IN = true;
		}
	}

	if (!is_IN) {
		printf("您输入的会员号不存在！！！");
		return;
	}

	fclose(fd);
	fclose(fp1);

	fp1 = fopen("temCustomer.txt", "r");
	fd = fopen("Customer.txt", "w+");

	while (fread(cur, sizeof(struct Customer), 1, fp1) != 0)
	{
		fwrite(cur, sizeof(struct Customer), 1, fd);
	}
	fclose(fd);
	fclose(fp1);

	CustomerManagement();

}


void queryCustomer() {

	int t_id;
	printf("请输入要查询的会员卡号 ：\n");

	bool flag = false;
	do {
		scanf("%d", &t_id);
		if (t_id < 0 || t_id > 999999) {
			printf("请输入合法的会员卡号！！！");
			flag = true;
		}
	} while (flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		return;
	}

	bool is_IN = false; //是否存在该会员号

	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		if (t_id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		printf("您输入的会员号不存在！！！");
		return;
	}
	else {
		printf("您查询的会员信息如下 ：\n");
		printf("会员号 ：\t %6d \n", cur->Id);
		printf("会员姓名 ：\t %s\n", cur->Name);
		printf("会员卡余额 ：\t %f\n", cur->Money);

	}

	fclose(fd);
	
	CustomerManagement();
}


void increaseMoney() {

	int t_id;
	printf("请输入要充值的会员卡号 ：\n");

	bool flag = false;
	do {
		scanf("%d", &t_id);
		if (t_id < 0 || t_id > 999999) {
			printf("请输入合法的会员卡号！！！");
			flag = true;
		}
	} while (flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		return;
	}

	bool is_IN = false; //是否存在该会员号

	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		if (t_id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		printf("您输入的会员号不存在！！！");
		return;
	}
	else {
		printf("您查询的会员信息如下 ：\n");
		printf("会员号 ：\t %6d \n", cur->Id);
		printf("会员姓名 ：\t %s\n", cur->Name);
		printf("会员卡余额 ：\t %f\n", cur->Money);
		printf("请输入充值金额 ： ");
		float t_money;
		bool flag = false;
		do {
			flag = false;
			scanf("%f", &t_money);
			if (t_money < 0 || t_money>999999) {
				printf("请输入合法的金额数！！！");
				flag = true;
			}
		} while (flag);

		cur->Money = t_money + cur->Money;
		printf(" 充值成功，当前余额为 %f\n",cur->Money);

	}

	fclose(fd);

	CustomerManagement();

}