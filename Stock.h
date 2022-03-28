#pragma once
#include<stdio.h>

extern int items;


void Load_StockData();  //从文件中加载先前的库存记录到链表中

void StockManagement();  //库存管理程序


void StockManagementManu();     //库存管理菜单

void CheckStock();               //显示库存信息

void AddStock();                //进货

void ChangeStockCount();       //修改库存信息

void LogOutStock();     //返回上一级

void  NoEmpty();    //排除多余字符