#include"Firm.h"
#include"Header.h"
void CreateFirms(vector <Firm>& firms) {
	string path = "C:\\Users\\PC\\source\\repos\\HomeWork25\\HomeWork25";
	for (auto& i : fs::directory_iterator(path))
	{
		if (fs::is_directory(i.status()))
		{
			if (i.path().filename() == "Firms") {
				for (auto& j : fs::directory_iterator(i.path()))
				{
					if (j.path().extension().empty() || j.path().extension() == ".txt") {
						Firm firm;
						firm.SetParametrs(j);
						firms.push_back(firm);
					}
				}
			}
		}
	}

}

void Search(vector <Firm> firms) {
	string search;
	cout << "Do you want search?" << endl;
	cin >> search;
	if (search == "name") {
		cout << "Enter what you are going to search through" << endl;
		cin >> search;
		for (auto& i : firms)
		{
			if (i.GetName() == search) {
				cout << "We found your company, here is all the information we have: \n Name: " << i.GetName() << "\n Owner: " << i.GetOwner() << "\n Number: " << i.GetNumber() << "\n Addres: " << i.GetAddres() << "\n Occupation: " << i.GetOccupatiion()<< endl;
			}
			else {
				cout << "Sorry, we couldn't find your company, we apologize\n";
			}
		}
	}
	else if (search == "owner")
	{
		cout << "Enter what you are going to search through"<<endl;
		cin>> search;
		for (auto& i : firms)
		{
			if (i.GetOwner() == search) {
				cout << "We found your company, here is all the information we have: \n Name: " << i.GetName() << "\n Owner: " << i.GetOwner() << "\n Number: " << i.GetNumber() << "\n Addres: " << i.GetAddres() << "\n Occupation: " << i.GetOccupatiion() << endl;

			}
			else { cout << "Sorry, we couldn't find your company, we apologize\n"; }
		}

	}
	else if (search == "number") {
		cout << "Enter what you are going to search through"<<endl;
		cin>> search;
		for (auto& i : firms)
		{
			if (i.GetNumber() == search) {
				cout << "We found your company, here is all the information we have: \n Name: " << i.GetName() << "\n Owner: " << i.GetOwner() << "\n Number: " << i.GetNumber() << "\n Addres: " << i.GetAddres() << "\n Occupation: " << i.GetOccupatiion() << endl;

			}
			else { cout << "Sorry, we couldn't find your company, we apologize\n"; }
		}
	}
	else if (search == "addres") {
		cout << "Enter what you are going to search through"<<endl;
		cin>> search;
		for (auto& i : firms)
		{
			if (i.GetAddres() == search) {
				cout << "We found your company, here is all the information we have: \n Name: " << i.GetName() << "\n Owner: " << i.GetOwner() << "\n Number: " << i.GetNumber() << "\n Addres: " << i.GetAddres() << "\n Occupation: " << i.GetOccupatiion() << endl;

			}
			else { cout << "Sorry, we couldn't find your company, we apologize\n"; }
		}
	}
	else if (search == "occupation") {
		cout << "Enter what you are going to search through" << endl;
		cin >> search;
		for (auto& i : firms)
		{
			if (i.GetOccupatiion() == search) {
				cout << "We found your company, here is all the information we have: \n Name: " << i.GetName() << "\n Owner: " << i.GetOwner() << "\n Number: " << i.GetNumber() << "\n Addres: " << i.GetAddres() << "\n Occupation: " << i.GetOccupatiion() << endl;

			}
			else { cout << "Sorry, we couldn't find your company, we apologize\n"; }
		}
	}
}

void main() {
	vector <Firm> firms;
	string want;
	CreateFirms(firms);
	while (true)
	{
		cout << "Do you want?" << endl;
		cin >> want;
		if (want == "create") {
			Firm firm; firm.AddFirm(); firms.push_back(firm);
		}
		else if (want == "search") {
			Search(firms);
		}
		else if (want == "all") {
			for (auto& i : firms)
			{
				cout << "Name: " << i.GetName() << "\n Owner: " << i.GetOwner() << "\n Number: " << i.GetNumber() << "\n Addres: " << i.GetAddres() << "\n Occupation: " << i.GetOccupatiion() << endl;

			}
		}
		else if (want == "recod") {
			cout << "which company do you want to change?\n";
			cin >> want;
			for (auto& i : firms)
			{
				if (i.GetName() == want) {
					i.Recod();
				}
				else {
					cout << "Sorry, we couldn't find your company, we apologize\n";
				}
			}

		}
		else if (want == "nothing") {
			return;
		}
	}
}