#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputeValidate.h"

class clsQuickWithdrawScreen : protected clsScreen
{
private:




public:

	static void ShowQuickWithdrawScreen()
	{
		_DrawScreenHeader("\t  Quick Withdraw Screen");

		cout << endl;
		cout << setw(40) << left << "" << "===========================================\n";
		cout << setw(40) << left << "" << "            Quick Withdraw Menue\n";
		cout << setw(40) << left << "" << "===========================================\n\n";

		cout << setw(40) << left << "" << "\t[1] Quick Withdraw\n";
		cout << setw(40) << left << "" << "\t[2] Normal Withdraw\n";
		cout << setw(40) << left << "" << "\t[3] Deposit\n";
		cout << setw(40) << left << "" << "\t[4] Account Details\n";
		cout << setw(40) << left << "" << "\t[5] LogOut\n";
		cout << setw(40) << left << "" << "===========================================\n\n";

	}

};

