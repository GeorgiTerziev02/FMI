#include "Account.h"
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

Account::Account(const String& userName, const String& password, const String& iBAN, size_t ownerId) {
	this->userName = userName;
	this->password = password;
	this->iBAN = iBAN;
	this->ownerId = ownerId;
	amount = 0;
	dateOfCreation = time(0);
}

const String& Account::getIBAN() const {
	return iBAN;
}

size_t Account::getOwnerId() const {
	return ownerId;
}

double Account::getBalance() const {
	return amount;
}

void Account::deposit(double toDeposit) {
	amount += toDeposit;
}

std::ostream& operator<<(std::ostream& out, const Account& account) {
	out << "Date of creation: " << ctime(&account.dateOfCreation);
	out << "IBAN: " << account.iBAN << std::endl;
	out << "Amount: " << account.amount << std::endl;
	out << "Owner id: " << account.ownerId << std::endl;
	out << "User name: " << account.userName << std::endl;
	out << std::endl;
	return out;
}