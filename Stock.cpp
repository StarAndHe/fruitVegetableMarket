#include"Stock.h"
#include"main_manu.h"
#include<stdlib.h>
void Load_StockData()  //���ļ��м�����ǰ�Ŀ���¼��������
{

}

void StockManagement()  //���������
{
	
}


void StockManagementManu()
{
	system("cls");
	printf("==================�� �� �� �� ======================\n");
	printf("====                                            ====\n");
	printf("====            1.�� �� �� ��                   ====\n\n");
	printf("====            2.��       ��                   ====\n\n");
	printf("====            3.�� �� �� ��                   ====\n\n");
	printf("====            4.�� �� �� һ ��                ====\n\n");
	PrintTime();
    int choose = 0;
    printf("������Ҫ���еĲ�����ţ�1-4��:");
    do {
        scanf_s("%d", &choose);
        if (choose > 4 || choose < 1)
            printf("��������ȷ��ѡ��(���Ҫ�˳��밴4)��");
    } while (choose > 4 || choose < 1);
    switch (choose)
    {
    case 1:
        CheckStock();
        break;
    case 2:
        AddStock();
        break;
    case 3:
        TradeManagement();
        break;
    case 4:
        LogOut();
        break;
    }
	


}