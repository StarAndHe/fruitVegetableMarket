#include"Trade.h"



void Load_TradeData()   //加载先前交易记录到链表中
{

}

void TradeManagement()  //交易管理程序
{

}

void PrintInfo() {
	
}

void MaiChu() {
	PrintInfo();//显示商品种类编号,输入9999结束
	int tmp;
	float shoukuan;
	printf("请输入欲购买商品种类编号以及数量，若结束选购请输入9999：\n");

	while (true)
	{
		scanf("%d", &tmp);//输入编号选择种类
		if (tmp == 9999) break;
		switch (tmp)
		{
		case 1://然后选择按个买还是按箱买-》数量-》算出金额-》更新库存
			
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