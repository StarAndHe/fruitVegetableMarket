#include<stdbool.h>
typedef struct Stock                       //各类商品库存节点结构体
{
	char stuffName[20];             //商品名称
	char ProductUnit;              //商品单位 个/箱/千克
	float price;                     //单价
	float Remain;                   //现有库存
}StockArray;

typedef struct Trade                      //每条交易记录的结构体
{
	int ID;                      //交易号码
	char* Ttime;                   //交易时间
	float Number[10];           //该笔交易各类商品交易数，下标对应商品序号
	float Amount[10];          //该笔交易各类商品交易额，下标代表商品序号
	float Receive;          //收到金额
	float Change;              //找零金额
	float DiscountAmount;        //会员优惠金额
	int CustomerId;            //用户账号
	struct Trade* next;
}TradeList;


typedef struct Customer                    //每个顾客结构体
{
	int ID;                   //顾客编号
	float Left;              //卡内所剩金额
	bool  Members;             //是否为会员
	int Integral;           //会员积分
	struct Customer* next;
}CustomerList;