#include <iostream>
#include <iomanip>

using namespace std;

//main

int main() {
	//stored input variables
	float investment, deposit, yearInt, months, years;
	//stored year end amounts
	float totAmount, intAmount, yearTotalInt;

	//investor display
	cout << "**********************************\n";
	cout << "********** Data Input ************\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of Years: \n";

	//user input
	system("PAUSE");
	cout << "**********************************\n";
	cout << "********** Data Input ************\n";
	cout << "Initial Investment Amount: $";
	cin >> investment;
	cout << "Monthly Deposit: $";
	cin >> deposit;
	cout << "Annual Interest: %";
	cin >> yearInt;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;

	//wait for user to press key
	system("PAUSE");
	//updating total amount
	totAmount = investment;

	//display without monthly deposits
	cout << "\n   Balance and Interest Without Additional Monthly Desposits\n";
	cout << "================================================================\n";
	cout << "Year\t\   Year End Balance\t\    Year End Earned Interest\n";
	cout << "----------------------------------------------------------------\n";

	for (int i = 0; i < years; i++) {
		//yearly interest
		intAmount = (totAmount) * ((yearInt / 100));

		//year total
		totAmount = totAmount + intAmount;

		//print amounts, use table, use 2 decimal
		cout << setw(2) << (i + 1) << setw(14) << "$" << fixed << setprecision(2) << totAmount << setw(22) << "$" << intAmount << "\n";

	}

	//updating total amount
	totAmount = investment;

	//display with monthly deposits
	cout << "\n\n   Balance and Interest With Additional Monthly Desposits\n";
	cout << "================================================================\n";
	cout << "Year\t\   Year End Balance\t\    Year End Earned Interest\n";
	cout << "----------------------------------------------------------------\n";

	for (int i = 0; i < years; i++) {
		//interest to 0
		yearTotalInt = 0;

		for (int j = 0; j < 12; j++) {
			//monthly interest
			intAmount = (totAmount + deposit) * ((yearInt / 100) / 12);

			//end of month interest
			yearTotalInt = yearTotalInt + intAmount;

			//end of month total
			totAmount = totAmount + deposit + intAmount;
		}

		//print amounts, use table, use 2 decimal
		cout << setw(2) << (i + 1) << setw(14) << "$" << fixed << setprecision(2) << totAmount << setw(22) << "$" << intAmount << "\n";
	}

	return 0;

}