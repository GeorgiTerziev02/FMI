#include<iostream>

template<typename T>
void merge(T* firstArray, size_t firstArrayLength, T* secondArray, size_t secondArrayLength) {
	T* result = new T[firstArrayLength + secondArrayLength];

	size_t firstArrIndex = 0, secondArrIndex = 0, resultArrIndex = 0;
	while (firstArrIndex < firstArrayLength && secondArrIndex < secondArrayLength) {
		if (firstArray[firstArrIndex] <= secondArray[secondArrIndex])
			result[resultArrIndex++] = firstArray[firstArrIndex++];
		else
			result[resultArrIndex++] = secondArray[secondArrIndex++];
	}

	while (firstArrIndex < firstArrayLength)
		result[resultArrIndex++] = firstArray[firstArrIndex++];

	while (secondArrIndex < secondArrayLength)
		result[resultArrIndex++] = secondArray[secondArrIndex++];

	for (size_t i = 0; i < resultArrIndex; i++)
		firstArray[i] = result[i];

	delete[] result;
}

template<typename T>
void mergeSort(T* arr, size_t length) {
	if (length <= 1)
		return;

	size_t mid = length / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, length - mid);
	merge(arr, mid, arr + mid, length - mid);
}

struct Time {
	short seconds, minutes, hours;
};

struct DateTime {
	size_t index;
	Time time;
	short days, month;
	int year;
};

bool operator<=(const Time& lhs, const Time& rhs) {
	if (lhs.hours == rhs.hours) {
		if (lhs.minutes == rhs.minutes)
			return lhs.seconds <= rhs.seconds;

		return lhs.minutes <= rhs.minutes;
	}

	return lhs.hours <= rhs.hours;
}

bool operator<=(const DateTime& lhs, const DateTime& rhs) {
	if (lhs.year == rhs.year) {
		if (lhs.month == rhs.month) {
			if (lhs.days == rhs.days)
				return lhs.time <= rhs.time;

			return lhs.days <= rhs.days;
		}

		return lhs.month <= rhs.month;
	}

	return lhs.year <= rhs.year;
}

void task2()
{
	int n;
	std::cin >> n;
	DateTime* arr = new DateTime[n];
	for (size_t i = 0; i < n; i++) {
		std::string time;
		std::cin >> time;
		arr[i].index = i + 1;
		arr[i].time.hours = ((int)time[0]) * 10 + (int)time[1];
		arr[i].time.minutes = ((int)time[3]) * 10 + (int)time[4];
		arr[i].time.seconds = ((int)time[6]) * 10 + (int)time[7];

		std::string date;
		std::cin >> date;
		arr[i].days = ((int)date[0]) * 10 + (int)date[1];
		arr[i].month = ((int)date[3]) * 10 + (int)date[4];
		arr[i].year = ((int)date[6]) * 1000 + ((int)date[7]) * 100 + ((int)date[8]) * 10 + ((int)date[9]);
	}

	mergeSort(arr, n);

	for (size_t i = 0; i < n; i++)
		std::cout << arr[i].index << "\n";
}