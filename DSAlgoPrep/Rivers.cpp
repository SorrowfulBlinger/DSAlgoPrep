#include "pch.h"
#include "Rivers.h"
#include <vector>
#include <iostream>

using namespace std;


Rivers::Rivers()
{}


bool Rivers::inBounds(vector<vector<int>>& matrix, int i, int j) {
	if (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size()) {
		return true;
	}
	return false;
}

void Rivers::execute() {
	vector<vector<int>> data = {
			{1, 1, 0},
			{1, 0, 1},
			{1, 1, 1},
			{1, 1, 0},
			{1, 0, 1},
			{0, 1, 0},
			{1, 0, 0},
			{1, 0, 0},
			{0, 0, 0},
			{1, 0, 0},
			{1, 0, 1},
			{1, 1, 1}
	};
	
	std::cout << "\n\n*************************** Result : ";
	for(int val : riverSizes(data)) {
		std::cout << val << ", ";
	}
}

void Rivers::dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited,
	int i, int j, int maxRow, int maxColumn, int& size) {
	if (!inBounds(matrix, i, j) || matrix[i][j] == 0 || visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	size++;
	dfs(matrix, visited, i + 1, j, maxRow, maxColumn, size);
	dfs(matrix, visited, i - 1, j, maxRow, maxColumn, size);
	dfs(matrix, visited, i, j + 1, maxRow, maxColumn, size);
	dfs(matrix, visited, i, j - 1, maxRow, maxColumn, size);
}

vector<int> Rivers::riverSizes(vector<vector<int>> matrix) {
	vector<vector<bool>> visited;
	vector<int> results;
	for (int i = 0; i < matrix.size(); i++) {
		vector<bool> row;
		for (int j = 0; j < matrix[i].size(); j++) {
			row.push_back(false);
		}
		visited.push_back(row);
	}


	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			int val = 0;
			dfs(matrix, visited, i, j, (int)visited.size(), (int)visited[i].size(), val);
			if (val > 0) {
				results.push_back(val);
			}
		}
	}

	return results;
}


Rivers::~Rivers()
{
}
