#include"Customer.h"
#include"structs.h"
#include"main_manu.h"
#include<malloc.h>
#include"Stock.h"
#include <stdlib.h>


Customer* head;
Customer* tail;
Customer* cur = (Customer*)malloc(sizeof(Customer));


void CustomerManagement()   //�û��������
{


	system("cls");//��ƶ��
	//������
	printf("========== �û����� ===========\n");

	printf("                              \t     \n");
	printf("           1.��ӻ�Ա           \t     \n");
	printf("           2.��ʾ���л�Ա       \t    \n");
	printf("           3.��ѯ��Ա	        \t     \n");
	printf("           4.��Ա��ֵ           \t     \n");
	printf("           5.ɾ����Ա	        \t     \n");
	printf("           6.�˳�	            \t     \n");
	printf("                                \t    \n");
	printf("============================================\n");
	int choose = 0;
	printf("������Ҫ���еĲ������  :");
	bool flag1 = false;
	do {
		flag1=scanf_s("%d", &choose);
		NoEmpty();
		if (choose > 6 || choose < 1)
			printf("��������ȷ��ѡ��  :");
	} while (!flag1 || choose > 6 || choose < 1);
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
		printf("�û��ļ���ʧ�ܣ�����");
		CustomerManagement();
	}
	cur = (Customer*)malloc(sizeof(Customer));
	printf("�������Ա�� �� ");
	int t_id;
	bool flag = false;
	bool flag2 = false;
	do {
		flag = false;
		flag2=scanf("%d", &t_id);
		NoEmpty();
		if (t_id < 0 || t_id>999999) {
			printf("������Ϸ��Ļ�Ա�ţ�����");
			flag = true;
		}
		if (find(t_id)) {
			printf("�û�Ա���Ѵ��ڣ����������룡����");
			flag = true;
		}
	} while (!flag2 || flag);

	cur->Id = t_id;

	printf("�������Ա���� �� ");
	char t_name[20];
	flag = false;
	do {
		flag = false;
		scanf("%s", t_name);
		if (t_name[0] == '\0') {
			printf("������Ϸ��Ļ�Ա����������");
			flag = true;
		}
	} while (flag);

	strcpy(cur->Name, t_name);

	//д�����ʼ���
	printf("�������ʼ��ֵ��� �� ");
	float t_money;
	flag = false;
	bool flag3 = false;
	do {
		flag = false;
		flag3 = scanf("%f", &t_money);
		NoEmpty();
		if (t_money < 0 || t_money>999999) {
			printf("������Ϸ��Ľ����������");
			flag = true;
		}
	} while (!flag3 || flag);

	cur->Money = t_money;

	//fwrite(cur, sizeof(struct Customer), 1, fd);

	fprintf(fd, "%30d", cur->Id);
	fprintf(fd, "%30s", cur->Name);
	fprintf(fd, "%30f", cur->Money);
	fprintf(fd, "\n");

	fclose(fd);
	printf(" ��ӻ�Ա�ɹ���");


	int choice = 0;
	bool bj = false;
	bool flag4 = false;
	do {
		bj = false;
		printf(" ��1������ӣ���2�����û�������棡");
		flag4 = scanf("%d", &choice);
		NoEmpty();
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while ( !flag4 || bj);

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
		printf("�û��ļ���ʧ�ܣ�����");
		CustomerManagement();
	}

	while (!feof(fd)) {
		fscanf(fd, "%d", &cur->Id);
		fscanf(fd, "%s", cur->Name);
		fscanf(fd, "%f", &cur->Money);
		fscanf(fd, "\n");
		printf("��Ա�� �� %d\n", cur->Id);
		printf("��Ա���� �� %s\n", cur->Name);
		printf("��Ա����� �� %f\n", cur->Money);
		printf("**************\n");

	}

	fclose(fd);


	int choice = 0;
	bool bj = false;
	bool flag4 = false;
	do {
		bj = false;
		printf(" ��2�����û�������棡");
		flag4 = scanf("%d", &choice);
		NoEmpty();
		if (choice != 2) {
			bj = true;
		}
	} while (!flag4 || bj);

	if (choice == 2) {
		CustomerManagement();
	}

}



void deleteCustomer() {
	system("cls");
	int t_id;
	printf("������Ҫɾ���Ļ�Ա���� ��\n");

	bool flag = false;
	bool flag1 = false;
	do {
		flag1 =scanf("%d", &t_id);
		NoEmpty();
		if (t_id < 0 || t_id > 999999) {
			printf("������Ϸ��Ļ�Ա���ţ�����");
			flag = true;
		}
	} while (!flag1 || flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		CustomerManagement();
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��

	FILE* remove;
	remove = fopen("temCustomer.txt", "w");
	fclose(remove);

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
		printf("������Ļ�Ա�Ų����ڣ�����");

		int choice = 0;
		bool bj = false;
		bool flag4 = false;
		do {
			bj = false;
			printf(" ��1����ɾ������2�����û�������棡");
			flag4 = scanf("%d", &choice);
			NoEmpty();
			if (choice != 1 && choice != 2) {
				bj = true;
			}
		} while (!flag4 || bj);

		if (choice == 1) {
			deleteCustomer();
		}
		if (choice == 2) {
			CustomerManagement();
		}

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


	FILE* remove1;
	remove1 = fopen("temCustomer.txt", "w");
	fclose(remove1);

	printf("ɾ���ɹ���");



	int choice = 0;
	bool bj = false;
	bool flag4 = false;
	do {
		bj = false;
		printf(" ��1����ɾ������2�����û�������棡");
		flag4 = scanf("%d", &choice);
		NoEmpty();
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (!flag4 || bj);

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
		printf("�û��ļ���ʧ�ܣ�����");
		CustomerManagement();
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��
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
	printf("������Ҫ��ѯ�Ļ�Ա���� ��\n");

	bool flag = false;
	bool flag1 = false;
	do {
		flag1 = scanf("%d", &t_id);
		NoEmpty();
		if (t_id < 0 || t_id > 999999) {
			printf("������Ϸ��Ļ�Ա���ţ�����");
			flag = true;
		}
	} while (!flag1 || flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		CustomerManagement();
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��
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
		printf("������Ļ�Ա�Ų����ڣ�����");
		fclose(fd);
		int choice = 0;
		bool bj = false;
		bool flag4 = false;
		do {
			bj = false;
			printf(" ��1������ѯ����2�����û�������棡");
			flag4 = scanf("%d", &choice);
			NoEmpty();
			if (choice != 1 && choice != 2) {
				bj = true;
			}
		} while (!flag4 || bj);

		if (choice == 1) {
			queryCustomer();
		}
		if (choice == 2) {
			CustomerManagement();
		}
		CustomerManagement();
	}
	else {
		printf("����ѯ�Ļ�Ա��Ϣ���� ��\n");
		printf("��Ա�� ��\t %d \n", cur->Id);
		printf("��Ա���� ��\t %s\n", cur->Name);
		printf("��Ա����� ��\t %f\n", cur->Money);

	}

	fclose(fd);


	int choice = 0;
	bool bj = false;
	bool flag4 = false;
	do {
		bj = false;
		printf(" ��1������ѯ����2�����û�������棡");
		flag4 = scanf("%d", &choice);
		NoEmpty();
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (!flag4 || bj);

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
	printf("������Ҫ��ֵ�Ļ�Ա���� ��\n");

	bool flag = false;
	bool flag1 = false;
	do {
		flag1 = scanf("%d", &t_id);
		NoEmpty();
		if (t_id < 0 || t_id > 999999) {
			printf("������Ϸ��Ļ�Ա���ţ�����");
			flag = true;
		}
	} while (! flag1 || flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		CustomerManagement();
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��

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
		printf("������Ļ�Ա�Ų����ڣ�����");

		int choice = 0;
		bool bj = false;
		bool flag4 = false;
		do {
			bj = false;
			printf(" ��1������ֵ����2�����û�������棡");
			flag4 = scanf("%d", &choice);
			NoEmpty();
			if (choice != 1 && choice != 2) {
				bj = true;
			}
		} while (!flag4 || bj);

		if (choice == 1) {
			increaseMoney();
		}
		if (choice == 2) {
			CustomerManagement();
		}

	}
	else {
		printf("����ֵ�Ļ�Ա��Ϣ���� ��\n");
		printf("��Ա�� ��\t %d \n", cur->Id);
		printf("��Ա���� ��\t %s\n", cur->Name);
		printf("��Ա����� ��\t %f\n", cur->Money);
		printf("�������ֵ��� �� ");
		float t_money;
		bool flag = false;
		bool flag2 = false;
		do {
			flag = false;
			flag2 = scanf("%f", &t_money);
			NoEmpty();
			if (t_money < 0 || t_money>999999) {
				printf("������Ϸ��Ľ����������");
				flag = true;
			}
		} while ( !flag2 ||flag);

		printf("��ֵ�˵Ľ� %f", t_money);
		printf("��ǰ�˻����Ϊ %f", cur->Money);
		lastMoney = t_money + cur->Money;
		printf(" ��ֵ�ɹ�����ǰ���Ϊ %f\n", lastMoney);
	}

	fclose(fd);

	fd = fopen("Customer.txt", "r");


	FILE* remove;
	remove = fopen("copyCustomer.txt", "w");
	fclose(remove);

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


	FILE* remove2;
	remove2 = fopen("copyCustomer.txt", "w");
	fclose(remove2);


	int choice = 0;
	bool bj = false;
	bool flag4 = false;
	do {
		bj = false;
		printf(" ��1������ֵ����2�����û�������棡");
		flag4 = scanf("%d", &choice);
		NoEmpty();
		if (choice != 1 && choice != 2) {
			bj = true;
		}
	} while (!flag4 || bj);

	if (choice == 1) {
		increaseMoney();
	}
	if (choice == 2) {
		CustomerManagement();
	}

}