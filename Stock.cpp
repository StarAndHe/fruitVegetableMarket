#include"Stock.h"
#include"main_manu.h"
#include<stdlib.h>
#include"structs.h"
Stock* StockLog[10];
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
}

void AddStock()                //进货
{
    system("cls");
    char choose = 'y';
    while (choose == 'y')
    {
        system("cls");
        printf("请输入要增加的商品序号(返回上一级请按0):\n");
        printf("1.苹果   2.香蕉 3.橘子  4.菠菜 5.火龙果 6.老坛酸菜  7.葡萄  8.榴莲  9.白菜  10.萝卜\n");
        int stuffName;
        scanf("%d", &stuffName);
        while (stuffName < 1 || stuffName > 10)
        {   
            if (stuffName == 0)
            {
                StockManagementManu();
                return;
            }
            printf("请输入1到10的数字(返回上一级请按0):\n");
            scanf("%d", &stuffName);

        }
        printf("请输入要采购%s的数量(返回上一级请按0):\n", StockLog[stuffName-1]->stuffName);
        float stuffNum;
        scanf("%f",&stuffNum);
        while (stuffNum < 0)
        {
            if (stuffNum == 0)
            {
                AddStock();
                return;
            }
            printf("请输入大于零的数字(返回上一级请按0):\n");
            scanf("%f", &stuffNum);

        }
        StockLog[stuffName-1]->Remain += stuffNum;
        printf("添加成功,当前%s库存为%f%s,是否继续添加(y/n)?\n",StockLog[stuffName-1]->stuffName,StockLog[stuffName-1]->ProductUnit,StockLog[stuffName-1]->Remain);
        scanf("%c", &choose);
        scanf("%c", &choose);
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("请输入y/n(不区分大小写)\n");
            scanf("%c", &choose);
        }

    }
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
        printf("1.苹果   2.香蕉 3.橘子  4.菠菜 5.火龙果 6.老坛酸菜  7.葡萄  8.榴莲  9.白菜  10.萝卜\n");
        int stuffName;
        scanf("%d", &stuffName);
        while (stuffName < 1 || stuffName > 10)
        {
            if (stuffName == 0)
            {
                StockManagementManu();
                return;
            }
            printf("请输入1到10的数字(返回上一级请按0):\n");
            scanf("%d", &stuffName);

        }
        printf("请输入修改后%s的库存数量:",StockLog[stuffName-1]->stuffName);
        float stuffNum;
        scanf("%f", &stuffNum);
        while (stuffNum < 0)
        {
            if (stuffNum == 0)
            {
                AddStock();
                return;
            }
            printf("请输入大于零的数字(返回上一级请按0):\n");
            scanf("%f", &stuffNum);

        }
        StockLog[stuffName - 1]->Remain = stuffNum;
        printf("修改成功,当前%s库存为%f%s,是否继续修改(y/n)?\n", StockLog[stuffName - 1]->stuffName, StockLog[stuffName - 1]->Remain, StockLog[stuffName - 1]->ProductUnit);
        scanf("%c", &choose);
        scanf("%c", &choose);
        while (choose != 'y' && choose != 'Y' && choose != 'N' && choose != 'n')
        {
            printf("请输入y/n(不区分大小写)\n");
            scanf("%c", &choose);
        }


    }
    StockManagementManu();
}

void LogOutStock()     //返回上一级
{
    StockManagementManu();
}
void CheckStock()
{
    system("cls");
    printf("================ 库 存 信 息 ==================\n");
    printf("商品名称        单位         单价         现有库存\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s           %s           %f              %f\n", StockLog[i]->stuffName, StockLog[i]->ProductUnit, StockLog[i]->price, StockLog[i]->Remain);
    }
    printf("按y返回上一级(不区分大小写):");
    char choose;
    getchar();
    scanf("%c", &choose);
    getchar();
    while (choose != 'y' && choose!='Y')
    {
        printf("返回上一级请按y:");
        
        scanf("%c", &choose);
    }
    StockManagementManu();
}
void StockManagement()  //库存管理程序
{
    StockManagementManu();
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