#include <iostream>

//ǰ������consumer��
class consumer;
class ATM
{
public:
	//ATM�涨����ȡ����Ŀö��
	enum withdraw
	{
		A = 100,
		B = 200,
		C = 500,
		D = 1000,
		E = 5000
	};

	//���캯����ʼ��
	ATM(consumer &cn) : cnsm(cn){}

	//��½�������
	void welcome();

	//�˶�����
	bool check_passwd(const std::string user_id, const std::string pwd);

	//�޸�����
	void change_passwd();

	//ȡ��
	void fetchmoney();

	//��ѯ�û���Ϣ
	void get_information();

	//�˳�ϵͳ
	void exitATM();

	//���ܽ���
	void functionshow();

	//��½��������һ�����������˻�
	void lock();

private:
	//��¼��½����������һ��������������
	int times = 0;

	//��ǰ�û�
	consumer &cnsm;
};


//�û���
class consumer
{
public:
	//��ATM����Ϊconsumer����Ԫ��
	friend class ATM;

	//���캯��
	consumer(const std::string &Name, const std::string &Num,
		float Money, std::string Passwd) : name(Name), num(Num), money(Money), passwd(Passwd) {}

	//��ȡ����
	inline std::string get_name();

	//��ȡ����
	std::string get_num();

	//��ȡ����
	std::string get_passwd();

	//��ȡ���
	float get_money();

	//��������
	void set_passwd(const std::string &pwd);

	//ȡǮ,ֻ����ȡ��������
	void set_money(int m);

private:
	//�û�����
	std::string passwd;

	//�û�����
	std::string name;

	//����
	std::string num;

	//�˻����
	float money;
};