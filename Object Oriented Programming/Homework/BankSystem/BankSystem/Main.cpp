#include <iostream>
#include "constants.h"
#include "Bank.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"

// Remove all error flags and characters from the input buffer
void clearInputBuffer() {
	// because of using both getline and cin we have to cin.ignore;
	// cin leaves the newline character in the stream which will be read as input from the getline

	std::cin.clear();    // clears errors flags from the cin
	std::cin.sync();        // discard unread characters from the input buffer
	std::cin.ignore();    // discard characters from the input buffer
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

				String name;
				std::cout << "Enter name:" << std::endl;
				std::cin >> name;

				String address;
				std::cout << "Enter address:" << std::endl;
				std::cin >> address;

				Customer* customer = new Customer(id, name, address);
				bank.addCustomer(customer);
				std::cout << "Customer created" << std::endl;
			}
			else if (strcmp(input, DELETE_CUSTOMER_COMMAND) == 0) {
				size_t id;
				std::cout << "Enter id:" << std::endl;
				std::cin >> id;

				bank.deleteCustomer(id);
				std::cout << "Customer deleted" << std::endl;
			}
			else if (strcmp(input, ADD_ACCOUNT_COMMAND) == 0) {

				String userName;
				std::cout << "Enter username:" << std::endl;
				std::cin >> userName;

				String password;
				std::cout << "Enter password:" << std::endl;
				std::cin >> password;

				String iBAN;
				std::cout << "Enter IBAN:" << std::endl;
				std::cin >> iBAN;

				size_t ownerId;
				std::cout << "Enter owner id:" << std::endl;
				std::cin >> ownerId;

				String type;
				std::cout << "Enter account type:" << std::endl;
				std::cin >> type;

				Account* account = nullptr;

				if (type == PRIVILEGE_ACCOUNT)
				{
					double overdraft;
					std::cout << "Enter overdraft:" << std::endl;
					std::cin >> overdraft;
					account = new PrivilegeAccount(userName, password, iBAN, ownerId, overdraft);
				}
				else if (type == SAVINGS_ACCOUNT) 
				{
					double interestRate;
					std::cout << "Enter interest:" << std::endl;
					std::cin >> interestRate;
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
				String iBAN;
				std::cout << "Enter IBAN:" << std::endl;
				std::cin >> iBAN;

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

				bank.listCustomerAccount(id);
			}
			else if (strcmp(input, LIST_LOG_COMMAND) == 0) {
				bank.listLog();
			}
			else if (strcmp(input, WITHDRAW_COMMAND) == 0) {
				String iBAN;
				std::cout << "Enter IBAN:" << std::endl;
				std::cin >> iBAN;
				std::cout << "Enter amount:" << std::endl;
				double amount;
				std::cin >> amount;

				bank.withdraw(iBAN, amount);
			}
			else if (strcmp(input, DEPOSIT_COMMAND) == 0) {
				String iBAN;
				std::cout << "Enter IBAN:" << std::endl;
				std::cin >> iBAN;
				double amount;
				std::cout << "Enter amount:" << std::endl;
				std::cin >> amount;

				bank.deposit(iBAN, amount);
			}
			else if (strcmp(input, TRANSFER_COMMAND) == 0) {
				String fromIBAN;
				std::cout << "Enter from IBAN:" << std::endl;
				std::cin >> fromIBAN;

				String toIBAN;
				std::cout << "Enter to IBAN:" << std::endl;
				std::cin >> toIBAN;

				double amount;
				std::cout << "Enter amount:" << std::endl;
				std::cin >> amount;

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

		clearInputBuffer();
	}

	bank.exportLog();
}