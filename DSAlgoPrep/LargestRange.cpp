#include "pch.h"
#include "LargestRange.h"
#include <vector>
#include <iostream>
#include <map>

using namespace std;

LargestRange::LargestRange()
{
}

LargestRange::~LargestRange()
{
}

void LargestRange::execute() {
	auto result = lRange(vector<int>{ 1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6 });
	cout << "\n\n*************************** Result : ";
	for (int i : result) {
		cout << i << ", ";
	}
}

vector<int> LargestRange::lRange(vector<int> array) {
	vector<int> answer;
	multimap<int, bool> result;
	for (int i : array) {
		result.insert(pair<int, bool>(i, true));
	}

	int left, right, max = 0, mright = 0, mleft = 0;
	for (int i : array) {
		if (result.find(i)->second) {
			left = i;
			right = i;
		}
		else {
			continue;
		}

		auto lbound = result.lower_bound(i);
		auto rbound = result.upper_bound(i);
		int occ = 0;
		while (lbound != rbound) {
			lbound++;
			occ++;
		}

		result.emplace(std::pair<int, bool>(i, false));
		while (result.find(left - 1) != result.end() && result.find(left - 1)->second) {
			left--;
			result.emplace(std::pair<int, bool>(left, false));
		}
		while (result.find(right + 1) != result.end() && result.find(right + 1)->second) {
			right++;
			result.emplace(std::pair<int, bool>(right, false));
		}
		if (right - left + occ > max) {
			max = right - left + occ;
			mright = right;
			mleft = left;
		}
	}

	answer.push_back(mleft);
	answer.push_back(mright);
	return answer;
}
