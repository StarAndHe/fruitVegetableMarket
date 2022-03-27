#include"Trade.h"
#include"Stock.h"
#include <stdlib.h>
#include"main_manu.h"

TradeList* tradelist = (TradeList*)calloc(1, sizeof(TradeList));
TradeList* rear = tradelist;
int id = 1;

void Load_TradeData()   //加载先前交易记录到链表中
{
	items;
}

void TradeShowMenu() {
	printf("============== 交易类型 ==============\n");
	printf("====                              ====\n");
	printf("====           1.购 物            ====\n\n");
	printf("====           2.退 换 货         ====\n");
	printf("====                              ====\n");
	printf("======================================\n");
	int tsm;
	printf("\n请选择交易类型：\n");
	scanf("%d", &tsm);
	if (tsm == 1) {
		system("cls");
		MaiChu();
	}

}

void TradeManagement()  //交易管理程序
{
	int flg;
	while (true)
	{
		system("cls");
		TradeShowMenu();
		printf("\n返回上一级请输入8888");

	}
	
}

void PrintInfo() {
	printf("\n商场现有商品编号及种类如下：\n\n");
	for (int i = 0; i < 10; i++) {
		printf("%d%s ",i+1, StockLog[i]->stuffName);
	}
	printf("\n");
}

void Deal01Error(int* n) {
	while (*n != 0 && *n != 1) {
		printf("\n输入有误，请重新输入\n");
		//if (*n == 8888) break;
		scanf("%d", n);
		
	}
}

void GouWu(int tmp,float *num,float* shoukuan) {
	int select;
	while (true)
	{
		printf("\n请输入欲购买几%s%s:\n", StockLog[tmp - 1]->ProductUnit, StockLog[tmp - 1]->stuffName);
		scanf("%f", num);
		if ((StockLog[tmp - 1]->Remain - (*num)) >= 0) {//若库存足够，则卖，不够则提示
			StockLog[tmp - 1]->Remain -= (*num);
			(*shoukuan) += (*num) * (StockLog[tmp - 1]->price);
			TradeList* p = (TradeList*)calloc(1, sizeof(TradeList));
			p->Amount[tmp - 1] += (*num) * (StockLog[tmp - 1]->price);
			p->Number[tmp - 1] += *num;
			tradelist->next = p;
			rear = p;
			break;
		}
		else {
			printf("\n库存不足，重新选择数量请输入0，重新输入种类请输入1：\n");
			scanf("%d", &select);
			Deal01Error(&select);
			//if (select == 8888) return;
			if (select == 1) break;
		}
	}
}

void MaiChu() {
	PrintInfo();//显示商品种类编号
	int tmp,select;
	float shoukuan=0.0f,num=0.0f;
	
	
	while (true)
	{
		printf("\n请输入欲购买商品种类编号,结束选购请输入9999\n");
		scanf("%d", &tmp);//输入编号选择种类
		if (tmp == 9999) break;
		//if (tmp == 8888) return;//返回上一级
		while (tmp <= 0 || tmp > 10) {
			printf("\n输入有误，请重新输入，结束选购请输入9999\n");
			scanf("%d", &tmp);
			if (tmp == 9999) break;
		}
		if (tmp == 9999) break;
		//printf("\n请输入欲购买几%s%s:\n", StockLog[tmp - 1]->ProductUnit, StockLog[tmp-1]->stuffName);
		GouWu(tmp, &num, &shoukuan);//此处不需要Switch
		
	}
	system("cls");

	float budazhe = shoukuan;

	printf("当前是否处于促销季，若是输入1，否则输入0\n");//促销季95折
	scanf("%d", &tmp);//输入编号，确定是否
	Deal01Error(&tmp);
	if (tmp == 8888) return;
	if (tmp == 1) {
		shoukuan *= 0.95;
	}

	printf("顾客是否是会员？ 若是输入1，否则输入0\n");
	scanf("%d", &tmp);//输入编号，确定是否是会员
	Deal01Error(&tmp);
	if (tmp == 8888) return;
	if (tmp == 1) //若是则将金额乘以0.9，否则收款金额不变
	{
		shoukuan *= 0.9;
		//会员卡号？？？？？？？？？？
		//会员卡内金额减少？？？？？？？？？？？？？？？？
	}

	//TradeList* p = (TradeList*)calloc(1, sizeof(TradeList));
	printf("\n本次交易总金额为：%.2f\n\n", shoukuan);
	printf("请输入收款金额：");
	scanf("%f", &rear->Receive);
	
	rear->Change = rear->Receive - shoukuan;
	printf("找零金额为：%.2f\t", rear->Change);

	rear->DiscountAmount = budazhe - shoukuan;
	printf("优惠金额为：%.2f\n", rear->DiscountAmount);

	rear->ID = id;
	id++;

	time_t timenow;
	struct tm* t;
	time(&timenow);
	t = gmtime(&timenow);
	printf("本次交易时间为:%d年%d月%d日 %d时%d分%d秒\n\n", 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday,8+t->tm_hour,t->tm_min,t->tm_sec);
	

	system("pause");
}