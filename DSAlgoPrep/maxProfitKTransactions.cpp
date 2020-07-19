#include "pch.h"
#include "maxProfitKTransactions.h"
#include <iostream>
#include <climits>

using namespace std;


maxProfitKTransactions::maxProfitKTransactions()
{
}


maxProfitKTransactions::~maxProfitKTransactions()
{
}


void maxProfitKTransactions::execute() {
	std::cout << "\n\n*************************** Max Profit: " << maxProfitWithKTransactions(vector<int>{ 5, 11, 3 , 50, 60 , 90 }, 2);
	//std::cout << "\n\n*************************** Max Profit: " << maxProfitWithKTransactions(vector<int>{1, 1, 1, 2, 100, 11, 1 }, 2);
}

int maxProfitKTransactions::maxProfitWithKTransactions(vector<int> prices, int tcount) {
	if (prices.size() <= 0) {
		return 0;
	}
	const unsigned int sz = prices.size();
	const unsigned int dval = 0;
	std:vector<std::pair<int, int>> trades;

	vector<vector<int>> result{ (const unsigned int)tcount + 1, vector<int>(sz, dval) };
	for (int i = 1; i <= tcount; i++) {
		int maxSoFar = INT_MIN;
		int buyRate = 0;
		for (int j = 1; j < prices.size(); j++) {
			int l1 = result[i][j - 1];
			auto maxFn = [](int a, int b) {
				return a > b ? a : b;
			};
			bool soldToday = false;
			std::pair<int, int> trade(0, 0);
			if (result[i - 1][j - 1] - prices[j - 1] > maxSoFar) {
				maxSoFar = result[i - 1][j - 1] - prices[j - 1];
				buyRate = prices[j - 1];
			}
			if (maxSoFar + prices[j] > l1) {
				result[i][j] = maxSoFar + prices[j];
				soldToday = true;
			}
			else {
				result[i][j] = l1;
			}
			if (i == tcount && soldToday) {
				trades.push_back(std::pair<int, int>(buyRate, prices[j]));
			}
		}
	}

	for (int i = 0; i <= tcount; i++) {
		for (int j = 0; j < prices.size(); j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << endl;
	}
	std::cout << "Trades take\n";

	int lastBuy = -1;
	for (std::vector<std::pair<int, int>>::reverse_iterator iter = trades.rbegin();
		iter != trades.rend(); ++iter) {
		if (lastBuy != -1 && lastBuy == iter->first) {
			continue;
		}
		std::cout << "Buy : " << iter->first << " Sold : " << iter->second << endl;
		lastBuy = iter->first;
	}

	return result[tcount][prices.size() - 1];
}

