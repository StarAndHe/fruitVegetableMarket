#include"Trade.h"



void Load_TradeData()   //������ǰ���׼�¼��������
{

}

void TradeManagement()  //���׹������
{

}

void PrintInfo() {
	
}

void MaiChu() {
	PrintInfo();//��ʾ��Ʒ������,����9999����
	int tmp;
	float shoukuan;
	printf("��������������Ʒ�������Լ�������������ѡ��������9999��\n");

	while (true)
	{
		scanf("%d", &tmp);//������ѡ������
		if (tmp == 9999) break;
		switch (tmp)
		{
		case 1://Ȼ��ѡ�񰴸����ǰ�����-������-��������-�����¿��
			
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