
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

void merge(int* arr, size_t leftIndex, size_t midIndex, size_t rightIndex) {
	size_t arr1Size = midIndex - leftIndex + 1;
	size_t arr2Size = rightIndex - midIndex;
	int* arr1 = new int[arr1Size];
	int* arr2 = new int[arr2Size];

	for (size_t i = 0; i < arr1Size; i++)
		arr1[i] = arr[leftIndex + i];
	for (size_t i = 0; i < arr2Size; i++)
		arr2[i] = arr[midIndex + 1 + i];

	int firstArrayIndex = 0, secondArrayIndex = 0, resultIndex = leftIndex;

	while (firstArrayIndex < arr1Size && secondArrayIndex < arr2Size) {
		if (arr1[firstArrayIndex] <= arr2[secondArrayIndex])
			arr[resultIndex++] = arr1[firstArrayIndex++];
		else
			arr[resultIndex++] = arr2[secondArrayIndex++];
	}

	while (firstArrayIndex < arr1Size)
		arr[resultIndex++] = arr1[firstArrayIndex++];

	while (secondArrayIndex < arr2Size)
		arr[resultIndex++] = arr2[secondArrayIndex++];

	delete[] arr1;
	delete[] arr2;
}

void mergeSort(int* arr, size_t leftIndex, size_t rightIndex) {
	if (leftIndex >= rightIndex)
		return;

	size_t mid = (leftIndex + rightIndex) / 2;
	mergeSort(arr, leftIndex, mid);
	mergeSort(arr, mid + 1, rightIndex);
	merge(arr, leftIndex, mid, rightIndex);
}

int main() {
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	mergeSort(arr, 0, 8);
	print(arr, 9);
}