#include"Trade.h"



void Load_TradeData()   //������ǰ���׼�¼��������
{

}

void TradeManagement()  //���׹������
{
	MaiChu();
}

void PrintInfo() {
	printf("�̳�������Ʒ��ż��������£�\n");
	for (int i = 0; i < 10; i++) {
		printf("%d%s ",i+1, StockLog[i]->stuffName);
	}
	printf("\n");
}

void Deal01Error(int n) {
	if (n != 0 && n != 1) {

	}
}

void MaiChu() {
	PrintInfo();//��ʾ��Ʒ������
	int tmp;
	float shoukuan=0.0f,num=0.0f;
	printf("\n��������������Ʒ������,����9999����ѡ��\n");
	
	while (true)
	{
		scanf("%d", &tmp);//������ѡ������
		if (tmp == 9999) break;
		switch (tmp)
		{

		case 1://Ȼ������-��������-�����¿��
			printf("\n������������%s%s:\n",StockLog[tmp]->ProductUnit,StockLog[tmp]->stuffName);
			scanf("%f", &num);
			if (StockLog[tmp]->Remain - num >= 0) {//������㹻����������������ʾ
				StockLog[tmp]->Remain -= num;
				shoukuan += num * StockLog[tmp]->price;
			}
			else {
				printf("\n��治�㣬����ѡ������������0��������������������1��\n");

			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		default:
			printf("\n������������������:");
			break;
		}
	}
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