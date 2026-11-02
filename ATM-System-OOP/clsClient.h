#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsPerson.h"

class clsClient : public clsPerson
{
private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	static string _ConvertClientDataToLine(clsClient Client, string Seperator = "#//#")
	{
		string ClientLine = "";

		ClientLine += Client.FirstName + Seperator;
		ClientLine += Client.LastName + Seperator;
		ClientLine += Client.Email + Seperator;
		ClientLine += Client.PhoneNum + Seperator;
		ClientLine += Client.AccountNumber() + Seperator;
		ClientLine += Client.PinCode + Seperator;
		ClientLine += to_string(Client.AccountBalance);

		return ClientLine;

	}

	static clsClient _ConvertClientLineToObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClient = clsString::Split(Line, Seperator);


		return  clsClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
			vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}

	static clsClient _GetEmptyOpject()
	{
		return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsClient> _LoadClientDataFromFile()
	{
		vector<clsClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode

		if (MyFile.is_open())
		{
			string DataLine;

			while (getline(MyFile, DataLine))
			{
				clsClient Client = _ConvertClientLineToObject(DataLine);

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;

	}

	static void _SaveClientDataToFile(const vector<clsClient> &vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;

			for (const clsClient &C : vClients)
			{
				Line = _ConvertClientDataToLine(C);

				MyFile << Line << endl;
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsClient> vClients = _LoadClientDataFromFile();

		for (clsClient &C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientDataToFile(vClients);
	}

public:

	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumebr,
		string PinCode, double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;

		_AccountNumber = AccountNumebr;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	
	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;

	
	static clsClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode


		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsClient Client = _ConvertClientLineToObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();
		}

		return _GetEmptyOpject();
	}

	static clsClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //Read Mode


		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsClient Client = _ConvertClientLineToObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();
		}

		return _GetEmptyOpject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsClient Client = clsClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static vector<clsClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > AccountBalance || Amount <= 0)
			return false;

		AccountBalance -= Amount;
		_Update();
		return true;
	}

	bool Deposit(double Amount)
	{
		if (Amount <= 0)
			return false;

		AccountBalance += Amount;
		_Update();
		return true;
	}

	static clsClient GetEmptyClientObject()
	{
		return _GetEmptyOpject();
	}

	enum enSaveResult {svFailedEmptyObject = 0, svSucceded = 1};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:

			return enSaveResult::svFailedEmptyObject;
			break;


		case enMode::UpdateMode:

			_Update();

			return enSaveResult::svSucceded;
			break;
		}
	}

};

