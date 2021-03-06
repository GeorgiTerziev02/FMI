#include "NormalAccount.h"
#include "constants.h"
#include <iostream>

NormalAccount::NormalAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId)
	:Account(userName, password, iBAN, ownerId) {}


Account* NormalAccount::clone() const {
	return new NormalAccount(*this);
}

bool NormalAccount::withdraw(double toWithdraw) {
	if (amount < toWithdraw)
		return false;

	amount -= toWithdraw;
	return true;
}

void NormalAccount::display() const {
	std::cout << NORMAL_ACCOUNT << std::endl;
	std::cout << *this;
}
