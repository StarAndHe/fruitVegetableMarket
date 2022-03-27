#include"Customer.h"
#include"structs.h"
#include"main_manu.h"


Customer* head;
Customer* tail;
Customer* cur = NULL;


void CustomerManagement()   //�û��������
{
	//������
	printf("============      �û�����      ============\n");

	printf("====                                    ====\n");
	printf("====           1.��ӻ�Ա            ====\n\n");
	printf("====           2.��ʾ���л�Ա            ====\n\n");
	printf("====           3.��ѯ��Ա	            ====\n\n");
	printf("====           4.��Ա��ֵ            ====\n");
	printf("====           5.ɾ����Ա	            ====\n\n");
	printf("====           6.�˳�	            ====\n\n");
	printf("====                                    ====\n");
	printf("============================================\n");
	int choose = 0;
	printf("������Ҫ���еĲ������  :");
	do {
		scanf_s("%d", &choose);
		if (choose > 4 || choose < 1)
			printf("��������ȷ��ѡ��  :");
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
		printf("�û��ļ���ʧ�ܣ�����");
		return;
	}
	cur = (Customer*)malloc(sizeof(Customer));
	printf("�������Ա�� �� ");
	int t_id;
	bool flag = false;
	do {
		flag = false;
		scanf("%d", &t_id);
		if (t_id < 0 || t_id>999999) {
			printf("������Ϸ��Ļ�Ա�ţ�����");
			flag = true;
		}
	} while (flag);

	cur->Id = t_id;

	printf("�������Ա���� �� ");
	char t_name[20];
	bool flag = false;
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
	bool flag = false;
	do {
		flag = false;
		scanf("%f", &t_money);
		if (t_money < 0 || t_money>999999) {
			printf("������Ϸ��Ľ����������");
			flag = true;
		}
	} while (flag);

	cur->Money = t_money;

	fwrite(cur, sizeof(struct Customer), 1, fd);
	fclose(fd);
	printf(" ��ӻ�Ա�ɹ���");

}



void showCustomer() {

	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		return;
	}

	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		printf("��Ա�� �� %6d\n",cur->Id);
		printf("��Ա���� �� %s\n", cur->Name);
		printf("��Ա����� �� %f\n", cur->Money);
		printf("**************\n");

	}

	fclose(fd);


}



void deleteCustomer() {
	int t_id;
	printf("������Ҫɾ���Ļ�Ա���� ��\n");
	
	bool flag = false;
	do {
		scanf("%d", &t_id);
		if (t_id < 0 || t_id > 999999) {
			printf("������Ϸ��Ļ�Ա���ţ�����");
			flag = true;
		}
	}while(flag);
	

	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		return;
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��
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
		printf("������Ļ�Ա�Ų����ڣ�����");
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
	printf("������Ҫ��ѯ�Ļ�Ա���� ��\n");

	bool flag = false;
	do {
		scanf("%d", &t_id);
		if (t_id < 0 || t_id > 999999) {
			printf("������Ϸ��Ļ�Ա���ţ�����");
			flag = true;
		}
	} while (flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		return;
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��

	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		if (t_id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		printf("������Ļ�Ա�Ų����ڣ�����");
		return;
	}
	else {
		printf("����ѯ�Ļ�Ա��Ϣ���� ��\n");
		printf("��Ա�� ��\t %6d \n", cur->Id);
		printf("��Ա���� ��\t %s\n", cur->Name);
		printf("��Ա����� ��\t %f\n", cur->Money);

	}

	fclose(fd);
	
	CustomerManagement();
}


void increaseMoney() {

	int t_id;
	printf("������Ҫ��ֵ�Ļ�Ա���� ��\n");

	bool flag = false;
	do {
		scanf("%d", &t_id);
		if (t_id < 0 || t_id > 999999) {
			printf("������Ϸ��Ļ�Ա���ţ�����");
			flag = true;
		}
	} while (flag);


	FILE* fd = fopen("Customer.txt", "r");
	if (fd == NULL) {
		printf("�û��ļ���ʧ�ܣ�����");
		return;
	}

	bool is_IN = false; //�Ƿ���ڸû�Ա��

	while (fread(cur, sizeof(struct Customer), 1, fd) != 0) {
		if (t_id == cur->Id) {
			is_IN = true;
			break;
		}
	}

	if (!is_IN) {
		printf("������Ļ�Ա�Ų����ڣ�����");
		return;
	}
	else {
		printf("����ѯ�Ļ�Ա��Ϣ���� ��\n");
		printf("��Ա�� ��\t %6d \n", cur->Id);
		printf("��Ա���� ��\t %s\n", cur->Name);
		printf("��Ա����� ��\t %f\n", cur->Money);
		printf("�������ֵ��� �� ");
		float t_money;
		bool flag = false;
		do {
			flag = false;
			scanf("%f", &t_money);
			if (t_money < 0 || t_money>999999) {
				printf("������Ϸ��Ľ����������");
				flag = true;
			}
		} while (flag);

		cur->Money = t_money + cur->Money;
		printf(" ��ֵ�ɹ�����ǰ���Ϊ %f\n",cur->Money);

	}

	fclose(fd);

	CustomerManagement();

}