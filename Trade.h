#pragma once
#include"structs.h"
#include<stdio.h>



extern TradeList* tradelist;

void Load_TradeData();   //加载先前交易记录到链表中

void TradeManagement();   //交易管理程序

void TradeShowMenu();

void DealError();

void MaiChu();

void PrintInfo();

