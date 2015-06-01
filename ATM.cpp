#include "ATM_class.h"
#include <iostream>

int main()
{
	consumer C1("JinBin OuYang", "6222024301081093724", 10000, "root");

	ATM atm(C1);
	atm.welcome();

	system("pause");
	return 0;
}