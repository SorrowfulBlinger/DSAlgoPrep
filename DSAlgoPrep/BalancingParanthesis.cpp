#include "pch.h"
#include "BalancingParanthesis.h"
#include <map>
#include <stack>
#include <iostream>

BalancingParanthesis::BalancingParanthesis()
{
}


BalancingParanthesis::~BalancingParanthesis()
{
}

void BalancingParanthesis::execute() {
	std::cout << "\n\n******************* Paranthesis balance - {{}}[]) - " << (isValid("{{}}[])") == true ? " balanced" : " not balanced");
	std::cout << "\n******************* Paranthesis balance - ({{}}[]) - " << (isValid("({{}}[])") == true ? " balanced" : " not balanced");
}

// Avoiding map made this fast
bool BalancingParanthesis::isValid(std::string s) {
	std::stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{')) { st.push(s[i]); }
		else {
			if (st.empty()) { return false; }
			if ((s[i] == ')') && (st.top() != '(')) { return false; }
			if ((s[i] == '}') && (st.top() != '{')) { return false; }
			if ((s[i] == ']') && (st.top() != '[')) { return false; }
			st.pop();
		}

	}
	return st.empty();
}

bool BalancingParanthesis::isValidSlow(std::string s) {
	std::map<char, char> lookup{
		{'(', ')'},
		{'{', '}'},
		{'[', ']'}
	};

	std::stack<char> jar;
	for (char c : s) {
		if (lookup.find(c) != lookup.end()) {
			jar.push(c);
		}
		else {
			if (jar.size() < 1) {
				return false;
			}
			char reverse = jar.top();
			jar.pop();
			if (lookup.find(reverse) != lookup.end()) {
				if (lookup[reverse] != c) {
					return false;
				}
			}
		}
	}
	return jar.size() == 0;
}
