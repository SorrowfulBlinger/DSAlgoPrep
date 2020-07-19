#pragma once
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <climits>

class StableMatching {

public:
	std::set<std::pair<std::string, std::string>> getMatching(
		std::map<std::string, std::vector<std::string>> men,
		std::map<std::string, std::vector<std::string>> women) {
		std::set<std::pair<std::string, std::string>> match;

		std::unordered_map<std::string, std::pair<std::string, int>> menCurrMatch;
		std::unordered_map<std::string, std::pair<std::string, int>> womenCurrMatch;

		std::unordered_map<std::string, std::map<std::string, int>> womenMatchReverseLookup;
		std::set<std::string> matchedMen;

		while (1) {
			bool change = false;
			for (auto& curr : men) {
				if (matchedMen.find(curr.first) != matchedMen.end()) {
					// Dont bother matched men
					continue;
				}
				std::string currMan = curr.first;
				std::string currWomen("");
				std::string nextWomen("");
				int startWomenIndex = 0;
				if (menCurrMatch.find(currMan) != menCurrMatch.end()) {
					startWomenIndex = menCurrMatch[currMan].second + 1;
				}
				for (int i = startWomenIndex; i < men[currMan].size(); i++) {
					currWomen = men[currMan][i];
					std::cout << "Checking" << currMan << "-" << currWomen << std::endl;

					// Check if women ready to match
					if (womenMatchReverseLookup.find(currWomen) == womenMatchReverseLookup.end()) {
						std::map<std::string, int> temp;
						for (int i = 0; i < women[currWomen].size(); i++) {
							temp[women[currWomen][i]] = i;
						}
						womenMatchReverseLookup[currWomen] = std::move(temp);
					}

					if (womenMatchReverseLookup[currWomen].find(currMan) != womenMatchReverseLookup[currWomen].end()) {
						int prevManPriority = std::numeric_limits<int>::max();
						int currManPriority = womenMatchReverseLookup[currWomen][currMan];
						std::string prevMan;

						if (womenCurrMatch.find(currWomen) != womenCurrMatch.end()) {
							prevManPriority = womenCurrMatch[currWomen].second;
							prevMan = womenCurrMatch[currWomen].first;
						}
						std::cout << "prevman-(" << prevMan << "," << prevManPriority << "), currman-(" << currMan << "," << currManPriority << ")" << endl;
						if (currManPriority < prevManPriority) {

							// Match possible
							menCurrMatch[currMan] = { currWomen , i };
							womenCurrMatch[currWomen] = { currMan, currManPriority };
							match.insert({ currMan, currWomen });
							matchedMen.insert(currMan);
							matchedMen.erase(prevMan);
							match.erase({ prevMan, currWomen });
							change = true;
							break;
						}
					}
				}
			}
			if (!change) {
				return match;
			}
		}
		return match;
	}

};