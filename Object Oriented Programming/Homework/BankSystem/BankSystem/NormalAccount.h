#pragma once
#include "Account.h"

class NormalAccount: public Account
{
public:
	bool withdraw(double toWithdraw) override;
};

