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

}

void ChangeStockCount()       //修改库存信息
{

}

void LogOutStock()     //返回上一级
{

}
void CheckStock()
{
    printf("================ 库 存 信 息 ==================\n");
    printf("商品名称        单位         单价         现有库存\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s           %s           %f              %f\n", StockLog[i]->stuffName, StockLog[i]->ProductUnit, StockLog[i]->price, StockLog[i]->Remain);
    }
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