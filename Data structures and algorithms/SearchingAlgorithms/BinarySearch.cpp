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

int main() {
	int arr[] = { 1, 3, 4, 6, 8, 9, 10 };
	std::cout << binarySearch(arr, 7, 3);
}