#pragma once
#include<stdio.h>
#include"structs.h"

StockArray StockLog[10];

void Load_StockData();  //���ļ��м�����ǰ�Ŀ���¼��������

void StockManagement();  //���������


void StockManagementManu();     //������˵�

void CheckStock();               //��ʾ�����Ϣ

void AddStock();                //����

void ChangeStockCount();       //�޸Ŀ����Ϣ