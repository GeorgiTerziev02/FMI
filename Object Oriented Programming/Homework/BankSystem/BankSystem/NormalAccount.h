#pragma once
#include "Account.h"

class NormalAccount: public Account
{
public:
	NormalAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId);

	Account* clone() const override;

	bool withdraw(double toWithdraw) override;
	void display() const override;
};

