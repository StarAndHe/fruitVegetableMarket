#include"Stock.h"
#include"main_manu.h"
#include<stdlib.h>
#include"structs.h"
Stock* StockLog[10];
void Load_StockData()  //���ļ��м�����ǰ�Ŀ���¼��������
{
    FILE* fp;
    if ((fp = fopen("stock.txt", "r")) == NULL)
    {
        printf("�����Ϣ��ȡʧ��\n");
        exit(0);
    }
    int i = 0;
    while (!feof(fp))
    {
        StockLog[i] = (struct Stock*)malloc(sizeof(struct Stock));
        fscanf(fp, "%s", StockLog[i]->stuffName);
        fscanf(fp, "%s", StockLog[i]->ProductUnit);
        fscanf(fp, "%f", &StockLog[i]->price);
        fscanf(fp, "%f", &StockLog[i]->Remain);
        i++;
    }
}

void AddStock()                //����
{

}

void ChangeStockCount()       //�޸Ŀ����Ϣ
{

}

void LogOutStock()     //������һ��
{

}
void CheckStock()
{
    printf("================ �� �� �� Ϣ ==================\n");
    printf("��Ʒ����        ��λ         ����         ���п��\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s           %s           %f              %f\n", StockLog[i]->stuffName, StockLog[i]->ProductUnit, StockLog[i]->price, StockLog[i]->Remain);
    }
}
void StockManagement()  //���������
{
    StockManagementManu();
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
        ChangeStockCount();
        break;
    case 4:
        LogOutStock();
        break;
    }
	


}