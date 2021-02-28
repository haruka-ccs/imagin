#pragma once
#include "EnemyBase.h"
#include <vector>
#include <memory>

class EnemyManager {
private:
	std::vector<std::shared_ptr<EnemyBase>> enemies;
public:
	EnemyManager() {};
	void Update();
	void Draw();

	void Add(std::shared_ptr<EnemyBase> e);
};