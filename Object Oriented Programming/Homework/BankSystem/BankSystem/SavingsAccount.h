#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
	double interestRate;
public:
	double getInterestRate() const;

	bool withdraw(double toWithdraw) override;
};

