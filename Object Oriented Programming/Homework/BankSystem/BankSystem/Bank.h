#pragma once
#include "String.h"
#include "Vector.hpp"
#include "Customer.h"
#include "Account.h"

class Bank
{
	String name;
	String address;
	Vector<Customer*> customers;
	Vector<Account*> accounts;
	Vector<String> log;

	void copyFrom(const Bank&);
	void free();
public:
	Bank(const String& name, const String& address);
	Bank(const Bank&);
	Bank& operator=(const Bank&);
	~Bank();

	Customer* getCustomer(size_t customerId) const;
	int getCustomerIndex(size_t customerId) const;

	void addCustomer(Customer* customer);
	void deleteCustomer(size_t customerId);
	void addAccount();
	void deleteAccount(const String& iBAN);
	void listCustomers() const;
	void listAccounts() const;
	void listCustomerAccount(size_t customerId) const;
	void exportLog() const;
	bool transfer(const String& fromIBAN, const String& toIBAN);
	void display() const;
};

