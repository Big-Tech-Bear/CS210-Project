//CS210 Project 2
//Ty Miller 10/2/26
//Airgead Banking

#include "AirgeadBank.h"
#include <iostream>
#include <iomanip>

using namespace std;

//mutators and accessors
void AirgeadBank::SetInitialInvestment(double t_initialInvestment) {
	m_totalAmount = t_initialInvestment;
}
void AirgeadBank::SetMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}
void AirgeadBank::SetInterestRate(double t_annualInterest) {
	m_yearlyTotalInterest = t_annualInterest;
}
void AirgeadBank::SetNumberOfYears(int t_numberOfYears) {
	m_numberOfYears = t_numberOfYears;
}
double AirgeadBank::GetInitialInvestment() const {
	return m_totalAmount;
}
double AirgeadBank::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}
double AirgeadBank::GetInterestRate() const {
	return m_yearlyTotalInterest;
}
int AirgeadBank::GetNumberOfYears() const {
	return m_numberOfYears;
}


//calculate balance without monthly deposit
double AirgeadBank::calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numberOfYears) {
	m_totalAmount = t_initialInvestment;

	//display table header
	cout << endl << "   Balance and Interest Without Monthly Deposits" << endl;
	cout << std::string(64, '*') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << std::string(64, '-') << endl;

	//calculate yearly interest and end total
	for (int i = 0; i < t_numberOfYears; i++) {
		m_interestAmount = m_totalAmount * (t_annualInterest / 100);
		m_totalAmount = m_totalAmount + m_interestAmount;
		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_interestAmount << endl;
	}

	return m_totalAmount;
}

//calculate balance with deposit
double AirgeadBank::balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears) {
	m_totalAmount = t_initialInvestment;

	//display table header
	cout << endl << "   Balance and Interest With Monthly Deposits" << endl;
	cout << std::string(64, '*') << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << std::string(64, '-') << endl;

	//calculate yearly interest and end total
	for (int i = 0; i < t_numberOfYears; i++) {
		m_yearlyTotalInterest = 0;
		for (int j = 0; j < 12; j++) {
			m_interestAmount = (m_totalAmount + t_monthlyDeposit) * ((t_annualInterest / 100.00) / 12.00);
			m_yearlyTotalInterest = m_yearlyTotalInterest + m_interestAmount;
			m_totalAmount = m_totalAmount + t_monthlyDeposit + m_interestAmount;
		}
		cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t\t$" << m_yearlyTotalInterest << endl;
	}

	return m_totalAmount;
}