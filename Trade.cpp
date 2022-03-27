#include"Trade.h"
#include <stdlib.h>



void Load_TradeData()   //加载先前交易记录到链表中
{

}

void TradeShowMenu() {
	printf("============== 交易类型 ==============\n");
	printf("====                              ====\n");
	printf("====           1.购 物            ====\n\n");
	printf("====           2.退 换 货         ====\n");
	printf("====                              ====\n");
	printf("======================================\n");
	int tsm;
	printf("\n请输入欲查看交易类型：\n");
	scanf("%d", &tsm);
	if (tsm == 1)	MaiChu();

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
		printf("\n输入有误，请重新输入，返回上一级请输入8888\n");
		if (*n == 8888) break;
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
			break;
		}
		else {
			printf("\n库存不足，重新选择数量请输入0，重新输入种类请输入1：\n");
			scanf("%d", &select);
			Deal01Error(&select);
			if (select == 8888) return;
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
		printf("\n请输入欲购买商品种类编号,输入9999结束选购\n");
		scanf("%d", &tmp);//输入编号选择种类
		if (tmp == 9999) break;
		if (tmp == 8888) return;//返回上一级
		while (tmp <= 0 || tmp > 10) {
			printf("\n输入有误，请重新输入，返回上一级请输入8888\n");
			scanf("%d", &tmp);
			if (tmp == 8888) return;
		}
		if (tmp == 9999) break;
		//printf("\n请输入欲购买几%s%s:\n", StockLog[tmp - 1]->ProductUnit, StockLog[tmp-1]->stuffName);
		GouWu(tmp, &num, &shoukuan);//此处不需要Switch
		
	}
	system("cls");
	printf("当前是否处于促销季，若是输入1，否则输入0\n");
	scanf("%d", &tmp);//输入编号，确定是否
	printf("顾客是否是会员？ 若是输入1，否则输入0\n");

	scanf("%d", &tmp);//输入编号，确定是否是会员
	if (tmp == 1) //若是则将金额乘以0.9，否则收款金额不变
	{
		shoukuan *= 0.9f;
		//会员卡内金额减少？？？？？？？？？？？？？？？？
	}
	

}