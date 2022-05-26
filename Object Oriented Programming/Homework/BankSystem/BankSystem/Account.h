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
	virtual ~Account() {}

	virtual Account* clone() const = 0;

	const String& getIBAN() const;
	size_t getOwnerId() const;
	double getBalance() const;

	void deposit(double toDeposit);
	virtual bool withdraw(double toWithdraw) = 0;
	virtual void display() const;

	friend std::ostream& operator<<(std::ostream& out, const Account& account);
};

