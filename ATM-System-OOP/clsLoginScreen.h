#pragma once

#include <iostream>
#include "clsClient.h"
#include "clsScreen.h"
#include "clsMainMenue.h"

class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short Trials = 3;
		string AccountNumber, PinCode;

		do
		{

			if (LoginFaild)
			{
				Trials--;
				system("cls");
				_DrawScreenHeader("\t\tLogin Screen");
				cout << "\nInvalid AccountNumebr OR PinCode!";
				cout << "\nYou Have [" << Trials << "] Trials Left!";

			}

			if (Trials == 0)
			{
				cout << "\n\nYou Are Locked After 3 Trials!\n";
				return false;
			}

			cout << "\n\nEnter Account Number: ";
			cin >> AccountNumber;

			cout << "Enter Pin Code: ";
			cin >> PinCode;

			Client = clsClient::Find(AccountNumber, PinCode);

			LoginFaild = Client.IsEmpty();


		} while (LoginFaild);

		clsMainMenue::ShowMainMenueScreen();
		return true;
	}


public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen");

		return _Login();
		
	}


};

