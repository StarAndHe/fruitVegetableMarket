#include<stdbool.h>
#include <string.h>
struct Stock                       //������Ʒ���ڵ�ṹ��
{
	char stuffName[20];             //��Ʒ����
	char ProductUnit[20];              //��Ʒ��λ ��/��/ǧ��
	float price;                     //����
	float Remain;                   //���п��
};
extern Stock* StockLog[10];
struct Trade                      //ÿ�����׼�¼�Ľṹ��
{
	int ID;                      //���׺���
	char* Ttime;                   //����ʱ��
	float Number[10];           //�ñʽ��׸�����Ʒ���������±��Ӧ��Ʒ���
	float Amount[10];          //�ñʽ��׸�����Ʒ���׶�±������Ʒ���
	float Receive;          //�յ����
	float Change;              //������
	float DiscountAmount;        //��Ա�Żݽ��
	int CustomerId;            //�û��˺�
	struct Trade* next;
}TradeList;
extern Stock* StockLog[10];

struct Customer                    //��Ա�ṹ��
{
	int Id;                   //��Ա���
	char Name[20];			// ��Ա����
	float Money;              //������ʣ���
	struct Customer* next;
}*CustomerList;