#include "PrivilegeAccount.h"

double PrivilegeAccount::getOverdraft() const {
	return overdraft;
}

bool PrivilegeAccount::withdraw(double toWithdraw) {
	if (amount + overdraft < toWithdraw)
		return false;

	amount -= toWithdraw;
	return true;
}