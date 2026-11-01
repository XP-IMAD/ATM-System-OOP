#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputeValidate.h"

class clsQuickWithdrawScreen : protected clsScreen
{
private:

	static short _ReadWithdrawOption()
	{
		cout << setw(38) << left << "" << "Choose What Do You Want To Do From 1 To 9: ";
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 9, "\nEnter Number Between [1 And 9]: ");

		return Option;
	}

	static short _GetQuickWithdrawAmount(short QuickWithdrawOption)
	{
		short Amounts[8] = { 20, 50, 100, 200, 400, 600, 800, 1000 };

		return Amounts[QuickWithdrawOption - 1];
	}

	static void _PerformQuickWithdrawOP(short QuickWithdrawOption)
	{
		short WithdrawAmount = _GetQuickWithdrawAmount(QuickWithdrawOption);

		if (QuickWithdrawOption == 9)
		{
			return;
		}

		char Answer = 'n';
		cout << "\n\nAre You Sure You Want To Perform This Transaction? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client.Withdraw(WithdrawAmount))
			{
				cout << "\n\nDone Successfully, New Balance is : " << Client.AccountBalance
					<< endl;
			}
		}

	}

public:

	static void ShowQuickWithdrawScreen()
	{
		_DrawScreenHeader("\t  Quick Withdraw Screen");

		cout << endl;
		cout << setw(38) << left << "" << "===================================================\n";
		cout << setw(38) << left << "" << "                Quick Withdraw Menue\n";
		cout << setw(38) << left << "" << "===================================================\n\n";

		cout << setw(38) << left << "" << "        [1] 20 $              [2] 50 $\n";
		cout << setw(38) << left << "" << "        [3] 100$              [4] 200$\n";
		cout << setw(38) << left << "" << "        [5] 400$              [6] 600$\n";
		cout << setw(38) << left << "" << "        [7] 800$              [8] 1000$\n\n";
		cout << setw(38) << left << "" << "                  [9] Exit\n";
		cout << setw(38) << left << "" << "===================================================\n\n";

		_PerformQuickWithdrawOP(_ReadWithdrawOption());

	}

};

