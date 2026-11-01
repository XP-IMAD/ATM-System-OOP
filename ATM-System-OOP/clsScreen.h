#pragma once

#include <iostream>
#include <iomanip>
#include "clsClient.h"
#include "CurrentClient.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t  _______________________________________";
		cout << "\n\n\t\t\t\t\t    " << Title;

		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t    " << SubTitle;
		}

		cout << "\n\t\t\t\t\t  _______________________________________\n\n";


		cout << "\n\t\t\t\t\t       Name   : " << Client.FullName();
		cout << "\n\t\t\t\t\t       Date   : " << clsDate::DateToString(clsDate());
		cout << "\n\t\t\t\t\t       Balance: " << Client.AccountBalance << " ($)\n\n";


	}

};

