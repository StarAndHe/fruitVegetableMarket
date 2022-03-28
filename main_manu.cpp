#include"main_manu.h"
#include"Stock.h"
#include"Customer.h"
#include"Trade.h"
#include<Windows.h>
void manu()                             //主界面菜单
{
	printf("============3161 果蔬系统 ============\n");
	printf("====                                    ====\n");
	printf("====           1.库 存 管 理            ====\n\n");
	printf("====           2.用 户 管 理            ====\n\n");
	printf("====           3.交 易 记 录            ====\n\n");
	printf("====           4.退 出 系 统            ====\n");
	printf("====                                    ====\n");
	printf("============================================\n");
    PrintTime();
    int choose = 0;
    printf("请输入要进行的操作序号（1-4）:");
    int flag = scanf("%d", &choose);
    NoEmpty();
   while (!flag)
    {
        printf("请输入数字(1-4):");
        flag = scanf("%d", &choose);
        NoEmpty();
    }
    while(choose > 4 || choose < 1)
    {
            printf("请输入正确的选项(如果要退出请按4)：");
            scanf("%d", &choose);
            NoEmpty();

    } 
    switch (choose)
    {
    case 1:
        StockManagement();
        break;
    case 2:
        CustomerManagement();
        break;
    case 3:
        TradeManagement();
        break;
    case 4:
        LogOut();
        break;
    }
}

void PrintTime()                 //打印当前系统时间
{
    time_t timenow;
    struct tm* p;
    time(&timenow);
    p = gmtime(&timenow);

    printf("当为:%d年%d月%d日\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
    //printf("%d\n", p->tm_sec); /*获取当前秒*/
    //printf("%d\n", p->tm_min); /*获取当前分*/
    //printf("%d\n", 8 + p->tm_hour);/*获取当前时,这里获取西方的时间,刚好相差八个小时*/
    //printf("%d\n", p->tm_mday);/*获取当前月份日数,范围是1-31*/
    //printf("%d\n", 1 + p->tm_mon);/*获取当前月份,范围是0-11,所以要加1*/
    //printf("%d\n", 1900 + p->tm_year);/*获取当前年份,从1900开始，所以要加1900*/
    //printf("%d\n", p->tm_yday); /*从今年1月1日算起至今的天数，范围为0-365*/
}

void LogOut()
{
    printf("期待您的下次使用，保存数据中。。。。。。。\n");
    Sleep(500);
    SaveStockItem();
}

void SaveStockItem()    //保存库存信息到文件中
{
    FILE* fp;
    if ((fp = fopen("stock.txt", "w")) == NULL)
    {
        printf("库存信息保存失败");
        return;
    }
    for (int i = 0; i < items-1; i++)
    {
        fprintf(fp, "%10s", StockLog[i]->stuffName);
        fprintf(fp, "%10s", StockLog[i]->ProductUnit);
        fprintf(fp, "%10.2f", StockLog[i]->price);
        fprintf(fp, "%10.2f", StockLog[i]->Remain);
        fprintf(fp, "%c", '\n');
    }
    fprintf(fp, "%10s", StockLog[items-1]->stuffName);
    fprintf(fp, "%10s", StockLog[items - 1]->ProductUnit);
    fprintf(fp, "%10.2f", StockLog[items - 1]->price);
    fprintf(fp, "%10.2f", StockLog[items - 1]->Remain);

    fclose(fp);
}