#include<stdbool.h>
<<<<<<< HEAD
#include <string>
                       //������Ʒ���ڵ�ṹ��


typedef struct Stock                      //������Ʒ���ڵ�ṹ��
=======
typedef struct Stock                       //������Ʒ���ڵ�ṹ��
>>>>>>> a58cffbbc2a5a473813fef71bb8dbdf763e60e9d
{
	char stuffName[20];             //��Ʒ����
	char ProductUnit;              //��Ʒ��λ ��/��/ǧ��
	float price;                     //����
	float Remain;                   //���п��
}*StockArray;

typedef struct Trade                      //ÿ�����׼�¼�Ľṹ��
{
	int ID;                      //���׺���
	char* Ttime;                   //����ʱ��
	float Number[10];            //�ñʽ��׸�����Ʒ���������±��Ӧ��Ʒ���
	float Amount[10];            //�ñʽ��׸�����Ʒ���׶�±������Ʒ���
	float Receive;               //�յ����
	float Change;                //������
	float DiscountAmount;        //��Ա�Żݽ��
	int CustomerId;            //�û��˺�
	struct Trade* next;
}TradeList;


<<<<<<< HEAD

struct Customer                    //��Ա�ṹ��
=======
struct Customer                    //ÿ���˿ͽṹ��
>>>>>>> a58cffbbc2a5a473813fef71bb8dbdf763e60e9d
{
	int ID;                   //�˿ͱ��
	float Left;              //������ʣ���
	bool  Members;             //�Ƿ�Ϊ��Ա
	int Integral;           //��Ա����
	struct Customer* next;
}CustomerList;