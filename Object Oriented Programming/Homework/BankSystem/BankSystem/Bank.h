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
	Account* getAccountByIBAN(const String& iBAN) const;

	void addCustomer(Customer* customer);
	void deleteCustomer(size_t customerId);
	void addAccount(const Account* account);
	void deleteAccount(const String& iBAN);
	void listCustomers() const;
	void listAccounts() const;
	void listCustomerAccount(size_t customerId) const;
	void listLog() const;
	void exportLog() const;

	void deposit(const String& iBAN, double amount);
	void withdraw(const String& iBAN, double amount);
	void transfer(const String& fromIBAN, const String& toIBAN, double amount);
	void display() const;
};

