#pragma once
#include "Account.h"

class PrivilegeAccount : public Account
{
	double overdraft;

public:
	double getOverdraft() const;

	bool withdraw(double toWithdraw) override;
};

