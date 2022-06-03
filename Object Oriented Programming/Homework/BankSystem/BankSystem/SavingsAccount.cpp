#include "SavingsAccount.h"
#include "constants.h"

SavingsAccount::SavingsAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId, double interestRate) 
	:Account(userName, password, iBAN, ownerId), interestRate(interestRate) {}

Account* SavingsAccount::clone() const
{
	return new SavingsAccount(*this);
}

double SavingsAccount::getInterestRate() const {
	return interestRate;
}

bool SavingsAccount::withdraw(double toWithdraw) {
	return false;
}

void SavingsAccount::display() const {
	std::cout << SAVINGS_ACCOUNT << std::endl;
	std::cout << *this;
	std::cout << "Interest rate: " << interestRate << std::endl;
}