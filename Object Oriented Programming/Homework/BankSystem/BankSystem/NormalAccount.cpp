#include "NormalAccount.h"
#include <iostream>

NormalAccount::NormalAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId)
	:Account(userName, password, iBAN, ownerId) {}


Account* NormalAccount::clone() const {
	Account* newObj = new NormalAccount(*this);
	return newObj;
}

bool NormalAccount::withdraw(double toWithdraw) {
	if (amount < toWithdraw)
		return false;

	amount -= toWithdraw;
	return true;
}

void NormalAccount::display() const {
	std::cout << "NormalAccount" << std::endl;
	std::cout << *this;
}
