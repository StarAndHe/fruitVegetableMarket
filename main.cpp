#include<stdio.h>
#include<time.h>
#include"Stock.h"
#include"Customer.h"
#include"Trade.h"
#include"main_manu.h"
int main()
{
	Load_StockData();
	Load_TradeData();

	manu();
    
	return 0;
}