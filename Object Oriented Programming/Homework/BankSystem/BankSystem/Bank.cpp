#include "Bank.h"

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

// TODO: ???
void Bank::copyFrom(const Bank& other) {
	name = other.name;
	address = other.address;

	for (size_t i = 0; i < other.customers.getSize(); i++)
	{
		Customer* customer = new Customer(*other.customers[i]);
		customers.pushBack(customer);
	}

	//for (size_t i = 0; i < other.accounts.getSize(); i++)
	//{
	//	Account* account = new Account(*other.accounts[i]);
	//	accounts.pushBack(account);
	//}
}

void Bank::free() {
	for (size_t i = 0; i < customers.getSize(); i++)
		delete customers[i];

	customers.clear();

	for (size_t i = 0; i < accounts.getSize(); i++)
		delete customers[i];

	accounts.clear();
}

Customer* Bank::getCustomer(size_t customerId) {
	return nullptr;
}


void Bank::addCustomer(Customer* customer) {
	customers.pushBack(customer);
}

void Bank::deleteCustomer(size_t customerId) {

}

void Bank::addAccount() {

}

void Bank::deleteAccount(const String& iBAN) {

}

void Bank::listCustomers() const {
	for (size_t i = 0; i < customers.getSize(); i++)
		std::cout << customers[i]->getId() << customers[i]->getName() << " " << customers[i]->getAddress() << std::endl;
}

void Bank::listAccounts() const {
	for (size_t i = 0; i < accounts.getSize(); i++)
		std::cout << accounts[i]->getOwnerId() << " " << accounts[i]->getAmount() << std::endl;
}

void Bank::listCustomerAccount(size_t customerId) const {
	
}

void Bank::exportLog() const {

}

bool Bank::transfer(const String& fromIBAN, const String& toIBAN) {

	return true;
}

void Bank::display() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Customers count: " << customers.getSize() << std::endl;
	std::cout << "Accounts count: " << accounts.getSize() << std::endl;
}