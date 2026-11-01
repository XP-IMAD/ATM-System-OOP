#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputeValidate.h"

class clsNormalWithdrawScreen : protected clsScreen
{
private:

	static void _Withdraw(double Amount)
	{
		char Answer = 'n';
		cout << "\n\nAre You Sure You Want To Perform This Transaction? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\n\nDone Successfully, New Balance is : " << Client.AccountBalance
					<< endl;
			}
			else
			{
				cout << "\nError, The Operation Has Been Cancelled :(\n";
			}
		}

	}


public:

	static void ShowNormalWithdrawScreen()
	{
		_DrawScreenHeader("\t   Normal Withdraw Screen");

		cout << "\n\nPLease Enter Your Withdraw Amount: ";
		double Amount = clsInputValidate::ReadPositiveNumber<double>();

		while (Amount > Client.AccountBalance)
		{
			cout << "\nAmount Exeeds The Balance, You Can't Withdraw Up To " << Client.AccountBalance;
			cout << "\nPLease Enter Another Withdraw Amount: ";
			Amount = clsInputValidate::ReadPositiveNumber<double>();
		}

		_Withdraw(Amount);

	}

};

