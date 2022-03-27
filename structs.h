#include<stdbool.h>
#include <string.h>

typedef struct Ttime                      //ÿ�����׼�¼�Ľṹ��
{
	int year,month,day;
	int hour, min, sec;
}Ttime;

struct Stock                       //������Ʒ���ڵ�ṹ��
{
	char stuffName[20];             //��Ʒ����
	char ProductUnit[20];              //��Ʒ��λ ��/��/ǧ��
	float price;                     //����
	float Remain;                   //���п��
};
extern Stock* StockLog[100];
typedef struct Trade                      //ÿ�����׼�¼�Ľṹ��
{
	int ID;                      //���׺���
	Ttime t;                   //����ʱ��
	float Number[100];           //�ñʽ��׸�����Ʒ���������±��Ӧ��Ʒ���
	float Amount[100];          //�ñʽ��׸�����Ʒ���׶�±������Ʒ���
	float Receive;          //�յ����
	float Change;              //������
	float DiscountAmount;        //�Żݽ��
	int CustomerId;            //��Ա�˺�
	struct Trade* next;
}TradeList;

typedef struct Customer                    //��Ա�ṹ��
{
	int Id;                   //��Ա���
	char Name[20];			// ��Ա����
	float Money;              //������ʣ���
	struct Customer* next;
}*CustomerList;