#include "pch.h"
#include "Bitset.h"
#include <bitset>
#include <iostream>
#include <vector>

Bitset::Bitset()
{
}


Bitset::~Bitset()
{
}

void Bitset::test() {
	std::cout << "\n";
	std::bitset<10> num;
	num[0] = true;
	num |= num << 2;

	// Knapsack - Find if sum can be made from given input (u can use same number more than 1ce too)
	std::vector<int> data = { 20 };
	const int sum = 99;
	std::bitset<sum+1> result;
	result[0] = true;
	for (int n : data) {
		int t = n;
		while (t < sum) {
			result |= result << n;
			t += n;
		}
	}
	if (result[sum]) {
		std::cout << "\nSum found";
	} else {
		std::cout << "\nSum not available";
	}
	std::cout << result;

	std::cout << "\nTriangle count";
	int numvert;
	//std::cin >> numvert;
	const int vertices = 6;
	std::vector<std::vector<int>> input = { {2,4,5}, {1, 3, 4, 6}, {2}, {1, 2, 5, 6}, {1, 4, 6}, {2, 4, 5}};
	std::vector<std::bitset<vertices>> bits(vertices, std::bitset<vertices>{});

	for (int i = 0; i < input.size(); i++) {
		for (int val : input[i]) {
			bits[i][val - 1] = true;
		}
	}
	int triangles = 0;
	for (int i = 0; i < input.size(); i++) {
		for (int j = i + 1; j < input.size(); j++) {
			auto temp = bits[i] & bits[j];
			if (temp.count() > 0 && bits[i][j]) {
				triangles += temp.count();
			}
		}
	}

	std::cout << "\n Num of triangles " << triangles / 3;

	std::bitset<100> a("100");
	std::cout << std::endl << a.to_ulong();
}
