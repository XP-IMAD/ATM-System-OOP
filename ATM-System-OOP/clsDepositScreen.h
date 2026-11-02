#pragma once

#include <iostream>
#include "clsInputeValidate.h"
#include "clsScreen.h"

class clsDepositScreen : protected clsScreen
{
private:

	static void _PrintClientCard()
	{
		cout << "\n____________[Client Card]_____________\n";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nEmail      : " << Client.Email;
		cout << "\nPhone Num  : " << Client.PhoneNum;
		cout << "\nAcc.Number : " << Client.AccountNumber();
		cout << "\nPin Code   : " << Client.PinCode;
		cout << "\nAcc.Balance: " << Client.AccountBalance << "($)";
		cout << "\n_____________________________________\n";

	}

	static void _Deposit(double Amount)
	{
		char C1 = 'n';

		cout << "\nAre You Sure You Want To Perform This Trasaction? [Y/N]: ";
		cin >> C1;

		if (toupper(C1) == 'Y')
		{
			if (Client.Deposit(Amount))
			{
				cout << "\nDone Successfully :)\n";
				_PrintClientCard();
			}
			else
			{
				cout << "\nError, The Operation Has Been Cancelled :(\n";
			}
		}
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t\tDeposit Screen");

		cout << "\nPLease Enter Your Deposit Amount: ";
		double Amount = clsInputValidate::ReadPositiveNumber<double>();

		_Deposit(Amount);

	}

};

