//============================================================================
// Name        : projectTwo.cpp
// Author      : Max Porter
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Airgead Banking App
//============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	//variables to store input
	float initialInvestment,monthlyDeposit,annualInterest,years,months;
	//variables to store output
	float interestYear,depositedAmount,total,interest,closingBalance;

	//display the user input window and gather user input
	cout << "********************************" << endl;
	cout << "*          data input          *" << endl;
	cout << "initial investment amount: $";
	cin >> initialInvestment;
	cout << endl << "monthly deposit: $";
	cin >> monthlyDeposit;
	cout << endl << "annual interest: %";
	cin >> annualInterest;
	cout << endl << "number of years: ";
	cin >> years;
	months = years * 12;
	total = initialInvestment;

	system("PAUSE");

	//calculate the interest and total without monthly deposits
	vector<float> totals(years);
	vector<float> interests(years);
	for(int i = 0; i < years; i++)
	{
		interest = total * (annualInterest / 100);
		total += interest;
		totals.at(i) = total;
		interests.at(i) = interest;
	}

	//display the calculated values
	cout << " balance and interest without additional monthly deposits " << endl;
	cout << "==========================================================" << endl;
	cout << " year      year end balance      year end earned interest " << endl;
	cout << "----------------------------------------------------------" << endl;

	for(int j = 0; j < years; j++)
	{
		cout << fixed << setprecision(2) << " " << j+1 << "         $" << totals.at(j);
		cout << "\t\t\t$" << interests.at(j) << endl;
	}

	total = initialInvestment;

	//calculate the interest and total without monthly deposits
	for(int i = 0; i < years; i++)
		{
			interestYear = 0;
			for(int j = 0; j < 12; j++)
			{
				interest = (total+monthlyDeposit) * ((annualInterest / 100) / 12);
				interestYear += interest;
				total += monthlyDeposit + interest;
			}
			totals.at(i) = total;
			interests.at(i) = interestYear;
		}

		//display the calculated values
		cout << endl <<  "   balance and interest with additional monthly deposits  " << endl;
		cout << "==========================================================" << endl;
		cout << " year      year end balance      year end earned interest " << endl;
		cout << "----------------------------------------------------------" << endl;

		for(int j = 0; j < years; j++)
		{
			cout << fixed << setprecision(2) << " " << j+1 << "         $" << totals.at(j);
			cout << "\t\t\t$" << interests.at(j) << endl;
		}

	return 0;
}
