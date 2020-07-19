
#pragma once
#include <map>
#include <set>
#include <vector>

class MaximalMatchingBipartite {

public:
	std::set<std::pair<std::string, std::string>> matchings;

	bool dfs(std::string source, std::set<std::pair<std::string, std::string>>& path, std::map<std::string, std::set<std::string>>& adjList, std::set<std::string>& visited) {
		
		if (source == "$target$") {
			return true;
		}
		bool found = false;
		for (auto& v : adjList[source]) {
			if (visited.count(v) == 0) {
				visited.insert(v);
				found = dfs(v, path, adjList, visited);
				if (found) {
					//std::cout << "insert -" << source << ", " << v << endl;
					path.insert({ source, v });
					break;
				}
			}
		}
		return found;
	}

	std::set<std::pair<std::string, std::string>> getPath(std::set<std::pair<std::string, std::string>>& path,
		std::map<std::string, std::set<std::string>>& adjList) {
		std::set<std::string> visited;
		visited.insert("$source$");
		dfs( "$source$", path, adjList, visited);
		return path;
	}

	std::set<std::pair<std::string, std::string>> getMaxPairs(std::map<std::string, std::set<std::string>>& adjList) {
		
		std::set<std::pair<std::string, std::string>> path;
		std::set<std::string> sAdj;
		std::set<std::string> tadj;
		std::map<std::string, std::set<std::string>>::iterator it = adjList.begin();

		while(it != adjList.end())
		{
			auto& data = *it;
			if (data.first[0] == '1') {
				sAdj.insert(data.first);
				(data.second).insert("$source$");
			}
			else if (data.first[0] == '2') {
				tadj.insert(data.first);
				(data.second).insert("$target$");
			}
			else {
				throw new std::runtime_error("Not possible- Bad input");
			}
			it++;
		}

		// Create auxilary graph and add temp Source & Target vertices
		adjList.insert({ "$source$", std::move(sAdj)});
		adjList.insert({ "$target$", std::move(tadj)});

		// Matched Edges
		while (1) {
			path.clear();
			getPath(path, adjList);
			if (path.empty()) {
				break;
			}
			// Update the graph by XORing Matched set and Current graph , and retry to see if any path exist
			for (const std::pair<std::string, std::string>&p : path) {
				adjList[p.second].insert(p.first);
				adjList[p.first].erase(p.second);

				matchings.erase({p.second, p.first});
				matchings.insert({p.first, p.second});
			}
		}

		// Build Matches
		return matchings;
	}
};