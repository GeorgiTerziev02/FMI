#include<iostream>

int binarySearch(int* arr, size_t length, int target) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		// handles the case when the sum
		// of left + right > INT_MAX
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

int exponentialSearch(int* arr, int length, int target) {
	int index = 1;
	while (index < length && arr[index] < target) {
		index *= 2;
	}

	int binaryIndex = binarySearch(
		arr + index / 2, // pointer to begining of the current subarray
		std::min(index + 1, length) - index / 2, // min of index and length
		target
	);

	if (binaryIndex != -1) {
		return binaryIndex + index / 2;
	}

	return -1;
}

int main() {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << exponentialSearch(arr, 10, 0) << std::endl;
	std::cout << exponentialSearch(arr, 10, 11) << std::endl;
	std::cout << exponentialSearch(arr, 10, 1) << std::endl;
	std::cout << exponentialSearch(arr, 10, 10) << std::endl;
	std::cout << exponentialSearch(arr, 10, 5) << std::endl;
	std::cout << exponentialSearch(arr, 10, 9) << std::endl;
}