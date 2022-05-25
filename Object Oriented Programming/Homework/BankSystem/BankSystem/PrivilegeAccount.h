#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
	double overdraft;

public:	
	PrivilegeAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId, double overdraft);

	Account* clone() const override;

	double getOverdraft() const;
	bool withdraw(double toWithdraw) override;
	void display() const override;
};

