#pragma once
#include"EnemyBase.h"

class Enemy1 :public EnemyBase {
private:
	Vec2d center;
public:
	Enemy1(Vec2d pos,BulletManager* bm);
	void Update();
	void Draw();
};