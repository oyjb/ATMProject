#include <iostream>

//前置声明consumer类
class consumer;
class ATM
{
public:
	//ATM规定允许取款数目枚举
	enum withdraw
	{
		A = 100,
		B = 200,
		C = 500,
		D = 1000,
		E = 5000
	};

	//构造函数初始化
	ATM(consumer &cn) : cnsm(cn){}

	//登陆界面设计
	void welcome();

	//核对密码
	bool check_passwd(const std::string user_id, const std::string pwd);

	//修改密码
	void change_passwd();

	//取款
	void fetchmoney();

	//查询用户信息
	void get_information();

	//退出系统
	void exitATM();

	//功能界面
	void functionshow();

	//登陆次数超过一定次数锁定账户
	void lock();

private:
	//记录登陆次数，超过一定次数将被锁定
	int times = 0;

	//当前用户
	consumer &cnsm;
};


//用户类
class consumer
{
public:
	//把ATM声明为consumer的友元类
	friend class ATM;

	//构造函数
	consumer(const std::string &Name, const std::string &Num,
		float Money, std::string Passwd) : name(Name), num(Num), money(Money), passwd(Passwd) {}

	//获取姓名
	inline std::string get_name();

	//获取卡号
	std::string get_num();

	//获取密码
	std::string get_passwd();

	//获取余额
	float get_money();

	//设置密码
	void set_passwd(const std::string &pwd);

	//取钱,只允许取整百数额
	void set_money(int m);

private:
	//用户密码
	std::string passwd;

	//用户姓名
	std::string name;

	//卡号
	std::string num;

	//账户余额
	float money;
};