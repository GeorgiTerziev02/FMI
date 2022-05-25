#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId, double interestRate) 
	:Account(userName, password, iBAN, ownerId), interestRate(interestRate) {}

Account* SavingsAccount::clone() const
{
	Account* newObj = new SavingsAccount(*this);
	return newObj;
}

double SavingsAccount::getInterestRate() const {
	return interestRate;
}

bool SavingsAccount::withdraw(double toWithdraw) {
	return false;
}

void SavingsAccount::display() const {
	std::cout << "SavingsAccount" << std::endl;
	((const Account*)this)->display();
}