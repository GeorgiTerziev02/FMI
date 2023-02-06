#include <iostream>
#include <vector>

int nearestValue(const std::vector<size_t>& numbers, size_t value) {
	if (value <= numbers[0])
		return 0;
	if (value >= numbers[numbers.size() - 1])
		return numbers.size() - 1;

	int left = 0;
	int right = numbers.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (numbers[mid] == value)
			return mid;
		else if (numbers[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}

	// left and right have swapped places

	size_t l = numbers[right];
	size_t r = numbers[left];
	if (value - l <= r - value)
		return right;

	return left;
}

int task2_2021() {
	int tasksCount, teamsCount;
	std::cin >> tasksCount >> teamsCount;

	std::vector<size_t> tasks;

	for (int i = 0; i < tasksCount; i++) {
		size_t task;
		std::cin >> task;
		tasks.push_back(task);
	}

	std::vector<size_t> teams;

	for (int i = 0; i < teamsCount; i++) {
		size_t team;
		std::cin >> team;
		teams.push_back(team);
	}

	for (int i = 0; i < teamsCount; i++)
	{
		int index = nearestValue(tasks, teams[i]);
		std::cout << tasks[index] << "\n";
	}

	return 0;
}
