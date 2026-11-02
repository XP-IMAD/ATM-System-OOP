#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputeValidate.h"
#include "clsScreen.h"
#include "clsQuickWithdrawScreen.h"
#include "clsNormalWithdrawScreen.h"
#include "clsDepositScreen.h"

class clsMainMenue : protected clsScreen
{
private:

	enum enATMMenueOption
	{
		enQuickWithdraw = 1, enNormalWithdraw = 2, enDeposit = 3,
		enAccountDetails = 4, enExit = 5
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(38) << left << "" << "Choose What Do You Want To Do From [1 To 5]: ";
		short Option = clsInputValidate::ReadNumberBetween<short>(1, 5, "\nEnter Number Between [1 And 5]: ");

		return Option;
	}

	static void _GoBackToMainMenueScreen()
	{
		cout << "\n [>] Press Any Key To Go Back To ATM Main Menue...";

		system("pause>0");
		ShowMainMenueScreen();
	}

	static void _ShowQuickWithdrawScreen()
	{
		//cout << "\n\nQuick Withdraw Screen Will Be Here...\n";
		clsQuickWithdrawScreen::ShowQuickWithdrawScreen();
	}

	static void _ShowNormalWithdrawScreen()
	{
		//cout << "\n\nNormal Withdraw Screen Will Be Here...\n";
		clsNormalWithdrawScreen::ShowNormalWithdrawScreen();
	}

	static void _ShowDepositScreen()
	{
		//cout << "\n\nDeposit Screen Will Be Here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowAccountDetailsScreen()
	{
		cout << "\n\nAccount Details Screen Will Be Here...\n";
	}

	static void _PerformATMMenueScreen(enATMMenueOption MenueOP)
	{
		switch (MenueOP)
		{

		case enQuickWithdraw:
			system("cls");
			_ShowQuickWithdrawScreen();
			_GoBackToMainMenueScreen();
			break;


		case enNormalWithdraw:
			system("cls");
			_ShowNormalWithdrawScreen();
			_GoBackToMainMenueScreen();
			break;


		case enDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToMainMenueScreen();
			break;


		case enAccountDetails:
			system("cls");
			_ShowAccountDetailsScreen();
			_GoBackToMainMenueScreen();
			break;


		case enExit:
			Client = clsClient::GetEmptyClientObject();
			break;

		}
	}

public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tATM Main Menue");

		cout << endl;
		cout << setw(38) << left << "" << "===================================================\n";
		cout << setw(38) << left << "" << "                   ATM Main Menue\n";
		cout << setw(38) << left << "" << "===================================================\n\n";

		cout << setw(38) << left << "" << "\t[1] Quick Withdraw\n";
		cout << setw(38) << left << "" << "\t[2] Normal Withdraw\n";
		cout << setw(38) << left << "" << "\t[3] Deposit\n";
		cout << setw(38) << left << "" << "\t[4] Account Details\n";
		cout << setw(38) << left << "" << "\t[5] Logout\n";
		cout << setw(38) << left << "" << "===================================================\n\n";

		_PerformATMMenueScreen(enATMMenueOption(_ReadMainMenueOption()));

	}

};

