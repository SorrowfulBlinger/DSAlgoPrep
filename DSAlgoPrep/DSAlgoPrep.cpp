// DSAlgoPrep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Rivers.h"
#include "LargestRange.h"
#include "maxProfitKTransactions.h"
#include "TrapRainWater.h"
#include "MaxPointLine.h"
#include "LinkedListCycleDetection.h"
#include "RemoveDuplicatesLL.h"
#include "BalancingParanthesis.h"
#include "WordLadderDFS.h"
#include "Bitset.h"
#include "MaximalMatchingBipartite.h"
#include "StableMatching.h"
#include <unordered_map>


class Person {
private:
public:
	int age;
	std::string name;
	Person(int age, std::string name) {
		this->age = age;
		this->name = name;
	}
};

class Person2 {
private:
public:
	int age;
	std::string name;
	Person2(int age, std::string name) {
		this->age = age;
		this->name = name;
	}
};

class Salary {
private:
public:
	int salary;
	Salary(int salary) {
		this->salary = salary;
	}
};

struct PersonComp {
	bool operator()(const Person & a, const Person& b) const {
		return a.age < b.age;
	}
};

struct Person2Comp {
	bool operator()(const Person2& a, const Person2& b) const {
		return a.age == b.age;
	}
};

struct Person2Hash {
	size_t operator()(const Person2 &a ) const {
		return std::hash<int>()(a.age);
	}
};

int main()
{
	// less than comaprator
	std::map<Person, Salary, PersonComp> data;
	
	// equals and hash comparator
	std::unordered_map<Person2, Salary, Person2Hash, Person2Comp> data1;

	data.insert({ Person(11, "Adi"), Salary(121)});

	std::cout << "Hello DS!\n";

	// https://www.algoexpert.io/questions/River%20Sizes
	auto val = new Rivers();
	val->execute();

	// https://www.algoexpert.io/questions/Largest%20Range
	auto val1 = new LargestRange();
	val1->execute();


	// https://www.algoexpert.io/questions/Max%20Profit%20With%20K%20Transactions
	auto val2 = new maxProfitKTransactions();
	val2->execute();

	// https://leetcode.com/problems/trapping-rain-water/
	auto val3 = new TrapRainWater();
	val3->execute();

	// https://leetcode.com/problems/max-points-on-a-line/
	auto val4 = new MaxPointLine();
	val4->execute();

	//https://leetcode.com/problems/linked-list-cycle/
	//https://www.youtube.com/watch?v=-YiQZi3mLq0
	//https://leetcode.com/problems/linked-list-cycle-ii/submissions/
	//https://leetcode.com/problems/reverse-linked-list/submissions/
	auto val5 = new LinkedListCycleDetection();
	val5->execute();

	//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
	auto val6 = new RemoveDuplicatesLL();
	val6->execute();

	//https://leetcode.com/problems/valid-parentheses/submissions/
	auto val7 = new BalancingParanthesis();
	val7->execute();


	//https://leetcode.com/problems/valid-parentheses/submissions/
	auto val8 = new WordLadderDFS();
	val8->execute();

	Bitset b;
	b.test();

	std::cout << "\n ***************** Stable Macthing ****************** \n";
	StableMatching s;
	
	// Perfect matching 
	/* 
	std::map<std::string, std::vector<std::string>> men{ 
		{"A", {"X", "Y", "Z"}}, 
		{"B", {"Y", "X", "Z"}},
		{"C", {"X", "Y", "Z"}}
	};
	
	std::map<std::string, std::vector<std::string>> women{
		{"X", {"B", "A", "C"}},
		{"Y", {"A", "B", "C"}},
		{"Z", {"A", "B", "C"}}
	}; */

	// Only 2 matching possble
	/*
	std::map<std::string, std::vector<std::string>> men{
		{"A", {"Y", "Z"}},
		{"B", {"Y", "X", "Z"}},
		{"C", {"X", "Y", "Z"}}
	};

	std::map<std::string, std::vector<std::string>> women{
		{"X", {"B", "A", "C"}},
		{"Y", { "B", "C"}},
		{"Z", { "B", "C"}}
	}; */

	// BackTrack
	std::map<std::string, std::vector<std::string>> men{
		{"A", {"X", "Z"}},
		{"B", {"X", "Y", "Z"}},
		{"C", {"X", "Y", "Z"}}
	};

	std::map<std::string, std::vector<std::string>> women{
		{"X", {"B", "A", "C"}},
		{"Y", { "B", "C"}},
		{"Z", { "B", "C"}}
	};

	auto val9 = s.getMatching(men, women);
	
	for (auto& p : val9) {
		std::cout << p.first << "-" << p.second << " , ";
	}
	
	std::cout << " ********************* Maximal Mathcing Bipartite graph ******************** \n";
	MaximalMatchingBipartite mbm;
	std::map<std::string, std::set<std::string>> adjList{ { "1A" , {"2B", "2C"}}, { "1B" , {} }, { "1C" , {"2A", "2D"} }, { "1D" , {"2C"} }, { "1E" , {"2D"} }, { "1F" , {"2F"} },
	{"2A" , {"1C"} }, { "2B" , {"1A"} }, { "2C" , {"1D", "1A", "1E"} }, { "2D" , {"1C", "1E"} }, { "2E" , {} }, { "2F" , {"1F"} }};
	std::set<std::pair<std::string, std::string>> matches = mbm.getMaxPairs(adjList);

	for (auto& p : matches) {
		if (p.first[0] == '$' || p.second[0] == '$') {
			continue;
		}
		std::cout << "(" <<p.first << "-" << p.second << ") , ";
	}

	std::cout << "\n Expected matching -  (1A-2B), (1C-2A), (1D-2C), (1E-2D), (1F-2F)\n";

	getchar();
	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
