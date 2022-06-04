#include "Bank.h"
#include "constants.h"
#include <fstream>

Bank::Bank(const String& name, const String& address) {
	this->name = name;
	this->address = address;
}

Bank::Bank(const Bank& other) {
	copyFrom(other);
}

Bank& Bank::operator=(const Bank& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Bank::~Bank() {
	free();
}

void Bank::copyFrom(const Bank& other) {
	name = other.name;
	address = other.address;

	for (size_t i = 0; i < other.customers.getSize(); i++)
		customers.pushBack(other.customers[i]->clone());

	for (size_t i = 0; i < other.accounts.getSize(); i++)
		accounts.pushBack(other.accounts[i]->clone());

	for (size_t i = 0; i < other.log.getSize(); i++)
		log.pushBack(other.log[i]);
}

void Bank::free() {
	for (size_t i = 0; i < customers.getSize(); i++)
		delete customers[i];

	customers.clear();

	for (size_t i = 0; i < accounts.getSize(); i++)
		delete accounts[i];

	accounts.clear();

	log.clear();
}

Customer* Bank::getCustomer(size_t customerId) const {
	for (size_t i = 0; i < customers.getSize(); i++)
		if (customers[i]->getId() == customerId)
			return customers[i];

	return nullptr;
}

int Bank::getCustomerIndex(size_t customerId) const {
	for (size_t i = 0; i < customers.getSize(); i++)
		if (customers[i]->getId() == customerId)
			return i;

	return -1;
}

Account* Bank::getAccountByIBAN(const String& iBAN) const {
	for (size_t i = 0; i < accounts.getSize(); i++)
		if (accounts[i]->getIBAN() == iBAN)
			return accounts[i];

	return nullptr;
}

void Bank::addCustomer(const Customer* customer) {
	if (getCustomer(customer->getId()) != nullptr)
		throw CUSTOMER_ALREADY_EXISTS;

	customers.pushBack(customer->clone());
	log.pushBack("Customer added");
}

void Bank::deleteCustomer(size_t customerId) {
	int customerIndex = getCustomerIndex(customerId);

	if (customerIndex == -1)
		throw CUSTOMER_DOES_NOT_EXIST;

	for (size_t i = 0; i < accounts.getSize(); i++) {
		if (accounts[i]->getOwnerId() == customerId) {
			Account* account = accounts.popAt(i);
			delete account;
		}
	}

	Customer* customer = customers.popAt(customerIndex);
	delete customer;
	log.pushBack("Customer deleted");
}

void Bank::addAccount(const Account* account) {
	if (getAccountByIBAN(account->getIBAN()) != nullptr)
		throw ACCOUNT_ALREADY_EXISTS;

	if (getCustomer(account->getOwnerId()) == nullptr)
		throw CUSTOMER_DOES_NOT_EXIST;

	accounts.pushBack(account->clone());
	log.pushBack("Account added");
}

void Bank::deleteAccount(const String& iBAN) {
	for (size_t i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i]->getIBAN() == iBAN)
		{
			Account* account = accounts.popAt(i);
			delete account;
			log.pushBack("Account deleted ");
			return;
		}
	}

	throw ACCOUNT_DOES_NOT_EXIST;
}

void Bank::listCustomers() const {
	for (size_t i = 0; i < customers.getSize(); i++) {
		std::cout << "Id: " << customers[i]->getId() << std::endl;
		std::cout << "Name: " << customers[i]->getName() << std::endl;
		std::cout << "Address: " << customers[i]->getAddress() << std::endl;
		std::cout << std::endl;
	}
}

void Bank::listAccounts() const {
	for (size_t i = 0; i < accounts.getSize(); i++)
		accounts[i]->display();
}

void Bank::listCustomerAccount(size_t customerId) const {
	for (size_t i = 0; i < accounts.getSize(); i++)
		if (accounts[i]->getOwnerId() == customerId)
			accounts[i]->display();
}

void Bank::listLog() const {
	for (size_t i = 0; i < log.getSize(); i++)
		std::cout << log[i] << std::endl;
}

void Bank::exportLog() const {
	std::ofstream out("logs.txt");

	if (!out.is_open())
		throw "Could not open file!";

	for (size_t i = 0; i < log.getSize(); i++)
		out << log[i] << std::endl;

	out.close();
}

void Bank::deposit(const String& iBAN, double amount) {
	Account* account = getAccountByIBAN(iBAN);

	if (account == nullptr)
		throw ACCOUNT_DOES_NOT_EXIST;

	account->deposit(amount);
	log.pushBack("Deposited");
}

void Bank::withdraw(const String& iBAN, double amount) {
	Account* account = getAccountByIBAN(iBAN);

	if (account == nullptr)
		throw ACCOUNT_DOES_NOT_EXIST;

	bool success = account->withdraw(amount);
	if (!success)
		throw CAN_NOT_WITHDRAW_FROM_THE_ACCOUNT;

	log.pushBack("Withdraw");
}

void Bank::transfer(const String& fromIBAN, const String& toIBAN, double amount) {
	Account* fromAccount = getAccountByIBAN(fromIBAN);
	Account* toAccount = getAccountByIBAN(toIBAN);

	if (fromAccount == nullptr || toAccount == nullptr)
		throw ACCOUNT_DOES_NOT_EXIST;

	bool success = fromAccount->withdraw(amount);
	if (!success)
		throw CAN_NOT_WITHDRAW_FROM_THE_ACCOUNT;

	toAccount->deposit(amount);
	log.pushBack("Transfer");
}

void Bank::display() const {
	std::cout << "Bank name: " << name << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Customers count: " << customers.getSize() << std::endl;
	std::cout << "Accounts count: " << accounts.getSize() << std::endl;
	std::cout << std::endl;
}