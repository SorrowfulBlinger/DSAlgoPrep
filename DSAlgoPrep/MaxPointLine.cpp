#include "pch.h"
#include "MaxPointLine.h"


MaxPointLine::MaxPointLine()
{
}


MaxPointLine::~MaxPointLine()
{
}

long double MaxPointLine::findSlope(std::vector<int>& a, std::vector<int>& b) {
	if (a[0] == b[0]) {
		return std::numeric_limits<long double>::max();
	}
	else if (a[1] == b[1]) {
		return 0;
	}
	else {
		return (long double)(b[1] - a[1]) / (b[0] - a[0]);
	}
}


void MaxPointLine::execute() {
	std::vector<std::vector<int>> val{ {1, 1}, { 3, 2 }, { 5, 3 }, { 4, 1 }, { 2, 3 }, { 1, 4 } };
	std::vector<std::vector<int>> val1{ {1, 1}, { 2,1 }, { 2,2 }, { 1,4 }, { 3,3 } };
	std::cout << "\n\n******************  Max point : " << maxPoints(val1);
}

int MaxPointLine::maxPoints(std::vector<std::vector<int>>& points) {
	if (points.size() <= 2) {
		return points.size();
	}

	int max = 0;
	for (int i = 0; i < points.size(); i++) {
		std::map<long double, int> result;
		int same = 0;
		int localmax = 0;
		for (int j = i + 1; j < points.size(); j++) {
			if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
				same++;
				continue;
			}
			long double slope = findSlope(points[i], points[j]);
			if (result.find(slope) != result.end()) {
				result.find(slope)->second = result.find(slope)->second + 1;
			}
			else {
				result.insert(std::make_pair(slope, 2));
			}
			localmax = std::max(result.find(slope)->second, localmax);
		}
		// If all inputs same coordinates
		if (result.size() == 0) {
			same++;
		}
		max = std::max(max, localmax + same);
	}
	return max;
}


int MaxPointLine::maxPointsForReference(std::vector<std::vector<int>>& points) {

	struct pointComparator {
		bool operator()(const std::vector<int> &a, const std::vector<int> &b) {
			return a[0] < b[0] && a[1] < b[1];
		}
	};

	if (points.size() <= 2) {
		return points.size();
	}

	std::map<double, std::set<std::vector<int>, pointComparator>> result;
	for (int i = 0; i < points.size(); i++) {
		for (int j = i + 1; j < points.size(); j++) {
			double slope = findSlope(points[i], points[j]);
			if (result.find(slope) != result.end()) {
				result.find(slope)->second.insert(points[i]);
				result.find(slope)->second.insert(points[j]);
			}
			else {
				std::set<std::vector<int>, pointComparator> value;
				value.insert(points[i]);
				value.insert(points[j]);
				result.insert(std::make_pair(slope, value));
			}
		}
	}
	std::for_each(result.begin(), result.end(), [](const std::pair<double, std::set<std::vector<int>, pointComparator>>& data) {
		std::cout << data.first << "\n";
	});

	auto it = std::max_element(result.begin(), result.end());
	std::cout << "Slope is " << it->first << " count : " << it->second.size();

	return it->second.size();
}