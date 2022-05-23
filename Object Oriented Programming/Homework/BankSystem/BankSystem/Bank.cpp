#include "Bank.h"

Bank::Bank(const String& name, const String& address) {
	this->name = name;
	this->address = address;
}

Bank::~Bank() {
	for (size_t i = 0; i < customers.getSize(); i++)
		delete customers[i];

	for (size_t i = 0; i < accounts.getSize(); i++)
		delete customers[i];
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

}

void Bank::display() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Address: " << address << std::endl;
	std::cout << "Customers count: " << customers.getSize() << std::endl;
	std::cout << "Accounts count: " << accounts.getSize() << std::endl;
}