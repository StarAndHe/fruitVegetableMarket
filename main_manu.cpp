#include"main_manu.h"
#include"Stock.h"
#include"Customer.h"
#include"Trade.h"

void manu()                             //������˵�
{
	printf("============3161���߳��й���ϵͳ ============\n");
	printf("====                                    ====\n");
	printf("====           1.�� �� �� ��            ====\n\n");
	printf("====           2.�� �� �� ��            ====\n\n");
	printf("====           3.�� �� �� ¼            ====\n\n");
	printf("====           4.�� �� ϵ ͳ            ====\n");
	printf("====                                    ====\n");
	printf("============================================\n");
    PrintTime();
    int choose = 0;
    printf("������Ҫ���еĲ������(1-4):");
    do {
        scanf_s("%d", &choose);
        if (choose > 4 || choose < 1)
            printf("��������ȷ��ѡ��(���Ҫ�˳��밴4)��");
    } while (choose > 4 || choose < 1);
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

void PrintTime()                 //��ӡ��ǰϵͳʱ��
{
    time_t timenow;
    struct tm* p;
    time(&timenow);
    p = gmtime(&timenow);

    printf("��Ϊ:%d��%d��%d��\n",1900+p->tm_year,1+p->tm_mon,p->tm_mday);
    //printf("%d\n", p->tm_sec); /*��ȡ��ǰ��*/
    //printf("%d\n", p->tm_min); /*��ȡ��ǰ��*/
    //printf("%d\n", 8 + p->tm_hour);/*��ȡ��ǰʱ,�����ȡ������ʱ��,�պ����˸�Сʱ*/
    //printf("%d\n", p->tm_mday);/*��ȡ��ǰ�·�����,��Χ��1-31*/
    //printf("%d\n", 1 + p->tm_mon);/*��ȡ��ǰ�·�,��Χ��0-11,����Ҫ��1*/
    //printf("%d\n", 1900 + p->tm_year);/*��ȡ��ǰ���,��1900��ʼ������Ҫ��1900*/
    //printf("%d\n", p->tm_yday); /*�ӽ���1��1�������������������ΧΪ0-365*/
}

void LogOut()
{

}