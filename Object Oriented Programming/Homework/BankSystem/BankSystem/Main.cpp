#include <iostream>
#include "constants.h"
#include "Bank.h"
#include "NormalAccount.h"

int main() {
	Bank bank("BankName", "BankAddress");

	while (true) {
		char input[INPUT_BUFFER];
		std::cin.getline(input, INPUT_BUFFER);

		if (strcmp(input, EDIT_COMMAND) == 0) {

		}
		else if (strcmp(input, QUIT_COMMAND) == 0) {
			break;
		}
	}
}