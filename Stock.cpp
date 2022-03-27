#include"Stock.h"
#include"main_manu.h"
#include<stdlib.h>
#include"structs.h"
Stock* StockLog[100];
int items = 0;
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
    items = i;
}
void newStuff()   //�������Ʒ
{
    items++;
    StockLog[items - 1] = (struct Stock*)malloc(sizeof(struct Stock));
    printf("��������Ʒ��(�˳��밴0):");
    scanf("%s", StockLog[items - 1]->stuffName);
    if (StockLog[items - 1]->stuffName[0] == '0')
    {
        free(StockLog[items - 1]);
        items--;
        AddStock();
        return;
    }

    printf("��������Ʒ��λ(�޸���һ���밴#,�˳��밴0):");
    scanf("%s", StockLog[items - 1]->ProductUnit);
    if (StockLog[items - 1]->ProductUnit[0] == '#')
    {
        free(StockLog[items - 1]);
        items--;
        newStuff();
    }
    if (StockLog[items - 1]->ProductUnit[0] == '0')
    {
        AddStock();
        return;
    }
    printf("��������Ʒ����(�����޸���һ���밴#,�˳��밴0):");
    int flag= scanf("%f", &StockLog[items - 1]->price);  //flag�����ж��������Ϊʮ���������Ƿ���1�����򷵻�0
    getchar();
    while (!flag)
    {
        if (StockLog[items - 1]->price == 16)
        {
            printf("��������Ʒ��λ(�˳��밴0):");
            scanf("%s", StockLog[items - 1]->ProductUnit);
            if (StockLog[items - 1]->ProductUnit[0] == '0')
            {
                AddStock();
                return;
            }
        }

        printf("��������Ʒ����(Ҫ������,�����޸���һ���밴#,�˳��밴0):");
        flag = scanf("%f", &StockLog[items - 1]->price);

    }

    printf("�������������(�����޸���һ���밴#,�˳��밴0):");

     flag = scanf("%f", &StockLog[items - 1]->Remain);  //flag�����ж��������Ϊʮ���������Ƿ���1�����򷵻�0
        
    while (!flag)
    {
        if (StockLog[items - 1]->Remain == 16)
        {
            printf("��������Ʒ����(�˳��밴0):");
            scanf("%f", &StockLog[items - 1]->price);
            if (StockLog[items - 1]->Remain == 0)
            {
                AddStock();
                return;
            }
        }
        printf("�����������(Ҫ������,�����޸���һ���밴#,�˳��밴0):");
        flag = scanf("%f", &StockLog[items - 1]->Remain);
    }
}
void AddStock()                //����
{
    system("cls");
    char choose = 'y';
    while (choose == 'y')
    {
        system("cls");
        printf("������Ҫ���ӵ���Ʒ���(������һ���밴0):\n");
        for (int i = 0; i < items; i++)
            printf("%d.%s ", i+1, StockLog[i]->stuffName);
        printf("\n");
        printf("���������Ʒ��11\n");
        int stuffName;
        scanf("%d", &stuffName);
        while (stuffName < 1 || stuffName > 10)
        {   
            if (stuffName == 0)
            {
                StockManagementManu();
                return;
            }
            if (stuffName == 11)
            {
                newStuff();
                AddStock();
            }
            printf("������1��10������(������һ���밴0):\n");
            scanf("%d", &stuffName);

        }
        printf("������Ҫ�ɹ�%s������(������һ���밴0):\n", StockLog[stuffName-1]->stuffName);
        float stuffNum;
        scanf("%f",&stuffNum);
        while (stuffNum < 0)
        {
            if (stuffNum == 0)
            {
                AddStock();
                return;
            }
            printf("����������������(������һ���밴0):\n");
            scanf("%f", &stuffNum);

        }
        StockLog[stuffName-1]->Remain += stuffNum;
        printf("��ӳɹ�,��ǰ%s���Ϊ%.2f%s,�Ƿ�������(y/n)?\n",StockLog[stuffName-1]->stuffName,StockLog[stuffName-1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        scanf("%c", &choose);
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("������y/n(�����ִ�Сд)\n");
            scanf("%c", &choose);
        }

    }
    StockManagementManu();
    
}

void ChangeStockCount()       //�޸Ŀ����Ϣ
{
    system("cls");
    char choose = 'y';
    while (choose == 'y' || choose == 'Y')
    {
        system("cls");
        printf("������Ҫ�޸���Ϣ����Ʒ���(��0������һ��):\n");
        printf("1.ƻ��   2.�㽶 3.����  4.���� 5.������ 6.��̳���  7.����  8.����  9.�ײ�  10.�ܲ�\n");
        int stuffName;
        scanf("%d", &stuffName);
        while (stuffName < 1 || stuffName > 10)
        {
            if (stuffName == 0)
            {
                StockManagementManu();
                return;
            }
            printf("������1��10������(������һ���밴0):\n");
            scanf("%d", &stuffName);

        }
        printf("�������޸ĺ�%s�Ŀ������:",StockLog[stuffName-1]->stuffName);
        float stuffNum;
        scanf("%f", &stuffNum);
        while (stuffNum < 0)
        {
            if (stuffNum == 0)
            {
                AddStock();
                return;
            }
            printf("����������������(������һ���밴0):\n");
            scanf("%f", &stuffNum);

        }
        StockLog[stuffName - 1]->Remain = stuffNum;
        printf("�޸ĳɹ�,��ǰ%s���Ϊ%.2f%s,�Ƿ�����޸�(y/n)?\n", StockLog[stuffName - 1]->stuffName, StockLog[stuffName - 1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        scanf("%c", &choose);
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("������y/n(�����ִ�Сд)\n");
            scanf("%c", &choose);
        }


    }
    StockManagementManu();
}

void LogOutStock()     //������һ��
{
    system("cls");
    manu();
}
void CheckStock()
{
    system("cls");
    printf("=================== �� �� �� Ϣ =====================\n");
    printf("��Ʒ����         ��λ          ����          ���п��\n");
    printf("========         ====          ====          ========\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%8s   %10s    %10.2f      %10.2f\n", StockLog[i]->stuffName, StockLog[i]->ProductUnit, StockLog[i]->price, StockLog[i]->Remain);
    }
    printf("��y������һ��(�����ִ�Сд):");
    char choose;
    getchar();
    scanf("%c", &choose);
    getchar();
    while (choose != 'y' && choose!='Y')
    {
        printf("������һ���밴y:");
        
        scanf("%c", &choose);
    }
    StockManagementManu();
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
        getchar();
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