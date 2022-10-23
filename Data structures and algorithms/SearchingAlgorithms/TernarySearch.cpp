#include<iostream>

int ternarySearch(int* arr, int length, int target) {
	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int mid1 = left + (right - left) / 3; // 2 * left + right
		int mid2 = right - (right - left) / 3; // 2*right + left

		if (arr[mid1] == target)
			return mid1;

		if (arr[mid2] == target)
			return mid2;

		if (target < arr[mid1]) {
			right = mid1 - 1;
		}
		else if (target > arr[mid2]) {
			left = mid2 + 1;
		}
		else {
			left = mid1 + 1;
			right = mid2 - 1;
		}
	}

	return -1;
}

int main() {
	int arr[] = { 1, 3, 4, 6, 8, 9, 10 };
	std::cout << ternarySearch(arr, 7, 0) << std::endl;
	std::cout << ternarySearch(arr, 7, 11) << std::endl;
	std::cout << ternarySearch(arr, 7, 1) << std::endl;
	std::cout << ternarySearch(arr, 7, 10) << std::endl;
	std::cout << ternarySearch(arr, 7, 5) << std::endl;
	std::cout << ternarySearch(arr, 7, 9) << std::endl;
}