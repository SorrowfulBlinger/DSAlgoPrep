#pragma once
#include <vector>

using namespace std;

class Rivers
{

private:
	bool inBounds(vector<vector<int>>& matrix, int i, int j);
	void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited,
		int i, int j, int maxRow, int maxColumn, int& size);
	vector<int> riverSizes(vector<vector<int>> matrix);

public:
	Rivers();
	~Rivers();
	void execute();
};

