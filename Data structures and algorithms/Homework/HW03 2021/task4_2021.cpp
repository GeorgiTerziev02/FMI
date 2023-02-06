#include <iostream>
#include <vector>
#include <algorithm>

int nearestIndex(const std::vector<int>& numbers, int target) {
	if (numbers.size() == 0)
		return -1;
	if (numbers[0] > target)
		return -1;
	if (numbers[numbers.size() - 1] <= target)
		return numbers.size() - 1;

	int left = 0;
	int right = numbers.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		// might have problem if we have more than one equal to target
		if (numbers[mid] == target) {

			while (mid + 1 < numbers.size() && numbers[mid + 1] == target)
				mid++;

			return mid;
		}
		else if (numbers[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right; // in this situation right is before left
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int elementsCoumt, queriesCount;
	std::cin >> elementsCoumt >> queriesCount;
	std::vector<int> elements;

	for (int i = 0; i < elementsCoumt; i++) {
		int num;
		std::cin >> num;
		elements.push_back(num);
	}

	std::sort(elements.begin(), elements.end());

	std::vector<unsigned long long int> sums(elementsCoumt);
	for (int i = 1; i < elementsCoumt; i++) {
		sums[i] = sums[i - 1] + elements[i];
	}

	for (int i = 0; i < queriesCount; i++)
	{
		size_t maxSum;
		int maxNum;
		std::cin >> maxSum >> maxNum;
		int index = nearestIndex(elements, maxNum);
		size_t sum = 0;
		size_t count = 0;
		while (index != -1)
		{
			if (sum + elements[index] <= maxSum)
			{
				sum += elements[index];
				count++;
			}
			else {
				break;
			}
			index--;
		}

		std::cout << count << "\n";
	}
}
