#pragma once
#include <map>
#include <string>


class Param {
public:
	const static int Error = -1;

	void Set(std::string key, int val);
	int Get(std::string key);

private:
	std::map<std::string, int> _map;
};