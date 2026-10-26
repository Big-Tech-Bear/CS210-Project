//CS210 Project 2
//Ty Miller 10/2/26
//Airgead Banking App header

#pragma once
#ifndef AIRGEADBANK_H_
#define AIRGEADBANK_H_


class AirgeadBank {


//public classes
public:
	void SetInitialInvestment(double t_initialInvestment);
	void SetMonthlyDeposit(double t_monthlyDeposit);
	void SetInterestRate(double t_annualInterest);
	void SetNumberOfYears(int t_numberOfYears);
	double GetInitialInvestment() const;
	double GetMonthlyDeposit() const;
	double GetInterestRate() const;
	int GetNumberOfYears() const;
	double calcBalanceWithoutMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numberOfYears);
	double balanceWithMonthlyDeposit(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears);


//private classes
private:
	double m_totalAmount;
	double m_interestAmount;
	double m_yearlyTotalInterest;
	double m_monthlyDeposit;
	double m_numberOfYears;
};

#endif