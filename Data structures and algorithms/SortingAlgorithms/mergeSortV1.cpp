#include <iostream>

void print(const int* arr, size_t length) {
	for (size_t i = 0; i < length; i++)
		std::cout << arr[i] << " ";
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void merge(int* firstArray, size_t firstArrayLength, int* secondArray, size_t secondArrayLength) {
	int* result = new int[firstArrayLength + secondArrayLength];

	size_t firstArrayIndex = 0, secondArrayIndex = 0, resultIndex = 0;

	while (firstArrayIndex < firstArrayLength && secondArrayIndex < secondArrayLength) {
		if (firstArray[firstArrayIndex] <= secondArray[secondArrayIndex])
			result[resultIndex++] = firstArray[firstArrayIndex++];
		else
			result[resultIndex++] = secondArray[secondArrayIndex++];
	}

	while (firstArrayIndex < firstArrayLength)
		result[resultIndex++] = firstArray[firstArrayIndex++];

	while (secondArrayIndex < secondArrayLength)
		result[resultIndex++] = secondArray[secondArrayIndex++];

	// bring back the values to the original array using the first pointer
	for (size_t i = 0; i < resultIndex; i++)
		firstArray[i] = result[i];

	delete[] result;
}

void mergeSort(int* arr, size_t length) {
	if (length <= 1)
		return;

	size_t mid = length / 2;
	mergeSort(arr, mid); // first half
	mergeSort(arr + mid, length - mid); // second half (moving the pointer)
	merge(arr, mid, arr + mid, length - mid); // first and second half
}

int main() {
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	mergeSort(arr, 9);
	print(arr, 9);
}