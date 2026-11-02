#pragma once

#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsInputeValidate.h"

class clsAccountDetailsScreen : protected clsScreen
{
private:

	static void _PrintClientCard()
	{
		cout << "\n\n This is Your Personal Information:";
		cout << "\n_____________________________________\n";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nEmail      : " << Client.Email;
		cout << "\nPhone Num  : " << Client.PhoneNum;
		cout << "\nAcc.Number : " << Client.AccountNumber();
		cout << "\nPin Code   : " << Client.PinCode;
		cout << "\nAcc.Balance: " << Client.AccountBalance << "($)";
		cout << "\n_____________________________________\n";
	}

	static void _UpdateClientInfo()
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone Number: ";
		Client.PhoneNum = clsInputValidate::ReadString();

		cout << "\nEnter Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();

	}

public:

	static void ShowAccountDetialsScreen()
	{
		_DrawScreenHeader("\t   Account Details Screen");
		_PrintClientCard();

		char C = 'n';
		cout << "\n\nDo You Want To Update Your Personal Information? [Y/N]: ";
		cin >> C;

		if (toupper(C) == 'Y')
		{
			_UpdateClientInfo();

			clsClient::enSaveResult SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsClient::enSaveResult::svSucceded:

				cout << "\n\nYour Personal Info Has Been Updated Successfully :)";
				_PrintClientCard();
				break;

			case clsClient::enSaveResult::svFailedEmptyObject:

				cout << "\nError, Empty Object Can't Be Updated :(\n";
				break;
			}
		}

	}

};

