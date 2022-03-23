#include <iostream>
#include <fstream>

using namespace std;

const int COMPANY_NAME_MAX_SIZE = 25;
const char FILE_PATH[] = "file.bin";

struct Job {
	char companyName[COMPANY_NAME_MAX_SIZE];
	int coWorkers;
	int paidLeave;
	long long salary;
};

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

bool strCmp(const char* str1, const char* str2) {
	int length1 = strLength(str1);
	int length2 = strLength(str2);

	if (length1 != length2) return false;

	for (size_t i = 0; i < length1; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}

	return true;
}

bool addJobToFile(const Job& job) {
	ofstream myFile(FILE_PATH, std::ios::binary | std::ios::app);
	if (!myFile.is_open()) {
		return false;
	}
	myFile.write((const char*)&job, sizeof(Job));
	myFile.close();
	return true;
}

//bool addJobsToFile(const Job* jobs, int length) {
//	ofstream myFile(FILE_PATH, std::ofstream::app);
//	myFile.write((const char*)&jobs, length * sizeof(Job));
//	myFile.close();
//	return true;
//}

int getFileSize(ifstream& myFile) {
	int current = myFile.tellg();
	myFile.seekg(0, ios::end);
	int size = myFile.tellg();
	myFile.seekg(current, ios::beg);

	return size;
}

void filterOffers(const char* filePath, long long minSalary) {
	ifstream myFile(filePath, std::ios::binary);

	if (!myFile.is_open())
	{
		return;
	}

	int fileSize = getFileSize(myFile);
	int arraySize = fileSize / sizeof(Job);

	for (size_t i = 0; i < arraySize; i++)
	{
		Job job;
		myFile.read((char*)&job, sizeof(Job));

		if (job.salary >= minSalary)
		{
			cout << job.companyName << endl;
		}
	}
	myFile.close();
}

bool existOffer(const char* filePath, const char* name) {
	ifstream myFile(filePath, std::ios::binary);

	if (!myFile.is_open())
	{
		return false;
	}

	int fileSize = getFileSize(myFile);
	int arraySize = fileSize / sizeof(Job);

	for (size_t i = 0; i < arraySize; i++)
	{
		Job job;
		myFile.read((char*)&job, sizeof(Job));

		if (strCmp(job.companyName, name))
		{
			myFile.close();
			return true;
		}
	}

	myFile.close();
	return false;
}

void clearConsole() {
	cin.clear();
	cin.ignore(255, '\n');
}

int main()
{
	//int n;
	//cin >> n;

	//for (size_t i = 0; i < n; i++)
	//{
	//	Job job;
	//	clearConsole();
	//	cin.getline(job.companyName, COMPANY_NAME_MAX_SIZE);
	//	cin >> job.coWorkers;
	//	cin >> job.paidLeave;
	//	cin >> job.salary;

	//	addJobToFile(job);
	//}
	//filterOffers(FILE_PATH, -20);
	cout << existOffer(FILE_PATH, "test1") << endl;
	cout << existOffer(FILE_PATH, "test144");
}