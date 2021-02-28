#include "Param.h"

void Param::Set(std::string key, int val) {
	_map[key] =val;
}

int Param::Get(std::string key) {
	auto it = _map.find(key);
	if (_map.end() == it) {
		return Error;
	}
	else {
		return it->second;
	}
}