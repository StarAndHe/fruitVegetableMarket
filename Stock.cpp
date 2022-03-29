#include"Stock.h"
#include"main_manu.h"
#include<stdlib.h>
#include"structs.h"
Stock* StockLog[100];
int items = 0;
void Load_StockData()  //从文件中加载先前的库存记录到链表中
{
    FILE* fp;
    if ((fp = fopen("stock.txt", "r")) == NULL)
    {
        printf("库存信息读取失败\n");
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
    fclose(fp);
}
void newStuff()   //添加新商品
{
    items++;
    StockLog[items - 1] = (struct Stock*)malloc(sizeof(struct Stock));
    printf("请输入商品名(退出请按0):");
    scanf("%s", StockLog[items - 1]->stuffName);
    if (StockLog[items - 1]->stuffName[0] == '0')
    {
        free(StockLog[items - 1]);
        items--;
        AddStock();
        return;
    }

    printf("请输入商品单位(修改上一项请按#,退出请按0):");
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
    printf("请输入商品单价(退出请按0):");
    int flag= scanf("%f", &StockLog[items - 1]->price);  //flag用来判断输入书否为十进制树，是返回1，否则返回0
    NoEmpty();
    
   /* while (!flag)
    {
        if (StockLog[items - 1]->price == 16)
        {
            printf("请输入商品单位(退出请按0):");
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
            printf("请输入商品单价(要求正数,退出请按0):");
            flag = scanf("%f", &StockLog[items - 1]->price);
            NoEmpty();
        }

    printf("请输入进货数量(退出请按0):");

     flag = scanf("%f", &StockLog[items - 1]->Remain);  //flag用来判断输入书否为十进制树，是返回1，否则返回0
     NoEmpty();
        
    /*while (!flag)
    {
        if (StockLog[items - 1]->Remain == 16)
        {
            printf("请输入商品单价(退出请按0):");
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
            printf("请输入进货数(要求正数,退出请按0):");
            flag = scanf("%f", &StockLog[items - 1]->Remain);
            NoEmpty();
        }
    SaveStockItem();
}
void AddStock()                //进货
{
    system("cls");
    char choose = 'y';
    while (choose == 'y' || choose == 'Y')
    {
        system("cls");
        printf("请输入要增加的商品序号(返回上一级请按0):\n");
        for (int i = 0; i < items; i++)
            printf("%d.%s ", i+1, StockLog[i]->stuffName);
        printf("\n");
        printf("如果有新商品按100\n");
        int stuffName;
        int flag = scanf("%d", &stuffName);
        NoEmpty();
        while (!flag)
        {
           printf("请输入数字:");
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
            printf("请输入1到%d的数字(返回上一级请按0):\n",items);
            scanf("%d", &stuffName);
            NoEmpty();

        }
        printf("请输入要采购%s的数量(返回上一级请按0):\n", StockLog[stuffName-1]->stuffName);
        float stuffNum;
        flag = scanf("%f",&stuffNum);
        NoEmpty();
        while (!flag)
        {
            printf("请输入数字:");
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
            printf("请输入大于零的数字(返回上一级请按0):\n");
            scanf("%f", &stuffNum);
            NoEmpty();
        }
        StockLog[stuffName-1]->Remain += stuffNum;
        printf("添加成功,当前%s库存为%.2f%s,是否继续添加(y/n)?\n",StockLog[stuffName-1]->stuffName,StockLog[stuffName-1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        NoEmpty();
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("请输入y/n(不区分大小写)\n");
            scanf("%c", &choose);
            NoEmpty();
        }

    }
    SaveStockItem();
    StockManagementManu();
    
}

void ChangeStockCount()       //修改库存信息
{
    system("cls");
    char choose = 'y';
    while (choose == 'y' || choose == 'Y')
    {
        system("cls");
        printf("请输入要修改信息的商品编号(按0返回上一级):\n");
        for (int i = 0; i < items; i++)
            printf("%d.%s ", i + 1, StockLog[i]->stuffName);
        printf("\n");
        int stuffName;
        int flag = scanf("%d", &stuffName);
        NoEmpty();
        while (!flag)
        {
            printf("请输入数字:");
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
            printf("请输入1到%d的数字(返回上一级请按0):\n",items);
            scanf("%d", &stuffName);
            NoEmpty();
        }
        printf("请输入修改后%s的库存数量:",StockLog[stuffName-1]->stuffName);
        float stuffNum;
        flag = scanf("%f", &stuffNum);
        NoEmpty();
        while (!flag)
        {
            printf("请输入数字:");
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
            printf("请输入大于零的数字(返回上一级请按0):\n");
            scanf("%f", &stuffNum);
            NoEmpty();

        }
        StockLog[stuffName - 1]->Remain = stuffNum;
        printf("修改成功,当前%s库存为%.2f%s,是否继续修改(y/n)?\n", StockLog[stuffName - 1]->stuffName, StockLog[stuffName - 1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        NoEmpty();
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("请输入y/n(不区分大小写)\n");
            scanf("%c", &choose);
            NoEmpty();
        }


    }
    SaveStockItem();
    StockManagementManu();
}
void  NoEmpty()
{
    char ch;
    while ((ch = getchar()) != '\n')
    {

    }
}

void LogOutStock()     //返回上一级
{
    system("cls");
    manu();
}
void CheckStock()
{
    system("cls");
    printf("=================== 库 存 信 息 =====================\n");
    printf("商品名称         单位          单价          现有库存\n");
    printf("========         ====          ====          ========\n");
    for (int i = 0; i < items; i++)
    {
        printf("%8s   %10s    %10.2f      %10.2f\n", StockLog[i]->stuffName, StockLog[i]->ProductUnit, StockLog[i]->price, StockLog[i]->Remain);
    }
    printf("按y返回上一级(不区分大小写):");
    char choose;
    char ch;
    scanf("%c", &choose);
    NoEmpty();
    while (choose != 'y' && choose!='Y')
    {
        printf("返回上一级请按y:");
       
        scanf("%c", &choose);
        NoEmpty();
    }
    StockManagementManu();
}
void StockManagement()  //库存管理程序
{
    StockManagementManu();
}

void SaveStockItem()    //保存库存信息到文件中
{
    FILE* fp;
    if ((fp = fopen("stock.txt", "w")) == NULL)
    {
        printf("库存信息保存失败");
        return;
    }
    for (int i = 0; i < items - 1; i++)
    {
        fprintf(fp, "%10s", StockLog[i]->stuffName);
        fprintf(fp, "%10s", StockLog[i]->ProductUnit);
        fprintf(fp, "%10.2f", StockLog[i]->price);
        fprintf(fp, "%10.2f", StockLog[i]->Remain);
        fprintf(fp, "%c", '\n');
    }
    fprintf(fp, "%10s", StockLog[items - 1]->stuffName);
    fprintf(fp, "%10s", StockLog[items - 1]->ProductUnit);
    fprintf(fp, "%10.2f", StockLog[items - 1]->price);
    fprintf(fp, "%10.2f", StockLog[items - 1]->Remain);

    fclose(fp);
}
void StockManagementManu()
{
	system("cls");
	printf("==================库 存 管 理 ======================\n");
	printf("====                                            ====\n");
	printf("====            1.查 看 库 存                   ====\n\n");
	printf("====            2.进       货                   ====\n\n");
	printf("====            3.修 改 库 存                   ====\n\n");
	printf("====            4.返 回 上 一 级                ====\n\n");
	PrintTime();
    int choose = 0;
    printf("请输入要进行的操作序号（1-4）:");
    do {
        scanf_s("%d", &choose);
        NoEmpty();
        if (choose > 4 || choose < 1)
            printf("请输入正确的选项(如果要退出请按4)：");
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