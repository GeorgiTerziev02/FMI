
#include<iostream>

int binarySearch(int* arr, int left, int right, int target) {
	if (left > right)
		return -1;

	// handles the case when the sum
	// of left + right > INT_MAX
	int mid = left + (right - left) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return binarySearch(arr, left, mid - 1, target);

	return binarySearch(arr, mid + 1, right, target);
}

int main() {
	int arr[] = { 1, 3, 4, 6, 8, 9, 10 };
	std::cout << binarySearch(arr, 0, 6, 2);
}