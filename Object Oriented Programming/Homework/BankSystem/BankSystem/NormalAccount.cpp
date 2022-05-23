#include "NormalAccount.h"
#include <iostream>

bool NormalAccount::withdraw(double toWithdraw) {
	if (amount < toWithdraw)
		return false;

	amount -= toWithdraw;
	return true;
}