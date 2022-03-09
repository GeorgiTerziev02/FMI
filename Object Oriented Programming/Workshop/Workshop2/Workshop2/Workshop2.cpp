#include <iostream>
#include <fstream>

using namespace std;

const int PROPERTY_MAX_SIZE = 128;
const int MAX_USERS = 100;
const int BUFFER_SIZE = 50;

const char REGISTER_COMMAND[] = "register";
const char LOGIN_COMMAND[] = "login";
const char INPUT_CHARACTER = '>';

const char SYSTEM_FILE_NAME[] = "system.txt";

struct User {
	char name[PROPERTY_MAX_SIZE];
	char email[PROPERTY_MAX_SIZE];
	char password[PROPERTY_MAX_SIZE];
};

struct System {
	User users[MAX_USERS];
	size_t size = 0;
};

size_t getStringLength(const char* str) {
	int count = 0;
	while (str[count] != '\0') count++;

	return count;
}

bool areStringsEqual(const char* str1, const char* str2) {
	size_t str1Length = getStringLength(str1);
	size_t str2Length = getStringLength(str2);
	if (str1Length != str2Length)
	{
		return false;
	}

	int index = 0;
	while (index != str1Length)
	{
		if (str1[index] != str2[index])
		{
			return false;
		}

		index++;
	}

	return true;
}

bool addUserToSystem(const User& user, System& system) {
	if (system.size == MAX_USERS)
	{
		return false;
	}

	system.users[system.size++] = user;
	return true;
}

User readUserFromFile(ifstream& file) {
	User user;
	file >> user.name >> user.email >> user.password;

	return user;
}

void writeUserToFile(const User& user, ofstream& file) {
	file << user.name << endl << user.email << endl << user.password << endl;
}

System readSystemFromFile(const char* fileName) {
	ifstream file(fileName);

	System system;
	if (!file.is_open())
	{
		return system;
	}

	int usersSize;
	file >> usersSize;
	for (size_t i = 0; i < usersSize && !file.eof(); i++)
	{
		User user = readUserFromFile(file);
		addUserToSystem(user, system);
	}

	file.close();
	return system;
}

bool writeSystemToFile(const char* fileName, const System& system) {
	ofstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file << system.size << endl;
	for (size_t i = 0; i < system.size; i++)
	{
		writeUserToFile(system.users[i], file);
	}

	file.close();
	return true;
}

bool registerUser(System& system) {
	User newUser;
	cout << "Enter name:" << endl << INPUT_CHARACTER;
	cin.getline(newUser.name, PROPERTY_MAX_SIZE);

	cout << "Enter email:" << endl << INPUT_CHARACTER;
	cin.getline(newUser.email, PROPERTY_MAX_SIZE);

	cout << "Enter password:" << endl << INPUT_CHARACTER;
	cin.getline(newUser.password, PROPERTY_MAX_SIZE);

	addUserToSystem(newUser, system);
	return writeSystemToFile(SYSTEM_FILE_NAME, system);
}

bool loginUser(const System& system) {
	User user;
	cout << "Enter email:" << endl << INPUT_CHARACTER;
	cin.getline(user.email, PROPERTY_MAX_SIZE);

	cout << "Enter password:" << endl << INPUT_CHARACTER;
	cin.getline(user.password, PROPERTY_MAX_SIZE);

	for (size_t i = 0; i < system.size; i++)
	{
		User currentUser = system.users[i];
		if (areStringsEqual(currentUser.email, user.email)
			&& areStringsEqual(currentUser.password, user.password))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	System system = readSystemFromFile(SYSTEM_FILE_NAME);

	while (true)
	{
		cout << "Enter command:" << endl;
		cout << INPUT_CHARACTER;

		char input[BUFFER_SIZE];
		cin.getline(input, BUFFER_SIZE);

		if (areStringsEqual(input, REGISTER_COMMAND))
		{
			bool result = registerUser(system);

			result ? cout << "Registration successful" << endl : cout << "Unsuccessful registration" << endl;
		}
		else if (areStringsEqual(input, LOGIN_COMMAND))
		{
			bool result = loginUser(system);

			result ? cout << "Login successful" << endl : cout << "Unsuccessful login" << endl;
		}

		cout << endl;
	}
}