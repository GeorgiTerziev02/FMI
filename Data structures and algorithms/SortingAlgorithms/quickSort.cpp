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

int partition(int* arr, int startIndex, int endIndex) {
	int pivot = arr[endIndex];

	size_t currentElementToPlaceIndex = startIndex; // index of next lower than pivot number to be placed

	for (size_t i = startIndex; i < endIndex; i++) {
		if (arr[i] <= pivot)
			swap(arr[i], arr[currentElementToPlaceIndex++]);
	}

	swap(arr[currentElementToPlaceIndex], arr[endIndex]);

	return currentElementToPlaceIndex;
}

int randomPartition(int arr[], int startIndex, int endIndex)
{
	srand(time(NULL));
	int randomIndex = startIndex + rand() % (endIndex - startIndex);
	swap(arr[randomIndex], arr[endIndex]); // put random number on last position

	return partition(arr, startIndex, endIndex);
}


void quickSort(int arr[], int startIndex, int endIndex) {
	if (startIndex >= endIndex)
		return;

	// pivot will be on its real position
	size_t partitionIndex = randomPartition(arr, startIndex, endIndex);

	quickSort(arr, startIndex, partitionIndex - 1); // one step before the pivot
	quickSort(arr, partitionIndex + 1, endIndex); // one step after the pivot
}

int main() {
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	quickSort(arr, 0, 8);
	print(arr, 8);
}