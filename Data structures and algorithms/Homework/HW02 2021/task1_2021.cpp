#include<iostream>

void merge(int* firstArray, size_t firstArrayLength, int* secondArray, size_t secondArrayLength) {
	int* result = new int[firstArrayLength + secondArrayLength];

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

void mergeSort(int* arr, size_t length) {
	if (length <= 1)
		return;

	size_t mid = length / 2;
	mergeSort(arr, mid);
	mergeSort(arr + mid, length - mid);
	merge(arr, mid, arr + mid, length - mid);
}

void task1()
{
	int n;
	std::cin >> n;
	int* arr = new int[n];
	for (size_t i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	int k;
	std::cin >> k;

	mergeSort(arr, n);

	int sum = 0;
	for (size_t i = 0; i < k; i++)
		sum += arr[i];

	std::cout << sum;
}