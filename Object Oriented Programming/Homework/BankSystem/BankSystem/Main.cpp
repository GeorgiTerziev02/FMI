#include <iostream>
#include "constants.h"
#include "Bank.h"
#include "NormalAccount.h"

int main() {
	Bank bank("BankName", "BankAddress");

	while (true) {
		char input[INPUT_BUFFER];
		std::cin.getline(input, INPUT_BUFFER);

		try
		{
			if (strcmp(input, ADD_CUSTOMER_COMMAND) == 0) {

			}
			else if (strcmp(input, DELETE_CUSTOMER_COMMAND) == 0) {

			}
			else if (strcmp(input, ADD_ACCOUNT_COMMAND) == 0) {

			}
			else if (strcmp(input, DELETE_ACCOUNT_COMMAND) == 0) {

			}
			else if (strcmp(input, LIST_CUSTOMERS_COMMAND) == 0) {

			}
			else if (strcmp(input, LIST_ACCOUNTS_COMMAND) == 0) {

			}
			else if (strcmp(input, LIST_CUSTOMER_ACCOUNTS_COMMAND) == 0) {

			}
			else if (strcmp(input, LIST_LOG_COMMAND) == 0) {

			}
			else if (strcmp(input, WITHDRAW_COMMAND) == 0) {

			}
			else if (strcmp(input, DEPOSIT_COMMAND) == 0) {

			}
			else if (strcmp(input, TRANSFER_COMMAND) == 0) {

			}
			else if (strcmp(input, INFO_COMMAND) == 0) {

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
}