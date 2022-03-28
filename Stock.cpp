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
        return;
    }
    if (StockLog[items - 1]->ProductUnit[0] == '0')
    {
        items--;
        AddStock();
        return;
    }
    printf("��������Ʒ����(�˳��밴0):");
    int flag= scanf("%f", &StockLog[items - 1]->price);  //flag�����ж��������Ϊʮ���������Ƿ���1�����򷵻�0
    NoEmpty();
    
   /* while (!flag)
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
       

    } */
  
    while (StockLog[items - 1]->price <= 0 || !flag)
        {
        if (StockLog[items - 1]->price == 0)
        {
            items--;
            AddStock();
            return;
        }
            printf("��������Ʒ����(Ҫ������,�˳��밴0):");
            flag = scanf("%f", &StockLog[items - 1]->price);
            NoEmpty();
        }

    printf("�������������(�˳��밴0):");

     flag = scanf("%f", &StockLog[items - 1]->Remain);  //flag�����ж��������Ϊʮ���������Ƿ���1�����򷵻�0
     NoEmpty();
        
    /*while (!flag)
    {
        if (StockLog[items - 1]->Remain == 16)
        {
            printf("��������Ʒ����(�˳��밴0):");
            scanf("%f", &StockLog[items - 1]->price);
            NoEmpty();
            if (StockLog[items - 1]->Remain == 0)
            {
                AddStock();
                return;
            }
        }
        
    }*/
    while (StockLog[items - 1]->Remain <= 0 || !flag)
        {
        if (StockLog[items - 1]->Remain == 0)
        {
            items--;
            AddStock();
            return;
        }
            printf("�����������(Ҫ������,�˳��밴0):");
            flag = scanf("%f", &StockLog[items - 1]->Remain);
            NoEmpty();
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
        printf("���������Ʒ��100\n");
        int stuffName;
        int flag = scanf("%d", &stuffName);
        NoEmpty();
        while (!flag)
        {
           printf("����������:");
           flag = scanf("%d", &stuffName);
           NoEmpty();
        }
        while (stuffName < 1 || stuffName > items)
        {   
            if (stuffName == 0)
            {
                StockManagementManu();
                return;
            }
            if (stuffName == 100)
            {
                newStuff();
                AddStock();
                return;
            }
            printf("������1��%d������(������һ���밴0):\n",items);
            scanf("%d", &stuffName);
            NoEmpty();

        }
        printf("������Ҫ�ɹ�%s������(������һ���밴0):\n", StockLog[stuffName-1]->stuffName);
        float stuffNum;
        flag = scanf("%f",&stuffNum);
        NoEmpty();
        while (!flag)
        {
            printf("����������:");
            flag = scanf("%f", &stuffNum);
            NoEmpty();
        }
        while (stuffNum < 0)
        {
            if (stuffNum == 0)
            {
                AddStock();
                return;
            }
            printf("����������������(������һ���밴0):\n");
            scanf("%f", &stuffNum);
            NoEmpty();
        }
        StockLog[stuffName-1]->Remain += stuffNum;
        printf("��ӳɹ�,��ǰ%s���Ϊ%.2f%s,�Ƿ�������(y/n)?\n",StockLog[stuffName-1]->stuffName,StockLog[stuffName-1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        NoEmpty();
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("������y/n(�����ִ�Сд)\n");
            scanf("%c", &choose);
            NoEmpty();
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
        for (int i = 0; i < items; i++)
            printf("%d.%s ", i + 1, StockLog[i]->stuffName);
        printf("\n");
        int stuffName;
        int flag = scanf("%d", &stuffName);
        NoEmpty();
        while (!flag)
        {
            printf("����������:");
            flag = scanf("%d", &stuffName);
            NoEmpty();
        }
        while (stuffName < 1 || stuffName > items)
        {
            if (stuffName == 0)
            {
                StockManagementManu();
                return;
            }
            printf("������1��%d������(������һ���밴0):\n",items);
            scanf("%d", &stuffName);
            NoEmpty();
        }
        printf("�������޸ĺ�%s�Ŀ������:",StockLog[stuffName-1]->stuffName);
        float stuffNum;
        flag = scanf("%f", &stuffNum);
        NoEmpty();
        while (!flag)
        {
            printf("����������:");
            flag = scanf("%f", &stuffNum);
            NoEmpty();
        }
        while (stuffNum < 0)
        {
            if (stuffNum == 0)
            {
                AddStock();
                return;
            }
            printf("����������������(������һ���밴0):\n");
            scanf("%f", &stuffNum);
            NoEmpty();

        }
        StockLog[stuffName - 1]->Remain = stuffNum;
        printf("�޸ĳɹ�,��ǰ%s���Ϊ%.2f%s,�Ƿ�����޸�(y/n)?\n", StockLog[stuffName - 1]->stuffName, StockLog[stuffName - 1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        NoEmpty();
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("������y/n(�����ִ�Сд)\n");
            scanf("%c", &choose);
            NoEmpty();
        }


    }
    StockManagementManu();
}
void  NoEmpty()
{
    char ch;
    while ((ch = getchar()) != '\n')
    {

    }
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
    for (int i = 0; i < items; i++)
    {
        printf("%8s   %10s    %10.2f      %10.2f\n", StockLog[i]->stuffName, StockLog[i]->ProductUnit, StockLog[i]->price, StockLog[i]->Remain);
    }
    printf("��y������һ��(�����ִ�Сд):");
    char choose;
    char ch;
    scanf("%c", &choose);
    NoEmpty();
    while (choose != 'y' && choose!='Y')
    {
        printf("������һ���밴y:");
       
        scanf("%c", &choose);
        NoEmpty();
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