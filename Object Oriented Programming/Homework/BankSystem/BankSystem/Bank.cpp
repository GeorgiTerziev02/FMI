#include "Bank.h"
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
	{
		Customer* customer = new Customer(*other.customers[i]);
		customers.pushBack(customer);
	}

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

void Bank::addCustomer(Customer* customer) {
	if (getCustomer(customer->getId()) != nullptr)
		throw "Customer already exists!";

	customers.pushBack(customer);
	log.pushBack("Customer added " + customer->getId());
}

void Bank::deleteCustomer(size_t customerId) {
	int customerIndex = getCustomerIndex(customerId);

	if (customerIndex == -1)
		throw "Customer does not exist!";

	for (size_t i = 0; i < accounts.getSize(); i++) {
		if (accounts[i]->getOwnerId() == customerId) {
			Account* account = accounts.popAt(i);
			delete account;
		}
	}

	Customer* customer = customers.popAt(getCustomerIndex(customerId));
	delete customer;
	log.pushBack("Customer deleted " + customerId);
}

void Bank::addAccount(Account* account) {
	if (getAccountByIBAN(account->getIBAN()) != nullptr)
		throw "Account already exists";

	accounts.pushBack(account);
	log.pushBack("Account added " + 123);
}

void Bank::deleteAccount(const String& iBAN) {
	for (size_t i = 0; i < accounts.getSize(); i++)
	{
		if (accounts[i]->getIBAN() == iBAN)
		{
			Account* account = accounts.popAt(i);
			delete account;
			log.pushBack("Account deleted " + 123);
			break;
		}
	}
}

void Bank::listCustomers() const {
	for (size_t i = 0; i < customers.getSize(); i++)
		std::cout << customers[i]->getId() << customers[i]->getName() << " " << customers[i]->getAddress() << std::endl;
}

void Bank::listAccounts() const {
	for (size_t i = 0; i < accounts.getSize(); i++)
		std::cout << accounts[i]->getOwnerId() << " " << accounts[i]->getBalance() << std::endl;
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
		"Account not found!";

	account->deposit(amount);
}

void Bank::withdraw(const String& iBAN, double amount) {
	Account* account = getAccountByIBAN(iBAN);

	if (account == nullptr)
		"Account not found!";

	bool success = account->withdraw(amount);
	if (!success)
		"Can not withdraw the given amount!";
}

void Bank::transfer(const String& fromIBAN, const String& toIBAN, double amount) {
	Account* fromAccount = getAccountByIBAN(fromIBAN);
	Account* toAccount = getAccountByIBAN(toIBAN);

	if (fromAccount == nullptr || toAccount == nullptr)
		throw "One of the accounts was not found!";

	bool success = fromAccount->withdraw(amount);
	if (!success)
		throw "Could not withdraw from the account!";

	toAccount->deposit(amount);
	log.pushBack("Transfer");
}

void Bank::display() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Customers count: " << customers.getSize() << std::endl;
	std::cout << "Accounts count: " << accounts.getSize() << std::endl;
}