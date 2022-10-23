#include<iostream>

int ternarySearch(int* arr, int left, int right, int target) {
	if (left > right)
		return -1;

	// handles the case when the sum
	// of left + right > INT_MAX
	int mid1 = left + (right - left) / 3; // 2 * left + right
	int mid2 = right - (right - left) / 3; // 2*right + left

	if (arr[mid1] == target)
		return mid1;

	if (arr[mid2] == target)
		return mid2;

	if (target < arr[mid1])
		return ternarySearch(arr, left, mid1 - 1, target);
	else if (target < arr[mid2])
		return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
	else
		return ternarySearch(arr, mid2 + 1, right, target);
}

int main() {
	int arr[] = { 1, 3, 4, 6, 8, 9, 10 };
	std::cout << ternarySearch(arr, 0, 6, 0) << std::endl;
	std::cout << ternarySearch(arr, 0, 6, 11) << std::endl;
	std::cout << ternarySearch(arr, 0, 6, 1) << std::endl;
	std::cout << ternarySearch(arr, 0, 6, 10) << std::endl;
	std::cout << ternarySearch(arr, 0, 6, 5) << std::endl;
	std::cout << ternarySearch(arr, 0, 6, 9) << std::endl;
}