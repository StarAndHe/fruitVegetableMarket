#include<stdbool.h>
#include <string>
typedef struct Stock                       //������Ʒ���ڵ�ṹ��
{
	char stuffName[20];             //��Ʒ����
	char ProductUnit;              //��Ʒ��λ ��/��/ǧ��
	float price;                     //����
	float Remain;                   //���п��
}*StockArray;

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


struct Customer                    //��Ա�ṹ��
{
	std::string Name;			// �˿���Ϣ
	int ID;                   //��Ա��
	float Money;              //������ʣ���
}*CustomerList;