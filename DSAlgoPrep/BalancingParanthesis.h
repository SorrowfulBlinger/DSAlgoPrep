#pragma once
#include <string>
class BalancingParanthesis
{
public:
	BalancingParanthesis();
	~BalancingParanthesis();
	void execute();
	bool isValidSlow(std::string s);
	bool isValid(std::string s);
};

