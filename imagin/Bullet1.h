#pragma once
#include"BulletBase.h"

class Bullet1 :public BulletBase {
public:
	Bullet1(Vec2d pos);
	Bullet1(Vec2d pos,BulletManager *bm);

	void Update();
	void Draw();
};