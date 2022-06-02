#include <iostream>
#include "constants.h"
#include "Bank.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

void clearInputBuffer() {
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
}

int main() {
	Bank bank("BankName", "BankAddress");

	while (true) {
		char input[INPUT_BUFFER];
		std::cout << "Enter command:" << std::endl;
		std::cin.getline(input, INPUT_BUFFER);

		try
		{
			if (strcmp(input, ADD_CUSTOMER_COMMAND) == 0) {
				size_t id;
				std::cout << "Enter id:" << std::endl;
				std::cin >> id;
				clearInputBuffer();

				char name[INPUT_BUFFER];
				std::cout << "Enter name:" << std::endl;
				std::cin.getline(name, INPUT_BUFFER);

				char address[INPUT_BUFFER];
				std::cout << "Enter address:" << std::endl;
				std::cin.getline(address, INPUT_BUFFER);

				Customer* customer = new Customer(id, name, address);
				bank.addCustomer(customer);
				std::cout << "Customer created" << std::endl;
			}
			else if (strcmp(input, DELETE_CUSTOMER_COMMAND) == 0) {
				size_t id;
				std::cout << "Enter id:" << std::endl;
				std::cin >> id;
				clearInputBuffer();

				bank.deleteCustomer(id);
				std::cout << "Customer deleted" << std::endl;
			}
			else if (strcmp(input, ADD_ACCOUNT_COMMAND) == 0) {

				char userName[INPUT_BUFFER];
				std::cout << "Enter username:" << std::endl;
				std::cin.getline(userName, INPUT_BUFFER);

				char password[INPUT_BUFFER];
				std::cout << "Enter password:" << std::endl;
				std::cin.getline(password, INPUT_BUFFER);

				char iBAN[INPUT_BUFFER];
				std::cout << "Enter IBAN:" << std::endl;
				std::cin.getline(iBAN, INPUT_BUFFER);

				size_t ownerId;
				std::cout << "Enter owner id:" << std::endl;
				std::cin >> ownerId;
				clearInputBuffer();

				char type[INPUT_BUFFER];
				std::cout << "Enter account type:" << std::endl;
				std::cin.getline(type, INPUT_BUFFER);

				Account* account = nullptr;

				if (strcmp(type, PRIVILEGE_ACCOUNT) == 0)
				{
					double overdraft;
					std::cout << "Enter overdraft:" << std::endl;
					std::cin >> overdraft;
					clearInputBuffer();
					account = new PrivilegeAccount(userName, password, iBAN, ownerId, overdraft);
				}
				else if (strcmp(type, SAVINGS_ACCOUNT) == 0)
				{
					double interestRate;
					std::cout << "Enter interest:" << std::endl;
					std::cin >> interestRate;
					clearInputBuffer();
					account = new SavingsAccount(userName, password, iBAN, ownerId, interestRate);
				}
				else 
				{
					account = new NormalAccount(userName, password, iBAN, ownerId);
				}

				bank.addAccount(account);
				std::cout << "Account created" << std::endl;
			}
			else if (strcmp(input, DELETE_ACCOUNT_COMMAND) == 0) {
				char iBAN[INPUT_BUFFER];
				std::cout << "Enter IBAN:" << std::endl;
				std::cin.getline(iBAN, INPUT_BUFFER);

				bank.deleteAccount(iBAN);
				std::cout << "Account deleted" << std::endl;
			}
			else if (strcmp(input, LIST_CUSTOMERS_COMMAND) == 0) {
				bank.listCustomers();
			}
			else if (strcmp(input, LIST_ACCOUNTS_COMMAND) == 0) {
				bank.listAccounts();
			}
			else if (strcmp(input, LIST_CUSTOMER_ACCOUNTS_COMMAND) == 0) {
				size_t id;
				std::cout << "Enter id:" << std::endl;
				std::cin >> id;
				clearInputBuffer();

				bank.listCustomerAccount(id);
			}
			else if (strcmp(input, LIST_LOG_COMMAND) == 0) {
				bank.listLog();
			}
			else if (strcmp(input, WITHDRAW_COMMAND) == 0) {
				char iBAN[INPUT_BUFFER];
				std::cout << "Enter IBAN:" << std::endl;
				std::cin.getline(iBAN, INPUT_BUFFER);
				std::cout << "Enter amount:" << std::endl;
				double amount;
				std::cin >> amount;
				clearInputBuffer();

				bank.withdraw(iBAN, amount);
			}
			else if (strcmp(input, DEPOSIT_COMMAND) == 0) {
				char iBAN[INPUT_BUFFER];
				std::cout << "Enter IBAN:" << std::endl;
				std::cin.getline(iBAN, INPUT_BUFFER);
				std::cout << "Enter amount:" << std::endl;
				double amount;
				std::cin >> amount;
				clearInputBuffer();

				bank.deposit(iBAN, amount);
			}
			else if (strcmp(input, TRANSFER_COMMAND) == 0) {
				char fromIBAN[INPUT_BUFFER];
				std::cout << "Enter from IBAN:" << std::endl;
				std::cin.getline(fromIBAN, INPUT_BUFFER);

				char toIBAN[INPUT_BUFFER];
				std::cout << "Enter to IBAN:" << std::endl;
				std::cin.getline(toIBAN, INPUT_BUFFER);

				double amount;
				std::cout << "Enter amount:" << std::endl;
				std::cin >> amount;
				clearInputBuffer();

				bank.transfer(fromIBAN, toIBAN, amount);
				std::cout << "Money transfered" << std::endl;
			}
			else if (strcmp(input, INFO_COMMAND) == 0) {
				bank.display();
			}
			else if (strcmp(input, QUIT_COMMAND) == 0) {
				break;
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}

	bank.exportLog();
}