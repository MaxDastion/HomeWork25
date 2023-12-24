#pragma once
#include "Header.h"

class Firm
{
public:
	void AddFirm() {
		cout << "Enter name firm: " << endl;
		cin >> _NameFirm;
		cout << "Enter owner firm: " << endl;
		cin >> _Owner;
		cout << "Enter number phone firm: " << endl;
		cin >> _NumberPhone;
		cout << "Enter addres firm: " << endl;
		cin >> _Addres;
		cout << "Enter occupation firm: " << endl;
		cin >> _Occupation;
		_Savefirm();
	}
	void AddFirm(string temp [5]) {
		
		  _NameFirm= temp[0];
		
		_Owner = temp[1];
		
		_NumberPhone = temp[2];
		
		_Addres = temp[3];
		
		_Occupation = temp[4];
	}
	void SetParametrs(fs::directory_entry dir) {
		ifstream fin(dir.path());
		string line;
		int f = 0;
		string temp[5];
		while (getline(fin, line)) {
			for (size_t i = 0; i < 14; i++)
			{
				line.erase(0,1);
			}
			temp[f] = line;
			f++;
			
		}
		AddFirm(temp);
		fin.close();
	}

	Firm() = default;
	Firm(string name, string owner, string number, string addres, string occupation) : _NameFirm(name), _Owner(owner), _NumberPhone(number), _Addres(addres), _Occupation(occupation){

	}
#pragma region Geters

	string GetName() {
		return _NameFirm;
	}
	string GetOwner() {
		return _Owner;
	}
	string GetNumber() {
		return _NumberPhone;
	}
	string GetAddres() {
		return _Addres;
	}
	string GetOccupatiion() {
		return _Occupation;
	}

#pragma endregion

	void Recod() {
		string want;
		cout << "what do you want to add?" << endl;
		cin >> want;
		if (want == "name") {
			cin >> want;
			_NameFirm + want;
			
		}
		else if (want == "owner")
		{
			cin >> want;
			_Owner + want;
		}
		else if (want == "number") {
			cin >> want;
			_NumberPhone + want;
		}
		else if (want == "addres") {
			cin >> want;
			_Addres + want;
		}
		else if (want == "occupation") {
			cin >> want;
			_Occupation + want;
		}
	}

private:
	string _NameFirm;
	string _Owner;
	string _NumberPhone;
	string _Addres;
	string _Occupation;


	void _Savefirm() {
		ofstream fon("C:\\Users\\PC\\source\\repos\\HomeWork25\\HomeWork25\\Firms\\"+_NameFirm+ ".txt");

		fon << "NameFirm     :"<< _NameFirm << endl;
		fon << "Owner        :"<< _Owner << endl;
		fon << "Number phone :"<< _NumberPhone << endl;
		fon << "Addres       :"<< _Addres << endl;
		fon << "Occupation   :"<< _Occupation << endl;
		fon.close();


	}
};
