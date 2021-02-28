#pragma once
#include <vector>
#include <memory>
#include"Player.h"

class BulletBase;

class BulletManager {
private:
	std::vector<std::shared_ptr<BulletBase>> bullets;

public:
	void Add(std::shared_ptr<BulletBase> b);
	void Update();
	void Draw();

	void Erase();

	bool Collision(Object& obj);
	int GetSize();
};