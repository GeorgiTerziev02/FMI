#include<iostream>

int jumpSearch(int* arr, int length, int target) {
	int left = 0;
	int step = sqrt(length);
	int right = step;

	while (right < length && arr[right] <= target) {
		left += step;
		right += step;
		if (right > length - 1)
			right = length;
	}

	for (int i = left; i < right; i++) {
		if (arr[i] == target)
			return i;
	}

	return -1;
}

int main() {
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::cout << jumpSearch(arr, 10, 0) << std::endl;
	std::cout << jumpSearch(arr, 10, 11) << std::endl;
	std::cout << jumpSearch(arr, 10, 1) << std::endl;
	std::cout << jumpSearch(arr, 10, 10) << std::endl;
	std::cout << jumpSearch(arr, 10, 5) << std::endl;
	std::cout << jumpSearch(arr, 10, 9) << std::endl;
}