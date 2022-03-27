#include"Trade.h"
#include"Stock.h"
#include <stdlib.h>
#include"main_manu.h"

TradeList* tradelist = (TradeList*)calloc(1, sizeof(TradeList));
TradeList* rear = tradelist;
int id = 1;

void Load_TradeData()   //������ǰ���׼�¼��������
{
	items;
}

void TradeShowMenu() {
	printf("============== �������� ==============\n");
	printf("====                              ====\n");
	printf("====           1.�� ��            ====\n\n");
	printf("====           2.�� �� ��         ====\n");
	printf("====                              ====\n");
	printf("======================================\n");
	int tsm;
	printf("\n��ѡ�������ͣ�\n");
	scanf("%d", &tsm);
	if (tsm == 1) {
		system("cls");
		MaiChu();
	}

}

void TradeManagement()  //���׹������
{
	int flg;
	while (true)
	{
		system("cls");
		TradeShowMenu();
		printf("\n������һ��������8888");

	}
	
}

void PrintInfo() {
	printf("\n�̳�������Ʒ��ż��������£�\n\n");
	for (int i = 0; i < 10; i++) {
		printf("%d%s ",i+1, StockLog[i]->stuffName);
	}
	printf("\n");
}

void Deal01Error(int* n) {
	while (*n != 0 && *n != 1) {
		printf("\n������������������\n");
		//if (*n == 8888) break;
		scanf("%d", n);
		
	}
}

void GouWu(int tmp,float *num,float* shoukuan) {
	int select;
	while (true)
	{
		printf("\n������������%s%s:\n", StockLog[tmp - 1]->ProductUnit, StockLog[tmp - 1]->stuffName);
		scanf("%f", num);
		if ((StockLog[tmp - 1]->Remain - (*num)) >= 0) {//������㹻����������������ʾ
			StockLog[tmp - 1]->Remain -= (*num);
			(*shoukuan) += (*num) * (StockLog[tmp - 1]->price);
			TradeList* p = (TradeList*)calloc(1, sizeof(TradeList));
			p->Amount[tmp - 1] += (*num) * (StockLog[tmp - 1]->price);
			p->Number[tmp - 1] += *num;
			tradelist->next = p;
			rear = p;
			break;
		}
		else {
			printf("\n��治�㣬����ѡ������������0��������������������1��\n");
			scanf("%d", &select);
			Deal01Error(&select);
			//if (select == 8888) return;
			if (select == 1) break;
		}
	}
}

void MaiChu() {
	PrintInfo();//��ʾ��Ʒ������
	int tmp,select;
	float shoukuan=0.0f,num=0.0f;
	
	
	while (true)
	{
		printf("\n��������������Ʒ������,����ѡ��������9999\n");
		scanf("%d", &tmp);//������ѡ������
		if (tmp == 9999) break;
		//if (tmp == 8888) return;//������һ��
		while (tmp <= 0 || tmp > 10) {
			printf("\n�����������������룬����ѡ��������9999\n");
			scanf("%d", &tmp);
			if (tmp == 9999) break;
		}
		if (tmp == 9999) break;
		//printf("\n������������%s%s:\n", StockLog[tmp - 1]->ProductUnit, StockLog[tmp-1]->stuffName);
		GouWu(tmp, &num, &shoukuan);//�˴�����ҪSwitch
		
	}
	system("cls");

	float budazhe = shoukuan;

	printf("��ǰ�Ƿ��ڴ���������������1����������0\n");//������95��
	scanf("%d", &tmp);//�����ţ�ȷ���Ƿ�
	Deal01Error(&tmp);
	if (tmp == 8888) return;
	if (tmp == 1) {
		shoukuan *= 0.95;
	}

	printf("�˿��Ƿ��ǻ�Ա�� ��������1����������0\n");
	scanf("%d", &tmp);//�����ţ�ȷ���Ƿ��ǻ�Ա
	Deal01Error(&tmp);
	if (tmp == 8888) return;
	if (tmp == 1) //�����򽫽�����0.9�������տ����
	{
		shoukuan *= 0.9;
		//��Ա���ţ�������������������
		//��Ա���ڽ����٣�������������������������������
	}

	//TradeList* p = (TradeList*)calloc(1, sizeof(TradeList));
	printf("\n���ν����ܽ��Ϊ��%.2f\n\n", shoukuan);
	printf("�������տ��");
	scanf("%f", &rear->Receive);
	
	rear->Change = rear->Receive - shoukuan;
	printf("������Ϊ��%.2f\t", rear->Change);

	rear->DiscountAmount = budazhe - shoukuan;
	printf("�Żݽ��Ϊ��%.2f\n", rear->DiscountAmount);

	rear->ID = id;
	id++;

	time_t timenow;
	struct tm* t;
	time(&timenow);
	t = gmtime(&timenow);
	printf("���ν���ʱ��Ϊ:%d��%d��%d�� %dʱ%d��%d��\n\n", 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday,8+t->tm_hour,t->tm_min,t->tm_sec);
	

	system("pause");
}