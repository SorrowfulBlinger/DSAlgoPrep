#include "pch.h"
#include "TrapRainWater.h"
#include <vector>
#include <iostream>
#include <stack>
#include <climits>
#include <queue>


TrapRainWater::TrapRainWater()
{
}


TrapRainWater::~TrapRainWater()
{
}

struct Person {
	int age;
	std::string name;

	Person (int age, std::string name) {
		this->age = age;
		this->name = name;
	}
};

struct comparePerson {

	bool operator()(const Person a, const Person b) {
		return a.name < b.name;
	}
};

void priorityQ() {
	
	std::priority_queue<Person, std::vector<Person>, comparePerson> pq;

	pq.push(Person(10, "Disha"));
	pq.push(Person(20, "Aditya"));
	pq.push(Person(30, "Zebra"));
	pq.push(Person(40, "Debra"));

	while (!pq.empty()) {
		std::string val = pq.top().name;
		std::cout << val.c_str() << " ,";
		pq.pop();
	}
}

int TrapRainWater::totalWater(std::vector<int> buildings) {
	int prevHeight = INT_MIN;
	int currHeight;
	std::stack<int> prevBuildings;
	int total = 0;
	for (int i = 0; i < buildings.size(); i++) {
		currHeight = buildings[i];
		int multiplier = 0;
		if (currHeight > prevHeight && prevBuildings.size() > 0) {
			int lastBuilding = prevBuildings.top();
			if (currHeight >= buildings[lastBuilding]) {
				prevBuildings.pop();
				multiplier = (buildings[lastBuilding + 1] - buildings[lastBuilding]);
				total += multiplier * (i - lastBuilding - 1);
				while (!prevBuildings.empty()) {
					lastBuilding = prevBuildings.top();
					if (currHeight >= buildings[lastBuilding]) {
						prevBuildings.pop();
						multiplier = (buildings[lastBuilding + 1] - buildings[lastBuilding]);
						total += multiplier * (i - lastBuilding - 1);
					}
					else {
						multiplier = currHeight - buildings[lastBuilding + 1];
						buildings[lastBuilding + 1] = currHeight;
						total += multiplier * (i - lastBuilding - 1);
						break;
					}
				}
			} else {
				multiplier = currHeight - buildings[lastBuilding + 1];
				buildings[lastBuilding + 1] = currHeight;
				total += multiplier * (i - lastBuilding - 1);
			}
			
		}
		else if (currHeight < prevHeight) {
			prevBuildings.push(i - 1);
		}
		prevHeight = currHeight;
	}
	return total;
}

void TrapRainWater::execute(){
	//std::cout << "\n\n*************************** Total water: " << totalWater(std::vector<int>{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 });
	std::cout << "\n\n*************************** Total water: " << totalWater(std::vector<int>{ 0, 2, 1, 3, 0, 1, 2, 1, 2, 1});
	std::cout << "\n\n*************************** PQ : ";
	priorityQ();
};