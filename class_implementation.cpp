#include "ATM_class.h"
#include <iostream>
#include <string>
using namespace std;


//��ӭ����
void ATM::welcome()
{
	times = 0;
	cout << "          �����������������������         " << endl;
	cout << "          ��                                        ��         " << endl;
	cout << "          ��                                        ��         " << endl;
	cout << "          ��                                        ��         " << endl;
	cout << "          ��     $��ӭʹ��XT����ATM�Զ�ȡ���       ��	      " << endl;
	cout << "          ��                                        ��         " << endl;
	cout << "          ��                                        ��         " << endl;
	cout << "          ��                                        ��         " << endl;
	cout << "          �����������������������         " << endl;

	string num,    //����
		   pwd;   //����

	do
	{
		cout << "�����뿨�ţ� ";
		cin >> num;
		cout << "���������룺 ";
		cin >> pwd;

		if (!check_passwd(num, pwd))
		{
			cout << "�Բ����˺Ż��������������������˺ź����룡" << endl;
			++times; //�ۼƳ����������
		}

		else
			functionshow();

	} while (times < 3);

	//�����������3�Σ�������
	lock();
}


//�˶������˻�������
bool ATM::check_passwd(const std::string user_id, const std::string pwd)
{
	if (user_id == cnsm.get_num() && pwd == cnsm.get_passwd())
		return true;
	else
		return false;
}


//�޸�����
void ATM::change_passwd()
{
	string old_pwd, //������ 
		   pwd,new_pwd; //�����ظ�ȷ������������
	//����Ļ��Ⱦ�ɵ���ɫ
	//system("color 43");

	times = 0;
	do
	{
		cout << "����������룺 ";
		cin >> old_pwd;

		if (!check_passwd(cnsm.get_num(), old_pwd)) //�������
		{
			cout << "�Բ�������������������룡" << endl;
			++times;
		}
		else
			break;
	} while (times < 3);

	if (times == 3)
	{
		cout << "�Բ���������������������ƣ����ѱ�����." << endl;
		lock();
	}

	while (1)
	{
		cout << "�����������룺 ";
		cin >> pwd;
		cout << "���ٴ��������룺 ";
		cin >> new_pwd;

		if (pwd == new_pwd)
			break;
	}

	cnsm.set_passwd(new_pwd);
	cout << "��ϲ�������޸ĳɹ������μ�!" << endl;
	//system("color 43");
}


//�û�ȡ��
void ATM::fetchmoney()
{
	int choice;
	char ch = 'n';
	//system("color 43");

	cout << "������������������������������������������������������������������" << endl;
	cout << "��    1)  **********************  100��   **********************" << endl;
	cout << "��    2)  **********************  200��   **********************" << endl;
	cout << "��    3)  **********************  500��   **********************" << endl;
	cout << "��    4)  **********************  1000��   *********************" << endl;
	cout << "��    5)  **********************  5000��   *********************" << endl;
	cout << "������������������������������������������������������������������" << endl;

	do
	{
		cout << "����������ȡ��ѡ� ";
		cin >> choice;
		switch (choice)
		{
		case 1 :
			if (cnsm.get_money() - 100 <= 0)
			{
				cout << "�Բ����������㣡�Ƿ�����ѡ�񣿣�Y or N��" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "��ϲ�������ɹ�!" << endl;
				cnsm.set_money(100);
				break;
			}

		case 2 :
			if (cnsm.get_money() - 200 <= 0)
			{
				cout << "�Բ����������㣡�Ƿ�����ѡ�񣿣�Y or N��" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "��ϲ�������ɹ�!" << endl;
				cnsm.set_money(200);
				break;
			}

		case 3 :
			if (cnsm.get_money() - 500 <= 0)
			{
				cout << "�Բ����������㣡�Ƿ�����ѡ�񣿣�Y or N��" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "��ϲ�������ɹ�!" << endl;
				cnsm.set_money(500);
				break;
			}

		case 4 :
			if (cnsm.get_money() - 1000 <= 0)
			{
				cout << "�Բ����������㣡�Ƿ�����ѡ�񣿣�Y or N��" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cnsm.set_money(1000);
				cout << endl << "��ϲ�������ɹ�!" << endl;
				break;
			}

		case 5 :
			if (cnsm.get_money() - 5000 <= 0)
			{
				cout << "�Բ����������㣡�Ƿ�����ѡ�񣿣�Y or N��" << endl;
				cin >> ch;
				break;
			}
			else
			{
				cout << endl << "��ϲ�������ɹ�!" << endl;
				cnsm.set_money(5000);
				break;
			}

		default:
			break;
		}
	} while (ch == 'y' || ch == 'Y');

	//system("color 32");
}


//��ȡ�û�������Ϣ
void ATM::get_information()
{
	//system("color 59");
	cout << "**********************************" << endl;
	cout << "*" << endl;
	cout << "*     ���ţ�    " << cnsm.get_num() << endl;
	cout << "*     ������    " << cnsm.get_name() << endl;
	cout << "*     ��    " << cnsm.get_money() << endl;
	cout << "*" << endl;
	cout << "**********************************" << endl;
	//system("color 59");
}


//��ʾ���ܽ���
void ATM::functionshow()
{
	system("cls");
	//system("color 84");
	int n = 0; //ѡ�����ѡ��
	do
	{
		cout << "          ����������������������������������         " << endl;
		cout << "          ��   ����������Ӧ�Ĳ�����Ž��в�����    ��         " << endl;
		cout << "          ��1) �޸�����:                            ��         " << endl;
		cout << "          ��2) ȡ��:                                ��         " << endl;
		cout << "          ��3) ��ѯ���:                            ��         " << endl;
		cout << "          ��4) �˳�ϵͳ:                            ��         " << endl;
		cout << "          ��                $ >\\                   ��         " << endl;
		cout << "          ���������������������������������         " << endl;
		cin >> n;
		while (n<1 || n>4)
		{
			cout << "��������ȷ�Ĳ������!" << endl;
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


//������
void ATM::lock()
{
	cout << endl << "�Բ���������Ĳ���������Ŀ��Ѿ���û��! " << endl;
	exit(1);
}

//�˳�ϵͳ
void ATM::exitATM()
{
	system("cls");
	//system("color 16");
	cout << endl << "��л��Ա��е�֧�֣���ӭ�´ι���!" << endl;
	cout << "��ȡ������" << endl;
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