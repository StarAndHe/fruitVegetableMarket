#include"Trade.h"



void Load_TradeData()   //加载先前交易记录到链表中
{

}

void TradeManagement()  //交易管理程序
{
	MaiChu();
}

void PrintInfo() {
	printf("商场现有商品编号及种类如下：\n");
	for (int i = 0; i < 10; i++) {
		printf("%d%s ",i+1, StockLog[i]->stuffName);
	}
	printf("\n");
}

void Deal01Error(int n) {
	if (n != 0 && n != 1) {

	}
}

void MaiChu() {
	PrintInfo();//显示商品种类编号
	int tmp;
	float shoukuan=0.0f,num=0.0f;
	printf("\n请输入欲购买商品种类编号,输入9999结束选购\n");
	
	while (true)
	{
		scanf("%d", &tmp);//输入编号选择种类
		if (tmp == 9999) break;
		switch (tmp)
		{

		case 1://然后数量-》算出金额-》更新库存
			printf("\n请输入欲购买几%s%s:\n",StockLog[tmp]->ProductUnit,StockLog[tmp]->stuffName);
			scanf("%f", &num);
			if (StockLog[tmp]->Remain - num >= 0) {//若库存足够，则卖，不够则提示
				StockLog[tmp]->Remain -= num;
				shoukuan += num * StockLog[tmp]->price;
			}
			else {
				printf("\n库存不足，重新选择数量请输入0，重新输入种类请输入1：\n");

			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		default:
			printf("\n输入有误，请重新输入:");
			break;
		}
	}
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