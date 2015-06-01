#include "ATM_class.h"
#include <iostream>
#include <string>
using namespace std;


//欢迎界面
void ATM::welcome()
{
	times = 0;
	cout << "          ★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★         " << endl;
	cout << "          ☆                                        ☆         " << endl;
	cout << "          ★                                        ★         " << endl;
	cout << "          ☆                                        ☆         " << endl;
	cout << "          ★     $欢迎使用XT银行ATM自动取款机       ★	      " << endl;
	cout << "          ☆                                        ☆         " << endl;
	cout << "          ★                                        ★         " << endl;
	cout << "          ☆                                        ☆         " << endl;
	cout << "          ★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★         " << endl;

	string num,    //卡号
		   pwd;   //密码

	do
	{
		cout << "请输入卡号： ";
		cin >> num;
		cout << "请输入密码： ";
		cin >> pwd;

		if (!check_passwd(num, pwd))
		{
			cout << "对不起！账号或密码有误，请重新输入账号和密码！" << endl;
			++times; //累计尝试输入次数
		}

		else
			functionshow();

	} while (times < 3);

	//输入次数超过3次，被锁定
	lock();
}


//核对输入账户和密码
bool ATM::check_passwd(const std::string user_id, const std::string pwd)
{
	if (user_id == cnsm.get_num() && pwd == cnsm.get_passwd())
		return true;
	else
		return false;
}


//修改密码
void ATM::change_passwd()
{
	string old_pwd, //旧密码 
		   pwd,new_pwd; //用于重复确认输入新密码
	//把屏幕渲染成淡红色
	//system("color 43");

	times = 0;
	do
	{
		cout << "请输入旧密码： ";
		cin >> old_pwd;

		if (!check_passwd(cnsm.get_num(), old_pwd)) //密码错误
		{
			cout << "对不起！密码错误，请重新输入！" << endl;
			++times;
		}
		else
			break;
	} while (times < 3);

	if (times == 3)
	{
		cout << "对不起，密码输入次数超过限制，您已被锁定." << endl;
		lock();
	}

	while (1)
	{
		cout << "请输入新密码： ";
		cin >> pwd;
		cout << "请再次输入密码： ";
		cin >> new_pwd;

		if (pwd == new_pwd)
			break;
	}

	cnsm.set_passwd(new_pwd);
	cout << "恭喜！密码修改成功，请牢记!" << endl;
	//system("color 43");
}


//用户取款
void ATM::fetchmoney()
{
	int choice;
	char ch = 'n';
	//system("color 43");

	cout << "★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★" << endl;
	cout << "☆    1)  **********************  100￥   **********************" << endl;
	cout << "☆    2)  **********************  200￥   **********************" << endl;
	cout << "☆    3)  **********************  500￥   **********************" << endl;
	cout << "☆    4)  **********************  1000￥   *********************" << endl;
	cout << "☆    5)  **********************  5000￥   *********************" << endl;
	cout << "★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★★☆☆★★☆☆★★☆☆★★☆☆★★☆☆★★" << endl;

	do
	{
		cout << "请输入您的取款选项： ";
		cin >> choice;
		switch (choice)
		{
		case 1 :
			if (cnsm.get_money() - 100 <= 0)
			{
				cout << "对不起！您的余额不足！是否重新选择？（Y or N）" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "恭喜，操作成功!" << endl;
				cnsm.set_money(100);
				break;
			}

		case 2 :
			if (cnsm.get_money() - 200 <= 0)
			{
				cout << "对不起！您的余额不足！是否重新选择？（Y or N）" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "恭喜，操作成功!" << endl;
				cnsm.set_money(200);
				break;
			}

		case 3 :
			if (cnsm.get_money() - 500 <= 0)
			{
				cout << "对不起！您的余额不足！是否重新选择？（Y or N）" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "恭喜，操作成功!" << endl;
				cnsm.set_money(500);
				break;
			}

		case 4 :
			if (cnsm.get_money() - 1000 <= 0)
			{
				cout << "对不起！您的余额不足！是否重新选择？（Y or N）" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cnsm.set_money(1000);
				cout << endl << "恭喜，操作成功!" << endl;
				break;
			}

		case 5 :
			if (cnsm.get_money() - 5000 <= 0)
			{
				cout << "对不起！您的余额不足！是否重新选择？（Y or N）" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "恭喜，操作成功!" << endl;
				cnsm.set_money(5000);
				break;
			}

		default:
			break;
		}
	} while (ch == 'y' || ch == 'Y');

	//system("color 32");
}


//获取用户基本信息
void ATM::get_information()
{
	//system("color 59");
	cout << "**********************************" << endl;
	cout << "*" << endl;
	cout << "*     卡号：    " << cnsm.get_num() << endl;
	cout << "*     姓名：    " << cnsm.get_name() << endl;
	cout << "*     余额：    " << cnsm.get_money() << endl;
	cout << "*" << endl;
	cout << "**********************************" << endl;
	//system("color 59");
}


//显示功能界面
void ATM::functionshow()
{
	system("cls");
	//system("color 84");
	int n = 0; //选择操作选项
	do
	{
		cout << "          ◆◆◇◇◆◆◇◇◆◆◇◇◆◆◇◇◆◆◇◇◆◆         " << endl;
		cout << "          ◇   请你输入相应的操作序号进行操作：    ◇         " << endl;
		cout << "          ◆1) 修改密码:                            ◆         " << endl;
		cout << "          ◇2) 取款:                                ◇         " << endl;
		cout << "          ◆3) 查询余额:                            ◆         " << endl;
		cout << "          ◇4) 退出系统:                            ◇         " << endl;
		cout << "          ◆                $ >\\                   ◆         " << endl;
		cout << "          ◇◇◆◆◇◇◆◆◇◇◆◆◇◇◆◆◇◇◆◆◇◇         " << endl;
		cin >> n;
		while (n<1 || n>4)
		{
			cout << "请输入正确的操作序号!" << endl;
			cout << "$ >\\";
			cin >> n;
		}

		switch (n)
		{
			case 1:   change_passwd();
				break;

			case 2:   fetchmoney();
				break;

			case 3:   get_information();
				break;

			case 4:   exitATM();
				break;
		}

	} while (true);
	//system("color 84");
}


//被锁定
void ATM::lock()
{
	cout << endl << "对不起，由于你的操作有误，你的卡已经被没收! " << endl;
	exit(1);
}

//退出系统
void ATM::exitATM()
{
	system("cls");
	//system("color 16");
	cout << endl << "感谢你对本行的支持，欢迎下次光临!" << endl;
	cout << "请取卡……" << endl;
	//system("color 16");
	exit(0);
}


inline string consumer::get_name()
{
	return name;
}

inline string consumer::get_num()
{
	return num;
}

inline string consumer::get_passwd()
{
	return passwd;
}

inline float consumer::get_money()
{
	return money;
}

void consumer::set_passwd(const std::string &pw)
{
	passwd = pw;
}

void consumer::set_money(int m)
{
	money = money - m;
}