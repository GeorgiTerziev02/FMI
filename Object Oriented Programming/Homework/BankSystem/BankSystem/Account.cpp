#include "Account.h"

Account::Account(const String& userName, const String& password, const String& iBAN, size_t ownerId) {
	this->userName = userName;
	this->password = password;
	this->iBAN = iBAN;
	this->ownerId = ownerId;
	amount = 0;
	dateOfCreation = time(0);
}

size_t Account::getOwnerId() const {
	return ownerId;
}

double Account::getAmount() const {
	return amount;
}

void Account::deposit(double toDeposit) {
	amount += toDeposit;
}