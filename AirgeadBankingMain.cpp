//CS210 Project 2
//Ty Miller 10/2/26
//Airgead Banking Main


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "AirgeadBank.h"

using namespace std;

AirgeadBank myInvestment;
double initialInvestment;
double monthlyDeposit;
double annualInterest;
double months;
int years;
char user_input = 'a';
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();

//main function
int main() {
	while (user_input != 'q') {
		system("cls");
		PrintHomeScreen();

		myInvestment.calcBalanceWithoutMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());
		myInvestment.balanceWithMonthlyDeposit(myInvestment.GetInitialInvestment(), myInvestment.GetMonthlyDeposit(), myInvestment.GetInterestRate(), myInvestment.GetNumberOfYears());

		cout << "Enter 'q' to quit. Enter any letter or number to run another report.";
		cin >> user_input;
	}

	return 0;
}

//home screen and get user input
void PrintHomeScreen() {
	try {
		cout << std::string(34, '*') << endl;
		cout << std::string(10, '-') << " Input Data " << std::string(12, '-') << endl;
		cout << "Initial Investment Amount: $";

		initialInvestment = validDoubleInput();
		if (initialInvestment < 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetInitialInvestment(initialInvestment);
		cout << "Monthly Deposit: $";
		monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetMonthlyDeposit(monthlyDeposit);
		cout << "Annual Interest: %";
		annualInterest = validDoubleInput();;
		if (annualInterest < 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetInterestRate(annualInterest);
		cout << "Number of years: ";
		years = validIntInput();
		if (years <= 0) {
			throw runtime_error("Invalid entry.");
		}

		myInvestment.SetNumberOfYears(years);

		system("PAUSE");
	}

	//catch to prevent error with negetive numbers
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Can not calculate with negative numbers." << endl;
		system("PAUSE");
		system("cls");
		PrintHomeScreen();
	}
}

//make sure input is an integer
int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			break;
		}
	
		else {
			cout << "Invalid Input. Please input a number.";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}

//make sure input is a double
double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			break;
		}

		else {
			cout << "Invalid Input. Please enter valid number.";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}