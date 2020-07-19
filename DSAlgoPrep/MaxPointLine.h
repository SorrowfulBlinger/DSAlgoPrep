#pragma once

#include <set>
#include <limits>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

class MaxPointLine {
public:
	
	MaxPointLine();
	~MaxPointLine();

	long double findSlope(std::vector<int>& a, std::vector<int>& b);
	void execute();
	int maxPoints(std::vector<std::vector<int>>& points);
	int maxPointsForReference(std::vector<std::vector<int>>& points);
};
