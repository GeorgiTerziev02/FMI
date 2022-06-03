#include "PrivilegeAccount.h"
#include "constants.h"

PrivilegeAccount::PrivilegeAccount(const String& userName, const String& password, const String& iBAN, size_t ownerId, double overdraft)
	: Account(userName, password, iBAN, ownerId), overdraft(overdraft) {}

Account* PrivilegeAccount::clone() const
{
	return new PrivilegeAccount(*this);
}

double PrivilegeAccount::getOverdraft() const {
	return overdraft;
}

bool PrivilegeAccount::withdraw(double toWithdraw) {
	if (amount + overdraft < toWithdraw)
		return false;

	amount -= toWithdraw;
	return true;
}

void PrivilegeAccount::display() const {
	std::cout << PRIVILEGE_ACCOUNT << std::endl;
	std::cout << *this;
}