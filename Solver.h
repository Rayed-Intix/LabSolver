#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Solver
{
private:
	struct Task
	{
		std::string name;
		std::function<void()> func;
	};

	std::vector<Task> Tasks;

	bool ExecuteTask(int _index);
public:
	Solver(const std::vector<Task>& _TaskList) : Tasks(_TaskList) {};

	void ShowTasks();
	void SelectTask();
	void StartUp(bool _inf = true);

};

void Solver::ShowTasks()
{
	for (int i = 0; i < Tasks.size(); i++)
		std::cout << i + 1 << " - " << (Tasks.at(i).name.empty() ? "Task" + std::to_string(i + 1) : Tasks.at(i).name) << '\n';
}

bool Solver::ExecuteTask(int _index)
{
	if (_index < Tasks.size() && _index >= 0) {
		Tasks.at(_index).func();
		return true;
	}
	else {
		std::cerr << "Invalid Input. Try again!\n";
		return false;
	}
}

void Solver::SelectTask()
{
	int n;
	do{
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid Input. Please Enter a Valid Number!\n";
		}
	} while (!ExecuteTask(n - 1));
}

void Solver::StartUp(bool _inf)
{
	char input;

	std::cout << "Enter Number Of Task : \n";
	ShowTasks();
	SelectTask();

	while (_inf)
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Do you want to try again? (y/n)\n";
		std::cin >> input;
		if (input == 'y') {
			std::cout << "Enter Number Of Task : \n";
			ShowTasks();
			SelectTask();
		}
		if (input == 'n')
			_inf = false;
	}
}
