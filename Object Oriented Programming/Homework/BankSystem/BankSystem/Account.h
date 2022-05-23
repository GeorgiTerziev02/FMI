#pragma once
#include <ctime>
#include "String.h"

class Account
{
protected:
	String userName;
	String password;
	String iBAN;
	size_t ownerId;
	double amount;
	time_t dateOfCreation;

public:
	Account(const String& userName, const String& password, const String& iBAN, size_t ownerId);

	size_t getOwnerId() const;
	double getAmount() const;

	void deposit(double toDeposit);
	virtual bool withdraw(double toWithdraw) = 0;
	void display() const;
};

