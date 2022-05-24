#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
	double interestRate;
public:
	SavingsAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId, double interestRate);

	double getInterestRate() const;
	bool withdraw(double toWithdraw) override;
	void display() const override;
};

