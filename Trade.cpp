#include"Trade.h"
#include <stdlib.h>



void Load_TradeData()   //������ǰ���׼�¼��������
{

}

void TradeShowMenu() {
	printf("============== �������� ==============\n");
	printf("====                              ====\n");
	printf("====           1.�� ��            ====\n\n");
	printf("====           2.�� �� ��         ====\n");
	printf("====                              ====\n");
	printf("======================================\n");
	int tsm;
	printf("\n���������鿴�������ͣ�\n");
	scanf("%d", &tsm);
	if (tsm == 1)	MaiChu();

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
		printf("\n�����������������룬������һ��������8888\n");
		if (*n == 8888) break;
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
			break;
		}
		else {
			printf("\n��治�㣬����ѡ������������0��������������������1��\n");
			scanf("%d", &select);
			Deal01Error(&select);
			if (select == 8888) return;
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
		printf("\n��������������Ʒ������,����9999����ѡ��\n");
		scanf("%d", &tmp);//������ѡ������
		if (tmp == 9999) break;
		if (tmp == 8888) return;//������һ��
		while (tmp <= 0 || tmp > 10) {
			printf("\n�����������������룬������һ��������8888\n");
			scanf("%d", &tmp);
			if (tmp == 8888) return;
		}
		if (tmp == 9999) break;
		//printf("\n������������%s%s:\n", StockLog[tmp - 1]->ProductUnit, StockLog[tmp-1]->stuffName);
		GouWu(tmp, &num, &shoukuan);//�˴�����ҪSwitch
		
	}
	system("cls");
	printf("��ǰ�Ƿ��ڴ���������������1����������0\n");
	scanf("%d", &tmp);//�����ţ�ȷ���Ƿ�
	printf("�˿��Ƿ��ǻ�Ա�� ��������1����������0\n");

	scanf("%d", &tmp);//�����ţ�ȷ���Ƿ��ǻ�Ա
	if (tmp == 1) //�����򽫽�����0.9�������տ����
	{
		shoukuan *= 0.9f;
		//��Ա���ڽ����٣�������������������������������
	}
	

}