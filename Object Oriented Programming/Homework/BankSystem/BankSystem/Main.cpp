#include <iostream>
#include "constants.h"
#include "Bank.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

int main() {
	Bank bank("BankName", "BankAddress");

	while (true) {
		char input[INPUT_BUFFER];
		std::cin.getline(input, INPUT_BUFFER);

		try
		{
			if (strcmp(input, ADD_CUSTOMER_COMMAND) == 0) {
				size_t id;
				std::cin >> id;

				String name;
				std::cin >> name;

				String address;
				std::cin >> address;

				Customer* customer = new Customer(id, name, address);
				bank.addCustomer(customer);
			}
			else if (strcmp(input, DELETE_CUSTOMER_COMMAND) == 0) {
				size_t id;
				std::cin >> id;

				bank.deleteCustomer(id);
			}
			else if (strcmp(input, ADD_ACCOUNT_COMMAND) == 0) {

				String userName;
				std::cin >> userName;

				String password;
				std::cin >> password;

				String iBAN;
				std::cin >> iBAN;

				size_t ownerId;
				std::cin >> ownerId;

				String type;
				std::cin >> type;

				Account* account = nullptr;

				if (type == PRIVILEGE_ACCOUNT)
				{
					double overdraft;
					std::cin >> overdraft;
					account = new PrivilegeAccount(userName, password, iBAN, ownerId, overdraft);
				}
				else if (type == SAVINGS_ACCOUNT) 
				{
					double interestRate;
					std::cin >> interestRate;
					account = new SavingsAccount(userName, password, iBAN, ownerId, interestRate);
				}
				else 
				{
					account = new NormalAccount(userName, password, iBAN, ownerId);
				}

				bank.addAccount(account);
			}
			else if (strcmp(input, DELETE_ACCOUNT_COMMAND) == 0) {
				String iBAN;
				std::cin >> iBAN;

				bank.deleteAccount(iBAN);
			}
			else if (strcmp(input, LIST_CUSTOMERS_COMMAND) == 0) {
				bank.listCustomers();
			}
			else if (strcmp(input, LIST_ACCOUNTS_COMMAND) == 0) {
				bank.listAccounts();
			}
			else if (strcmp(input, LIST_CUSTOMER_ACCOUNTS_COMMAND) == 0) {
				size_t id;
				std::cin >> id;

				bank.listCustomerAccount(id);
			}
			else if (strcmp(input, LIST_LOG_COMMAND) == 0) {
				bank.listLog();
			}
			else if (strcmp(input, WITHDRAW_COMMAND) == 0) {
				String iBAN;
				std::cin >> iBAN;
				double amount;
				std::cin >> amount;

				bank.withdraw(iBAN, amount);
			}
			else if (strcmp(input, DEPOSIT_COMMAND) == 0) {
				String iBAN;
				std::cin >> iBAN;
				double amount;
				std::cin >> amount;

				bank.deposit(iBAN, amount);
			}
			else if (strcmp(input, TRANSFER_COMMAND) == 0) {
				String fromIBAN;
				std::cin >> fromIBAN;
				String toIBAN;
				std::cin >> toIBAN;
				double amount;
				std::cin >> amount;

				bank.transfer(fromIBAN, toIBAN, amount);
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

		bank.exportLog();
	}
}