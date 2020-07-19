#pragma once

#include <unordered_set>
#include <set>
#include <limits>
#include <algorithm>
#include <iostream>

using namespace std;
typedef std::pair<std::string, int> Node;

struct NodeComparator {
	bool operator()(const Node&a, const Node& b) const {
		return a.first < b.first;
	}
};

class WordLadderDFS
{
public:
	WordLadderDFS() {

	}
	
	~WordLadderDFS() {

	}

	void execute() {
		std::cout << "\n\n************* Word Ladder - DFS " << 
			ladderLength("cet", "ism", 
				std::vector<string>{ "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob"});
		
		std::cout << "\n\n************* Word Ladder - BFS " <<
			ladderLengthBFSOptimised("cet", "ism",
				std::vector<string>{ "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam", "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin", "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob"});

		/*
		std::cout << "\n\n************* Word Ladder - DFS " << 
			ladderLength("abc", "bec",
			std::vector<string>{"abc", "abx", "aec", "bec", "bed", "aed", "aex", "amx", "abd"});

		
		std::for_each(bfsresult.begin(), bfsresult.end(), [](auto data) {
			std::cout << "----------------- \n\n";
				std::for_each(data.begin(), data.end(), [](auto idata) {
					std::cout << idata << "-";
			});
		}); */

		std::cout << "\n\n" << bfsanswer["ism"];

		/*
		std::vector<std::unordered_set<std::string>>::const_reverse_iterator rit = bfsresult.crbegin();

		while (rit != bfsresult.crend()) {
			if (rit->size() == 1) {
				std::cout << *rit->begin() << "->";
			} else {
				
			}
			rit++;
		} */
		
	
	}

	std::set<std::string> dictionary;
	std::set<Node, NodeComparator> visitedNodes;
	std::map<std::string, std::string> traversal;
	std::vector<std::unordered_set<std::string>> bfsresult;
	std::map<std::string, std::string> bfsanswer;
	std::vector<std::string> path;

	int ladderLengthBFSOptimised(string beginWord, string endWord, vector<string> wordList) {
		std::set<string> dictionary(wordList.begin(), wordList.end());
		std::unordered_set<std::string> headSet{ beginWord };
		std::unordered_set<std::string> tailSet{ endWord };
		std::unordered_set<std::string>* head = &headSet;
		std::unordered_set<std::string>* tail = &tailSet;

		if (dictionary.count(endWord) < 1) {
			return 0;
		}
		dictionary.erase(beginWord);
		dictionary.erase(endWord);
		bfsresult.push_back(headSet);
		bfsanswer[beginWord] = beginWord;
		int ladder = 2;
		while (1) {
			if (head->empty() && tail->empty()) {
				return 0;
			}
			if (!head->empty() && head->size() <= tail->size()) {
			}
			else {
				//std::swap(head, tail);
			}

			std::unordered_set<std::string> temp;
			for (std::string s : *head) {

				for (int i = 0; i < s.length(); i++) {
					for (int j = 0; j < 26; j++) {
						string ts = s;
						ts[i] = 'a' + j;
						if (dictionary.find(ts) != dictionary.end()) {
							dictionary.erase(ts);
							temp.insert(ts);
							bfsanswer[ts] = bfsanswer[s] + "->" + ts;
						}
						if (tail->find(ts) != tail->end()) {
							bfsresult.push_back(tailSet);
							bfsanswer[ts] = bfsanswer[s] + "->" + ts;
							return ladder;
						}
					}
				}
			}
			if (temp.size() > 0) {
				ladder++;
			}
			else {
				return 0;
			}
			bfsresult.push_back(temp);
			std::swap(temp, *head);
			//std::cout << "temp : " << temp.size() << " - head : " << head->size() << " - tail : " << tail->size()<< "\n";
		}
		return 0;
	}

	int ladderLength(string beginWord, string endWord, vector<string> wordList) {
		this->dictionary = std::set<std::string>(wordList.begin(), wordList.end());
		Node root(beginWord, std::numeric_limits<int>::max());
		int distance = dfs(root, endWord);
		std::cout << "\n\n";
		while (1) {
			std::cout << beginWord << "->";
			beginWord = traversal[beginWord];
			if (beginWord == endWord || beginWord.empty()) {
				std::cout << beginWord;
				break;
			}
		}
		if (distance == std::numeric_limits<int>::max()) {
			return 0;
		}
		else {
			return distance;
		}
	}

	int dfs(Node currentNode, std::string endWord) {
		
		if (this->visitedNodes.count(currentNode)) {
			//return  std::numeric_limits<int>::max();
			return visitedNodes.find(currentNode)->second;
		} else if (currentNode.first == endWord) {
			std::cout << "\n\nFinal - \n";
			std::for_each(path.begin(), path.end(), [](auto& data) {
				std::cout << data;
			});
			//this->visitedNodes.insert(Node(endWord, 1));
			return 1;
		}
		int minDistance = std::numeric_limits<int>::max();
		this->visitedNodes.insert(Node(currentNode.first, minDistance));
		path.push_back(currentNode.first);
		std::string minString;
		//std::cout << currentNode.first << "\n";
		for (int i = 0 ; i < currentNode.first.size(); i++) {
			std::string permutedString = currentNode.first;
			for (int j = 0; j<26; j++) {
				permutedString[i] = 'a' + j;
				if (permutedString.compare(currentNode.first) != 0 && dictionary.count(permutedString)) {
					//std::cout << permutedString << " @ ";
					int bestDistance = dfs(Node(permutedString, std::numeric_limits<int>::max()), endWord);
					bestDistance = (bestDistance == std::numeric_limits<int>::max()) ? (std::numeric_limits<int>::max()) : (bestDistance + 1);
					if (bestDistance < minDistance) {
						minDistance = bestDistance;
						minString = permutedString;
					}
				}
			}
		}

		// Update the mindistance from currentNode
		this->visitedNodes.erase(Node(currentNode.first, minDistance));
		this->visitedNodes.insert(Node(currentNode.first, minDistance));
		path.pop_back();
		if (minDistance < std::numeric_limits<int>::max()) {
			traversal[currentNode.first] = minString;
		}

		return minDistance;
	}
};
