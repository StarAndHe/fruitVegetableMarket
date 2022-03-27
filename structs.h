#include<stdbool.h>
#include <string.h>

typedef struct Ttime                      //每条交易记录的结构体
{
	int year,month,day;
	int hour, min, sec;
}Ttime;

struct Stock                       //各类商品库存节点结构体
{
	char stuffName[20];             //商品名称
	char ProductUnit[20];              //商品单位 个/箱/千克
	float price;                     //单价
	float Remain;                   //现有库存
};
extern Stock* StockLog[100];
typedef struct Trade                      //每条交易记录的结构体
{
	int ID;                      //交易号码
	Ttime t;                   //交易时间
	float Number[100];           //该笔交易各类商品交易数，下标对应商品序号
	float Amount[100];          //该笔交易各类商品交易额，下标代表商品序号
	float Receive;          //收到金额
	float Change;              //找零金额
	float DiscountAmount;        //优惠金额
	int CustomerId;            //会员账号
	struct Trade* next;
}TradeList;

typedef struct Customer                    //会员结构体
{
	int Id;                   //会员编号
	char Name[20];			// 会员姓名
	float Money;              //卡内所剩金额
	struct Customer* next;
}*CustomerList;