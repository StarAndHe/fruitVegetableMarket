#include"Customer.h"
#include"structs.h"
#include"main_manu.h"
#include<malloc.h>
#include <stdlib.h>


Customer* head;
Customer* tail;
Customer* cur = (Customer*)malloc(sizeof(Customer));


void CustomerManagement()   //用户管理程序
{


	system("cls");//清贫；
	//主界面
	printf("========== 用户管理 ===========\n");

	printf("                              \t     \n");
	printf("           1.添加会员           \t     \n");
	printf("           2.显示所有会员       \t    \n");
	printf("           3.查询会员	        \t     \n");
	printf("           4.会员充值           \t     \n");
	printf("           5.删除会员	        \t     \n");
	printf("           6.退出	            \t     \n");
	printf("                                \t    \n");
	printf("============================================\n");
	int choose = 0;
	printf("请输入要进行的操作序号  :");
	do {
		scanf_s("%d", &choose);
		if (choose > 6 || choose < 1)
			printf("请输入正确的选项  :");
	} while (choose > 6 || choose < 1);
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
	system("cls");

	FILE* fd;
	fd = fopen("Customer.txt", "a+");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		CustomerManagement();
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
		if (find(t_id)) {
			printf("该会员卡已存在，请重新输入！！！");
			flag = true;
		}
	} while (flag);

	cur->Id = t_id;

	printf("请输入会员姓名 ： ");
	char t_name[20];
	flag = false;
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
	flag = false;
	do {
		flag = false;
		scanf("%f", &t_money);
		if (t_money < 0 || t_money>999999) {
			printf("请输入合法的金额数！！！");
			flag = true;
		}
	} while (flag);

	cur->Money = t_money;

	//fwrite(cur, sizeof(struct Customer), 1, fd);

	fprintf(fd, "%30d", cur->Id);
	fprintf(fd, "%30s", cur->Name);
	fprintf(fd, "%30f", cur->Money);
	fprintf(fd, "\n");

	fclose(fd);
	printf(" 添加会员成功！");


	int choice = 0;
	bool bj = false;
	do {
		bj = false;
		printf(" 按1继续添加，按2返回用户管理界面！");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (bj);

	if (choice == 1) {
		createCustomer();
	}
	if (choice == 2) {
		CustomerManagement();
	}

}



void showCustomer() {
	system("cls");

	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		CustomerManagement();
	}

	while (!feof(fd)) {
		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");
		printf("会员号 ： %d\n", cur->Id);
		printf("会员姓名 ： %s\n", cur->Name);
		printf("会员卡余额 ： %f\n", cur->Money);
		printf("**************\n");

	}

	fclose(fd);


	int choice = 0;
	bool bj = false;
	do {
		bj = false;
		printf(" 按2返回用户管理界面！");
		scanf("%d", &choice);
		if (choice != 2) {
			bj = true;
		}
	} while (bj);

	if (choice == 2) {
		CustomerManagement();
	}

}



void deleteCustomer() {
	system("cls");
	int t_id;
	printf("请输入要删除的会员卡号 ：\n");

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
		CustomerManagement();
	}

	bool is_IN = false; //是否存在该会员号
	FILE* fp1 = fopen("temCustomer.txt", "r+");
	while (!feof(fd)) {
		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");
		if (t_id != cur->Id) {

			fprintf(fp1, "%30d", cur->Id);
			fprintf(fp1, "%30s", cur->Name);
			fprintf(fp1, "%30f", cur->Money);
			fprintf(fp1, "\n");
		}
		else {
			is_IN = true;
		}
	}

	if (!is_IN) {
		printf("您输入的会员号不存在！！！");
		CustomerManagement();
	}

	fclose(fd);
	fclose(fp1);

	fp1 = fopen("temCustomer.txt", "r");
	fd = fopen("Customer.txt", "w+");

	while (!feof(fp1))
	{

		fscanf(fp1, "%d", &cur->Id);
		fscanf(fp1, "%s", cur->Name);
		fscanf(fp1, "%f", &cur->Money);
		fscanf(fp1, "\n");
		//fwrite(cur, sizeof(struct Customer), 1, fd);
		fprintf(fd, "%30d", cur->Id);
		fprintf(fd, "%30s", cur->Name);
		fprintf(fd, "%30f", cur->Money);
		fprintf(fd, "\n");

	}
	fclose(fd);
	fclose(fp1);


	FILE* remove;
	remove = fopen("temCustomer.txt", "w");
	fclose(remove);

	printf("删除成功！");



	int choice = 0;
	bool bj = false;
	do {
		bj = false;
		printf(" 按1继续删除，按2返回用户管理界面！");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (bj);

	if (choice == 1) {
		deleteCustomer();
	}
	if (choice == 2) {
		CustomerManagement();
	}

}




bool find(int id) {


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("用户文件打开失败！！！");
		CustomerManagement();
	}

	bool is_IN = false; //是否存在该会员号
	//fread(cur, sizeof(struct Customer), 1, fd) != 0
	while (!feof(fd)) {

		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");

		if (id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		fclose(fd);
		return false;
	}
	else {
		fclose(fd);
		return true;

	}




}

void queryCustomer() {
	system("cls");
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
		CustomerManagement();
	}

	bool is_IN = false; //是否存在该会员号
	//fread(cur, sizeof(struct Customer), 1, fd) != 0
	while (!feof(fd)) {

		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");

		if (t_id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		printf("您输入的会员号不存在！！！");
		CustomerManagement();
	}
	else {
		printf("您查询的会员信息如下 ：\n");
		printf("会员号 ：\t %d \n", cur->Id);
		printf("会员姓名 ：\t %s\n", cur->Name);
		printf("会员卡余额 ：\t %f\n", cur->Money);

	}

	fclose(fd);


	int choice = 0;
	bool bj = false;
	do {
		bj = false;
		printf(" 按1继续查询，按2返回用户管理界面！");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (bj);

	if (choice == 1) {
		queryCustomer();
	}
	if (choice == 2) {
		CustomerManagement();
	}
}


void increaseMoney() {
	system("cls");
	int t_id;
	float lastMoney = 0;
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
		CustomerManagement();
	}

	bool is_IN = false; //是否存在该会员号

	//fread(cur, sizeof(struct Customer), 1, fd) != 0
	while (!feof(fd)) {

		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");

		if (t_id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		printf("您输入的会员号不存在！！！");
		CustomerManagement();
	}
	else {
		printf("您充值的会员信息如下 ：\n");
		printf("会员号 ：\t %d \n", cur->Id);
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

		printf("充值了的金额： %f", t_money);
		printf("当前账户余额为 %f", cur->Money);
		lastMoney = t_money + cur->Money;
		printf(" 充值成功，当前余额为 %f\n", lastMoney);
	}

	fclose(fd);

	fd = fopen("Customer.txt", "r");
	FILE* fp1 = fopen("copyCustomer.txt", "r+");
	while (!feof(fd)) {
		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");
		if (t_id != cur->Id) {

			fprintf(fp1, "%30d", cur->Id);
			fprintf(fp1, "%30s", cur->Name);
			fprintf(fp1, "%30f", cur->Money);
			fprintf(fp1, "\n");
		}
		else {
			fprintf(fp1, "%30d", cur->Id);
			fprintf(fp1, "%30s", cur->Name);
			fprintf(fp1, "%30f", lastMoney);
			fprintf(fp1, "\n");

		}
	}
	fclose(fd);
	fclose(fp1);


	fp1 = fopen("copyCustomer.txt", "r");
	fd = fopen("Customer.txt", "w+");

	while (!feof(fp1))
	{

		fscanf(fp1, "%d", &cur->Id);
		fscanf(fp1, "%s", cur->Name);
		fscanf(fp1, "%f", &cur->Money);
		fscanf(fp1, "\n");
		//fwrite(cur, sizeof(struct Customer), 1, fd);
		fprintf(fd, "%30d", cur->Id);
		fprintf(fd, "%30s", cur->Name);
		fprintf(fd, "%30f", cur->Money);
		fprintf(fd, "\n");

	}
	fclose(fd);
	fclose(fp1);


	FILE* remove;
	remove = fopen("copyCustomer.txt", "w");
	fclose(remove);


	int choice = 0;
	bool bj = false;
	do {
		bj = false;
		printf(" 按1继续充值，按2返回用户管理界面！");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (bj);

	if (choice == 1) {
		increaseMoney();
	}
	if (choice == 2) {
		CustomerManagement();
	}

}